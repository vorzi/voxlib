#include "voxlib.h"
#include <stdio.h>

int i = 0;
int b = 0;

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
        puts("Tecla O pressionada, Mostrando Cursor");
        ShowCursor(*win);
    }

    if (key == KEY_I) {

        if (i > 137)
            i = 0;

        printf("Tecla I pressionada, Mudando Cursor, indo de %d -> %d\n", i - 1, i);
        ChangeCursor(*win, i);
        i++;
    }

    if (key == KEY_B) {
        b = !b;

        printf("Fundo: %s\n", b ? "Preto" : "Branco");

        /* força um evento Expose para chamar onDraw() */
        XClearArea(
            win->display,
            win->window,
            0,
            0,
            0,
            0,
            True
        );
    }
}

void onMouse(VoxWindow *win, XEvent *event)
{
    (void)event;

    if (IsMouseButtonDown(*win, Button1Mask))
    {
        puts("Segurando esquerdo");
    }

    VoxMousePosition mouse = GetMouse(*win);

    printf("root: (%d, %d)\n", mouse.rootX, mouse.rootY);
    printf("window: (%d, %d)\n", mouse.x, mouse.y);
}

void onDraw(VoxWindow *win, XEvent *event)
{
    (void)event;

    if (b) {
        SetWindowBackground(win, BlackPixel(win->display, win->screen)); 
        DrawSetColor(win, WhitePixel(win->display, win->screen));
    } else {
        SetWindowBackground(win, WhitePixel(win->display, win->screen)); 
        DrawSetColor(win, BlackPixel(win->display, win->screen));
    }
    DrawClear(win);


    DrawPixel(win, 50, 50);

    DrawLine(win, 100, 50, 250, 50);

    DrawRectangle(win, 100, 100, 150, 100, 0);

    DrawRectangle(win, 300, 100, 150, 100, 1);

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

    
    DrawText(
        win,
        576,
        260,
        "Yeah! Catholicism good!"
    );
    
    DrawLine(win, 630, 190, 630, 230);
    DrawLine(win, 618, 205, 642, 205);
    
    DrawSetColor(win, 0xff0000);

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

int main(void)
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

    CreateEvent(w, KeyPress, onKey);
    CreateEvent(w, Expose, onDraw);
    CreateEvent(w, ButtonPress, onMouse);
    CreateEvent(w, ButtonRelease, onMouse);

    start(w);

    return 0;
}