#ifndef VIDEO_H
#define VIDEO_H

#include <dos.h>
typedef unsigned char byte;

// VGA memory
byte far *VGA = (byte far *)0xA0000000L;

void plot_pixel(int x, int y, byte color);

#endif