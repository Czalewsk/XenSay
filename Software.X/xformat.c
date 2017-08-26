#include <xc.h>
#include "xformat.h"
#include "sdcard.h"
#include "smartlibc.h"

static u8 musicName[XFORMAT_MUSIC_MAXNAME];
static u8 musicData[XFORMAT_MUSIC_MAXSIZE];
static u16 musicSize;
static u16 musicIndex;
static u16 musicSector;

static u8 xformat_error(u8 *error)
{
    lcd_write_line(error, 0);
    return (0);
}

u8 xformat_isFormatted()
{
    u8 *block;
    u8 i;
    
    block = sdcard_read(0); // Read xformat header
    
    // Check header structure
    for (i = 0; i < 8; ++i)
    {
        if (block[i] != 0x42)
            return (0);
    }
    for (i = 0; i < 4; ++i)
    {
        if (block[i + 8] != 0x0)
            return (0);
    }
    for (i = 0; i < 4; ++i)
    {
        if (block[i + 12] != 0x42)
            return (0);
    }
    
    // Check version
    if (block[16] != XFORMAT_VERSION)
        return (0);
    
    return (1);
}

u8 xformat_start()
{
    musicIndex = 0;
    
    if (!sdcard_start())
        return (0);
    if (!xformat_isFormatted())
        return (xformat_error(" UNKNOW FORMAT  "));
    
    return (1);
}

u8 xformat_getMusicCount()
{
    u8 *block;
    u8 count;
    u8 entry;
    
    count = 0;
    
    entry = 0;
    while (entry < XFORMAT_FAT_MAXENTRY)
    {
        if (!(entry % XFORMAT_FAT_ENTRYINSECTOR)) // Read sector of entry
        {
            if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
                return (0);
        }
        
        if (GET_FATENTRYSIZE(block, entry))
            ++count;
        ++entry;
    }
    return (count);
}

u8 *xformat_firstMusic()
{
    u8 *block;
    u8 entry;
    
    for (entry = 0; entry < XFORMAT_FAT_MAXENTRY; ++entry)
    {
        if (!(entry % XFORMAT_FAT_ENTRYINSECTOR)) // Read sector of entry
        {
            if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
                return (0);
        }
        
        if (GET_FATENTRYSIZE(block, entry))
        {
            musicIndex = entry;
            musicSector = GET_FATENTRYSECTOR(block, entry);
            musicSize = GET_FATENTRYSIZE(block, entry);
            
            return ((u8 *)slc_memcpy(musicName, block + (entry * XFORMAT_FAT_ENTRYSIZE) + 4,
                    XFORMAT_MUSIC_MAXNAME));
        }
    }
    return (0);
}

u8 *xformat_nextMusic()
{
    u8 *block;
    u8 entry;
    u32 intStatus;

    // disable interrupts
    intStatus = INTDisableInterrupts();

    entry = musicIndex + 1;
    // Read first block
    if (entry % XFORMAT_FAT_ENTRYINSECTOR && entry < XFORMAT_FAT_MAXENTRY)
    {
        if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
            return (0);
    }
    
    for (; entry < XFORMAT_FAT_MAXENTRY; ++entry)
    {
        if (!(entry % XFORMAT_FAT_ENTRYINSECTOR)) // Read sector of entry
        {
            if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
                return (0);
        }
        
        if (GET_FATENTRYSIZE(block, entry))
        {
            musicIndex = entry;
            musicSector = GET_FATENTRYSECTOR(block, entry);
            musicSize = GET_FATENTRYSIZE(block, entry);
            INTRestoreInterrupts(intStatus);
            return ((u8 *)slc_memcpy(musicName, block + (entry * XFORMAT_FAT_ENTRYSIZE) + 4,
                    XFORMAT_MUSIC_MAXNAME));
        }
    }
    INTRestoreInterrupts(intStatus);
    return (musicName);
}

u8 *xformat_prevMusic()
{
    u8 *block;
    u8 entry;
    
    if (!musicIndex)
        return (musicName);
    
    entry = musicIndex - 1;
    
    // Read first block
    if (entry % XFORMAT_FAT_ENTRYINSECTOR && entry < XFORMAT_FAT_MAXENTRY)
    {
        if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
            return (0);
    }
    
    for (; entry < XFORMAT_FAT_MAXENTRY; --entry)
    {
        if (!(entry % XFORMAT_FAT_ENTRYINSECTOR)) // Read sector of entry
        {
            if (!(block = sdcard_read((entry / XFORMAT_FAT_ENTRYINSECTOR) + 1)))
                return (0);
        }
        
        if (GET_FATENTRYSIZE(block, entry))
        {
            musicIndex = entry;
            musicSector = GET_FATENTRYSECTOR(block, entry);
            musicSize = GET_FATENTRYSIZE(block, entry);
            
            return ((u8 *)slc_memcpy(musicName, block + (entry * XFORMAT_FAT_ENTRYSIZE) + 4,
                    XFORMAT_MUSIC_MAXNAME));
        }
    }
    return (musicName);
}

u8 *xformat_loadMusic()
{
    u8 *block;
    u16 i;
    
    for (i = 0; i < musicSize; ++i)
    {
        if (!(i % 512))
        {
            if (!(block = sdcard_read(musicSector)))
                return (0);
        }
        slc_memcpy(musicData + i, block + (i % 512), 1);
    }
    
    return (musicData);
}

u16 xformat_sizeMusic()
{
    return (musicSize);
}

u8 *xformat_nameMusic()
{
    return (musicName);
}

u8 *xformat_dataMusic()
{
    return (musicData);
}