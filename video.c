#include "video.h"
#include <string.h>
void plot_pixel(int x, int y, byte color)
{
    VGA[(y << 8) + (y << 6) + x] = color;
}

void plot_pixel_buffer(int x, int y, byte color)
{
    g_buffer[(y << 8) + (y << 6) + x] = color;
}

// applies code from buffer to vga
void render()
{
    memcpy(VGA, g_buffer, SCREEN_WIDTH * SCREEN_HEIGHT);
}

void clear()
{
    memset(g_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT);
}