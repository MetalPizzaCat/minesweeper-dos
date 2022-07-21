#ifndef MOUSE_H
#define MOUSE_H
#include <dos.h>

// Send correct interrupt to enable mouse
// Returns 0 if no mouse found and 1 if found
// unsigned short init_mouse();

unsigned char init_mouse(void);

struct Mouse
{
    int x;
    int y;
    int buttons;
};

struct Mouse
get_mouse_info(void);
#endif
