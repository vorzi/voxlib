#include "../include/voxlib.h"

int IsMouseButtonDown(VoxWindow win, VoxMouseButton button)
{
    Window root, child;
    int rootX, rootY;
    int x, y;
    unsigned int mask;

    XQueryPointer(
        win.display,
        win.window,
        &root,
        &child,
        &rootX,
        &rootY,
        &x,
        &y,
        &mask
    );

    return (mask & button) != 0;
}

VoxMousePosition GetMouse(VoxWindow win)
{
    Window root, child;
    VoxMousePosition pos;
    unsigned int mask;

    XQueryPointer(
        win.display,
        win.window,
        &root,
        &child,
        &pos.rootX,
        &pos.rootY,
        &pos.x,
        &pos.y,
        &mask
    );

    return pos;
}

void MoveCursor(VoxWindow win, int x, int y)
{
    XWarpPointer(
        win.display,
        None,
        win.window,
        0,
        0,
        0,
        0,
        x,
        y
    );

    XFlush(win.display);
}

void HideCursor(VoxWindow win)
{
    Pixmap blank;
    XColor dummy;
    Cursor invisble;
    blank = XCreatePixmap(
        win.display,
        win.window,
        1,
        1,
        1
    );

    invisble = XCreatePixmapCursor(
        win.display,
        blank,
        blank,
        &dummy,
        &dummy,
        0,
        0
    );

    XDefineCursor(
        win.display,
        win.window,
        invisble
    );

    XFreePixmap(
        win.display,
        blank
    );

    XFlush(win.display);
}

void ShowCursor(VoxWindow win) 
{
    XUndefineCursor(win.display, win.window);
    XFlush(win.display);
}