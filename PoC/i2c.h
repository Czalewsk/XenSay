/* 
 * File:   i2c.h
 * Author: bocal
 *
 * Created on June 22, 2017, 5:00 PM
 */

#ifndef I2C_H
#define	I2C_H

// I2C
# define ADDR (0x7C)  // I2C screen Addr

typedef enum {
    START,
    ADDRESS,
    SEND_DATA,
    STOP,
    END,
} I2C_STATES;

typedef struct  t_I2Cdata //I2C data struct with buf
{
    char        data[100];
    u8          len;
    u8          index;
    I2C_STATES  state;
}               s_I2Cdata;

typedef enum  {
    FREE_I2C,
    BUSY_I2C
} I2C_BUSY_FLAG;

// State enum
typedef enum {
    CONFIG,
    SIMON,
    LEARN,
    FREE_PLAY
} G_STATES;

#endif	/* I2C_H */

