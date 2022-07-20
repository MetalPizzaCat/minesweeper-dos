
void plot_pixel(int x, int y, byte color)
{
    offset = 320 * y + x;
    VGA[offset] = color;
}