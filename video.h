#ifndef VIDEO_H
#define VIDEO_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define COLOR_COUNT 256
#include <dos.h>
typedef unsigned char byte;

// VGA memory
byte far *VGA = (byte far *)0xA0000000L;
byte *g_buffer;

void plot_pixel(int x, int y, byte color);

void plot_pixel_buffer(int x, int y, byte color);

// applies code from buffer to vga
void render();

void clear();
#endif
