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
void MoveCursor(VoxWindow win, int x, int y);
VoxMousePosition GetMouse(VoxWindow win);
void ChangeCursor(VoxWindow win, unsigned int Arrow);
void HideCursor(VoxWindow win);
void ShowCursor(VoxWindow win);

#endif