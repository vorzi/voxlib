#ifndef DRAW_H
#define DRAW_H

#include <X11/Xlib.h>

typedef struct VoxWindow VoxWindow;

typedef void (*EventCallback)(VoxWindow *, XEvent *);
struct VoxImage {
    XImage *image;
};
typedef struct VoxImage VoxImage;

void DrawClear(VoxWindow *win);
VoxImage *DrawCreateImage(VoxWindow *win, unsigned char *pixels, int w, int h);
void DrawImage(VoxWindow *win, VoxImage *image, int x, int y);
void DrawDestroyImage(VoxImage *image);
void DrawPixel(VoxWindow *win, int x, int y);
void DrawLine(VoxWindow *win, int x1, int y1, int x2, int y2);
void DrawRectangle(VoxWindow *win, int x, int y, int w, int h, int Fill);
void DrawCircle(VoxWindow *win, int x, int y, int w, int h, unsigned angle1, unsigned int angle2, int Fill);
void DrawText(VoxWindow *win, int x, int y, const char *text);
void DrawSetColor(VoxWindow *win, unsigned long color);
void DrawSync(VoxWindow *win);
void DrawRefresh(VoxWindow *win);

#endif