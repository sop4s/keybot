#include <stdio.h>
#include <X11/X.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include "keyboard.h"
#include "utils.h"

void send_key(KeySym sym, int keydown, Display* display) {
  KeyCode code = XKeysymToKeycode(display, sym);
  XTestFakeKeyEvent(display, code, keydown, 0);
}
void press(KeySym sym, Display* display) {
  KeyCode code = XKeysymToKeycode(display, sym);

  XTestFakeKeyEvent(display, code, KEYDOWN, 0);
  XFlush(display);
  XTestFakeKeyEvent(display, code, KEYUP, 0);
  XFlush(display);
}
void write_to_keyboard(const char* txt, Display *display, int interval) {
  KeySym sym;
  char buf[2] = " \0";
  int is_uppercase;
  for (int i = 0; i < strlen(txt); i++) {
    buf[0] = txt[i];
    is_uppercase = ( txt[i] >= 'A' && txt[i] <= 'Z' );
    fflush(stdout);
    printf("%c", txt[i]);
    
    sym = XStringToKeysym(buf);
   
    switch (buf[0]) {
      case '\n':      
        press(XK_Return, display);
        break;
      case ' ':
        press(XK_space, display);
        break;
      default:
        if (is_uppercase) {
          send_key(XK_Shift_L, KEYDOWN, display);
          press(sym, display);
          send_key(XK_Shift_L, KEYUP, display);
        } else {
          press(sym, display);
        }
        break;
    }

    sleep_ms(interval);
  }
}
