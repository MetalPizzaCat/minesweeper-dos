#include "mouse.h"

struct Mouse
get_mouse_info(void)
{
    struct Mouse res;
    union REGS regs;
    regs.x.ax = 3;
    int86(0x33, &regs, &regs);
    res.x = regs.x.cx;
    res.y = regs.x.dx;
    res.buttons = regs.x.bx;
    return res;
}

unsigned char init_mouse(void)
{
    union REGS regs;
    regs.x.ax = 0;
    int86(0x33, &regs, &regs);
    return regs.x.ax;
}
