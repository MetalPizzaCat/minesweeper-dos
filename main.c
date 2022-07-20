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
    _asm {
        /* function 00h = mode set */
        mov ah,0
        /* 256-color */
        mov al, 13h
        /* do it! */
        int 10h
    }
}

// Sends interrupt to enable text mode
void quit_graphics(void)
{
    _asm {
        /* function 00h = mode set */
        mov ah,0
        /* text mode */
        mov al, 3h
        /* do it! */
        int 10h
    }
}

int get_keyboard_key(void)
{
    byte result = -1;
    byte bios_scan = 0;
    _asm {
        mov ah, 1
        int 16h
        jz noKey
        mov ah,0
        int 16h
        mov result, ah
        mov bios_scan, al
        noKey:
    }
    return result;
}

int main()
{
    int value = 0;
    int key = 0;

    init_graphics();
    while (key != 1)
    {
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
    }
    quit_graphics();
    printf("Goodbye world!\n");
    return 0;
}
