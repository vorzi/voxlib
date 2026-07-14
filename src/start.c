#include "../include/voxlib.h"

void start(VoxWindow *win)
{
    while (win->running)
    {
        PollEvents(win);
    }

    DestroyWindow(win);
}