#include "voxlib.h"
#include <stdio.h>

void onKey(VoxWindow *win, XEvent *event)
{
    VoxKey key = GetKey(event);

    puts("Tecla pressionada!");

    if (key == KEY_Q) {
        puts("Tecla Q pressionada, saindo!");
        DestroyWindow(win);
    };
}

void onDraw(VoxWindow *win, XEvent *event)
{
    (void)event;

    DrawClear(win);

    // Preto
    DrawSetColor(
        win,
        BlackPixel(win->display, win->screen)
    );

    // Pixel
    DrawPixel(
        win,
        50,
        50
    );

    // Linha
    DrawLine(
        win,
        100,
        50,
        250,
        50
    );

    // Retângulo vazio
    DrawRectangle(
        win,
        100,
        100,
        150,
        100,
        0
    );

    // Retângulo preenchido
    DrawRectangle(
        win,
        300,
        100,
        150,
        100,
        1
    );

    // Círculo vazio
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

    // Círculo preenchido
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

    // Texto
    DrawText(
        win,
        550,
        100,
        "VoxLib Draw Test"
    );

    // Vermelho
    DrawSetColor(
        win,
        0xff0000
    );

    // Linha vermelha
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
        KeyPressMask | ExposureMask
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

    start(w);

    return 0;
}