#include <stdlib.h>
#include <string.h>
#include "../include/voxlib.h"

VoxWindow *CreateWindow(int w, int h, const char *title, long perm)
{
    VoxWindow *win = calloc(1, sizeof(VoxWindow));

    if (!win)
        return NULL;

    win->display = XOpenDisplay(NULL);

    if (!win->display)
    {
        free(win);
        return NULL;
    }

    win->screen = DefaultScreen(win->display);

    win->width = w;
    win->height = h;
    win->running = 1;

    win->window = XCreateSimpleWindow(
        win->display,
        RootWindow(win->display, win->screen),
        0,
        0,
        w,
        h,
        1,
        BlackPixel(win->display, win->screen),
        WhitePixel(win->display, win->screen));

    XStoreName(win->display, win->window, title);

    XSelectInput(win->display, win->window, perm);

    win->wm_delete = XInternAtom(
        win->display,
        "WM_DELETE_WINDOW",
        False);

    XSetWMProtocols(
        win->display,
        win->window,
        &win->wm_delete,
        1);

    XMapWindow(win->display, win->window);

    XFlush(win->display);

    win->gc = DefaultGC(win->display, win->screen);

    return win;
}

void DestroyWindow(VoxWindow *win)
{
    if (!win)
        return;

    XDestroyWindow(win->display, win->window);
    XCloseDisplay(win->display);

    free(win);
}