#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "video.h"

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

    //this should put ASCII key value into ah and BIOS value into al
    regs.h.ah = 0x00;
    int86(0x16, &regs, &regs);

    result = regs.h.ah;
    bios_scan = regs.h.al;
    return result;
}

int main()
{
    int value = 0;
    int key = 0;
    init_graphics();
    while (key != 1)
    {
        unsigned short offset;
        int x = 0;
        for (x = 0; x < 500; x++)
        {
            offset = 320 + x;
            VGA[offset] = COLOR_RED;
        }
        key = get_keyboard_key();
    }

    quit_graphics();
    printf("Goodbye world!\n");
    return 0;
}
