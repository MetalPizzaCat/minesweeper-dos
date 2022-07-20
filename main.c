#include <stdio.h>
#include <stdlib.h>

//#include "colors.h"
//#include "video.h"

#define true 1
#define false 0

int main()
{
    // union REGS regs;
    // printf("Hello world!\n");

    // regs.h.ah = 0x00;          /* function 00h = mode set */
    // regs.h.al = 0x13;          /* 256-color */
    // int86(0x10, &regs, &regs); /* do it! */
    // while (true)
    // {
    //     unsigned short offset;
    //     int x = 0;
    //     for (x = 0; x < 500; x++)
    //     {
    //         offset = 320 + x;
    //         VGA[offset] = COLOR_WHITE;
    //     }
    // }

    // regs.h.ah = 0x00;
    // regs.h.al = 0x03; /* text mode is mode 3 */
    // int86(0x10, &regs, &regs);

    printf("Hello world!\n");
    return 0;
}
