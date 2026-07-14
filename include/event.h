#ifndef EVENT_H
#define EVENT_H

#include <X11/Xlib.h>

typedef struct VoxWindow VoxWindow;

typedef void (*EventCallback)(VoxWindow *, XEvent *);

typedef struct
{
    EventCallback callbacks[LASTEvent];
} EventManager;

void CreateEvent(VoxWindow *win, int type, EventCallback cb);
void PollEvents(VoxWindow *win);

#endif