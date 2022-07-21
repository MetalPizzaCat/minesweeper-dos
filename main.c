#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "video.h"
#include "mouse.h"
#include "bitmap.h"

#define true 1
#define false 0

union REGS regs;

// Sends interrupt to enable graphics mode
void init_graphics(void)
{

    regs.h.ah = 0x00;          /* function 00h = mode set */
    regs.h.al = 0x13;          /* 256-color */
    int86(0x10, &regs, &regs); /* do it! */
}

// Sends interrupt to enable text mode
void quit_graphics(void)
{
    regs.h.ah = 0x00;          /* function 00h = mode set */
    regs.h.al = 0x3;           /* text  */
    int86(0x10, &regs, &regs); /* do it! */
}

int get_keyboard_key(void)
{
    byte result = -1;
    byte bios_scan = 0;
    regs.h.ah = 0x01;
    int86(0x16, &regs, &regs);

    // this should put ASCII key value into ah and BIOS value into al
    regs.h.ah = 0x00;
    int86(0x16, &regs, &regs);

    result = regs.h.ah;
    bios_scan = regs.h.al;
    return result;
}

int main()
{
    struct Mouse mouse;
    Bitmap *face;
    int key = 0;
    face = read_bmp("face.bmp");

    printf("%i", face);

    // g_buffer = (byte *)calloc(320 * 200, sizeof(byte));

    init_graphics();

    while (key != 1)
    {
        int i = 0;

        for (i = 0; i < 100; i++)
        {
            plot_pixel(i, i, COLOR_DARK_GRAY);
        }

        draw_bitmap(face, 0, 0);
        key = get_keyboard_key();
    }
    printf("quitting\n");
    quit_graphics();
    printf("Goodbye world!\n");
    free_bmp(face);
    return 0;
}
