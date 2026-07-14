#include "../include/voxlib.h"
#include <stdlib.h>
#include "string.h"

void DrawPixel(VoxWindow *win, int x, int y)
{
    XDrawPoint(
        win->display,
        win->window,
        win->gc,
        x,
        y
    );
}

void DrawLine(VoxWindow *win, int x1, int y1, int x2, int y2) {
    XDrawLine(win->display, win->window, win->gc, x1, y1, x2, y2);
};


void DrawRectangle(VoxWindow *win, int x, int y, int w, int h, int Fill)
{
    if (Fill) {
        XFillRectangle(
        win->display,
        win->window,
        win->gc,
        x,
        y,
        w,
        h
    );
    } else {
        XDrawRectangle(
        win->display,
        win->window,
        win->gc,
        x,
        y,
        w,
        h
    );
    }
}

void DrawCircle(VoxWindow *win, int x, int y, int w, int h, unsigned angle1, unsigned int angle2, int Fill)
{
    if (Fill) {
        XFillArc(
        win->display,
        win->window,
        win->gc,
        x,
        y,
        w,
        h,
        angle1,
        angle2
    );
    } else {
        XDrawArc(
        win->display,
        win->window,
        win->gc,
        x,
        y,
        w,
        h,
        angle1,
        angle2
    );
    }
}

void DrawText(VoxWindow *win, int x, int y, const char *text) {
    XDrawString(win->display, win->window, win->gc, x, y, text, strlen(text));
}

void DrawClear(VoxWindow *win) {
    XClearWindow(win->display, win->window);
}

void DrawRefresh(VoxWindow *win)
{
    XFlush(win->display);
}


void DrawSync(VoxWindow *win)
{
    XSync(win->display, False);
}

VoxImage *DrawCreateImage(VoxWindow *win, unsigned char *pixels, int w, int h)
{
    VoxImage *img = malloc(sizeof(VoxImage));

    img->image = XCreateImage(
        win->display,
        DefaultVisual(win->display, win->screen),
        DefaultDepth(win->display, win->screen),
        ZPixmap,
        0,
        (char *)pixels,
        w,
        h,
        32,
        0
    );

    return img;
}

void DrawImage(
    VoxWindow *win,
    VoxImage *img,
    int x,
    int y
)
{
    XPutImage(
        win->display,
        win->window,
        win->gc,
        img->image,
        0,
        0,
        x,
        y,
        img->image->width,
        img->image->height
    );
}

void DrawDestroyImage(VoxImage *image)
{
    if (image) {
        image->image->data = NULL;
        XDestroyImage(image->image);
    }
}

void DrawSetColor(VoxWindow *win, unsigned long color)
{
    XSetForeground(
        win->display,
        win->gc,
        color
    );
}