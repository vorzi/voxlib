#include "../include/voxlib.h"
#include <X11/keysym.h>

VoxKey GetKey(XEvent *event)
{
    KeySym sym = XLookupKeysym(&event->xkey, 0);

    switch (sym)
    {
        case XK_a: case XK_A: return KEY_A;
        case XK_b: case XK_B: return KEY_B;
        case XK_c: case XK_C: return KEY_C;
        case XK_d: case XK_D: return KEY_D;
        case XK_e: case XK_E: return KEY_E;
        case XK_f: case XK_F: return KEY_F;
        case XK_g: case XK_G: return KEY_G;
        case XK_h: case XK_H: return KEY_H;
        case XK_i: case XK_I: return KEY_I;
        case XK_j: case XK_J: return KEY_J;
        case XK_k: case XK_K: return KEY_K;
        case XK_l: case XK_L: return KEY_L;
        case XK_m: case XK_M: return KEY_M;
        case XK_n: case XK_N: return KEY_N;
        case XK_o: case XK_O: return KEY_O;
        case XK_p: case XK_P: return KEY_P;
        case XK_q: case XK_Q: return KEY_Q;
        case XK_r: case XK_R: return KEY_R;
        case XK_s: case XK_S: return KEY_S;
        case XK_t: case XK_T: return KEY_T;
        case XK_u: case XK_U: return KEY_U;
        case XK_v: case XK_V: return KEY_V;
        case XK_w: case XK_W: return KEY_W;
        case XK_x: case XK_X: return KEY_X;
        case XK_y: case XK_Y: return KEY_Y;
        case XK_z: case XK_Z: return KEY_Z;

        case XK_0: return KEY_0;
        case XK_1: return KEY_1;
        case XK_2: return KEY_2;
        case XK_3: return KEY_3;
        case XK_4: return KEY_4;
        case XK_5: return KEY_5;
        case XK_6: return KEY_6;
        case XK_7: return KEY_7;
        case XK_8: return KEY_8;
        case XK_9: return KEY_9;

        case XK_minus:       return KEY_MINUS;
        case XK_equal:       return KEY_EQUAL;
        case XK_bracketleft: return KEY_LEFT_BRACKET;
        case XK_bracketright:return KEY_RIGHT_BRACKET;
        case XK_backslash:   return KEY_BACKSLASH;
        case XK_semicolon:   return KEY_SEMICOLON;
        case XK_apostrophe:  return KEY_APOSTROPHE;
        case XK_grave:       return KEY_GRAVE;
        case XK_comma:       return KEY_COMMA;
        case XK_period:      return KEY_PERIOD;
        case XK_slash:       return KEY_SLASH;
        case XK_less:        return KEY_LESS;

        case XK_Return:      return KEY_ENTER;
        case XK_Escape:      return KEY_ESCAPE;
        case XK_BackSpace:   return KEY_BACKSPACE;
        case XK_Tab:         return KEY_TAB;
        case XK_space:       return KEY_SPACE;
        case XK_Delete:      return KEY_DELETE;
        case XK_Insert:      return KEY_INSERT;

        case XK_Home:        return KEY_HOME;
        case XK_End:         return KEY_END;
        case XK_Page_Up:     return KEY_PAGE_UP;
        case XK_Page_Down:   return KEY_PAGE_DOWN;

        case XK_Left:        return KEY_LEFT;
        case XK_Right:       return KEY_RIGHT;
        case XK_Up:          return KEY_UP;
        case XK_Down:        return KEY_DOWN;

        case XK_Shift_L:
        case XK_Shift_R:     return KEY_SHIFT;

        case XK_Control_L:
        case XK_Control_R:   return KEY_CONTROL;

        case XK_Alt_L:
        case XK_Alt_R:       return KEY_ALT;

        case XK_Super_L:
        case XK_Super_R:     return KEY_SUPER;

        case XK_Caps_Lock:   return KEY_CAPS_LOCK;
        case XK_Num_Lock:    return KEY_NUM_LOCK;
        case XK_Scroll_Lock: return KEY_SCROLL_LOCK;

        case XK_F1:  return KEY_F1;
        case XK_F2:  return KEY_F2;
        case XK_F3:  return KEY_F3;
        case XK_F4:  return KEY_F4;
        case XK_F5:  return KEY_F5;
        case XK_F6:  return KEY_F6;
        case XK_F7:  return KEY_F7;
        case XK_F8:  return KEY_F8;
        case XK_F9:  return KEY_F9;
        case XK_F10: return KEY_F10;
        case XK_F11: return KEY_F11;
        case XK_F12: return KEY_F12;

        case XK_KP_0:        return KEY_KP_0;
        case XK_KP_1:        return KEY_KP_1;
        case XK_KP_2:        return KEY_KP_2;
        case XK_KP_3:        return KEY_KP_3;
        case XK_KP_4:        return KEY_KP_4;
        case XK_KP_5:        return KEY_KP_5;
        case XK_KP_6:        return KEY_KP_6;
        case XK_KP_7:        return KEY_KP_7;
        case XK_KP_8:        return KEY_KP_8;
        case XK_KP_9:        return KEY_KP_9;

        case XK_KP_Add:      return KEY_KP_ADD;
        case XK_KP_Subtract: return KEY_KP_SUBTRACT;
        case XK_KP_Multiply: return KEY_KP_MULTIPLY;
        case XK_KP_Divide:   return KEY_KP_DIVIDE;
        case XK_KP_Decimal:  return KEY_KP_DECIMAL;
        case XK_KP_Enter:    return KEY_KP_ENTER;

        default:
            return KEY_UNKNOWN;
    }
}

/* Is Key Down or Up is check if is typing */
Bool IsKeyDown(XEvent *event, VoxKey key)
{
    if (event->type != KeyPress)
        return False;

    return GetKey(event) == key;
}

Bool IsKeyUp(XEvent *event, VoxKey key)
{
    if (event->type != KeyRelease)
        return False;

    return GetKey(event) == key;
}