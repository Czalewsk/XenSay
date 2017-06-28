/* 
 * File:   smartlibc.c
 * Author: Tim
 *
 * Created on June 28, 2017, 9:31 AM
 */

#include "smartlibc.h"


void    *slc_memcpy(void *dst, const void *src, u32 n)
{
    u32 i;

    i = 0;
    while (i < n)
    {
        ((u8 *)dst)[i] = ((u8 *)src)[i];
        i++;
    }
    return (dst);
}