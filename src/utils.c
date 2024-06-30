#include "utils.h"  
#include <stdio.h>
#include <time.h>

void sleep_ms(unsigned long milliseconds) {
  struct timespec req = {0};
  req.tv_sec = milliseconds / 1000;
  req.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&req, NULL);
}
size_t get_file_lines(FILE* fs) {
  size_t lines = 0;
  char c;
  while ((c = fgetc(fs)) != EOF) {
    if (c == '\n') lines++;
  }
  fseek(fs, 0, SEEK_SET);
  return lines;
}
