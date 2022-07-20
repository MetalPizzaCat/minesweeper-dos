#include "video.h"
void plot_pixel(int x, int y, byte color)
{
    VGA[(y<<8) + (y<<6) + x] = color;
}