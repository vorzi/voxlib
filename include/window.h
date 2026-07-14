#ifndef VOXLIBC_H
#define VOXLIBC_H

#include <X11/Xlib.h>
#include "event.h"

typedef struct VoxWindow
{
    Display *display;
    Window window;
    GC gc;

    int screen;
    int width;
    int height;

    int running;

    Atom wm_delete;

    EventManager events;

} VoxWindow;

VoxWindow *CreateWindow(int w, int h, const char *title, long perm);
void DestroyWindow(VoxWindow *win);

void start(VoxWindow *win);

#endif