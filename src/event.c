#include "../include/voxlib.h"

void CreateEvent(VoxWindow *win, int type, EventCallback cb)
{
    if (type >= 0 && type < LASTEvent)
        win->events.callbacks[type] = cb;
}

void PollEvents(VoxWindow *win)
{
    XEvent event;

    XNextEvent(win->display, &event);

    if (event.type == ClientMessage)
    {
        if ((Atom)event.xclient.data.l[0] == win->wm_delete)
        {
            win->running = 0;
            return;
        }
    }

    EventCallback cb = win->events.callbacks[event.type];

    if (cb)
        cb(win, &event);
}