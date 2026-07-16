#include "voxlib.h"
#include <stdio.h>

int i = 0;

void onKey(VoxWindow *win, XEvent *event)
{
    VoxKey key = GetKey(event);

    puts("Tecla pressionada!");

    if (IsKeyDown(event, key))
    {
        printf("Tecla %d pressionada.\n", key);
    }

    if (key == KEY_Q) {
        puts("Tecla Q pressionada, saindo!");
        DestroyWindow(win);
    }

    if (key == KEY_M) {
        puts("Tecla M pressionada, movendo!");
        MoveCursor(*win, 100, 100);
    }

    if (key == KEY_P) {
        puts("Tecla P pressionada, Escondendo Cursor");
        HideCursor(*win);
    }

    if (key == KEY_O) {
        puts("Tecla P pressionada, Mostrando Cursor");
        ShowCursor(*win);
    }

    if (key == KEY_I) {
        puts("Tecla I pressionada, Mudando Cursor");

        if (i > 137) i=0;
        ChangeCursor(*win, i);
        i++;
    }
}

void onMouse(VoxWindow *win, XEvent *event)
{
    if (IsMouseButtonDown(*win, Button1Mask))
    {
        puts("Segurando esquerdo");
    }

    VoxMousePosition mouse = GetMouse(*win);

    printf("in root y -> %d, in root x -> %d\n", mouse.rootX, mouse.rootY);
    printf("in screen y -> %d, in screen x -> %d\n", mouse.x, mouse.y);
}

void onDraw(VoxWindow *win, XEvent *event)
{
    (void)event;

    DrawClear(win);

    DrawSetColor(
        win,
        BlackPixel(win->display, win->screen)
    );

    DrawPixel(win, 50, 50);

    DrawLine(
        win,
        100,
        50,
        250,
        50
    );

    DrawRectangle(
        win,
        100,
        100,
        150,
        100,
        0
    );

    DrawRectangle(
        win,
        300,
        100,
        150,
        100,
        1
    );

    DrawCircle(
        win,
        100,
        300,
        150,
        150,
        0,
        360 * 64,
        0
    );

    DrawCircle(
        win,
        350,
        300,
        150,
        150,
        0,
        360 * 64,
        1
    );

    DrawText(
        win,
        550,
        100,
        "VoxLib Draw Test"
    );

    DrawSetColor(
        win,
        0xff0000
    );

    DrawLine(
        win,
        550,
        150,
        750,
        150
    );

    DrawSync(win);
    DrawRefresh(win);
}

int main()
{
    VoxWindow *w = CreateWindow(
        800,
        600,
        "Teste of Lib C!",
        KeyPressMask |
        ExposureMask |
        ButtonPressMask |
        ButtonReleaseMask
    );

    if (!w)
    {
        printf("Erro criando janela!\n");
        return 1;
    }

    CreateEvent(
        w,
        KeyPress,
        onKey
    );

    CreateEvent(
        w,
        Expose,
        onDraw
    );

    CreateEvent(
        w,
        ButtonPress,
        onMouse
    );

    CreateEvent(
        w,
        ButtonRelease,
        onMouse
    );

    start(w);

    return 0;
}