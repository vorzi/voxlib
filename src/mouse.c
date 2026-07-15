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