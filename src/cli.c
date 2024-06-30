#include "cli.h"
#include <stdio.h>
#include <string.h>
int read_line(char *buf) {
  if (!fgets(buf, sizeof(buf), stdin)) return 1;
  buf[strcspn(buf, "\n")] = '\0';
  return 0;
}
