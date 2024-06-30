#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <X11/Xlib.h>

#define KEYDOWN 1
#define KEYUP 0

void write_to_keyboard(const char* txt, Display *display, int interval);

#endif
