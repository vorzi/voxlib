#ifndef MOUSE_H
#define MOUSE_H

typedef enum
{
    LeftClick,
    MiddleClick,
    RightClick,

    X1Button,
    X2Button
} VoxMouseButton;

typedef struct
{
    int x;
    int y;
    int rootX;
    int rootY;
} VoxMousePosition;

int IsMouseButtonDown(VoxWindow win, VoxMouseButton button);
VoxMousePosition GetMouse(VoxWindow win);

#endif