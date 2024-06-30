#ifndef OPTIONS_H
#define OPTIONS_H
  
#include "constants.h"

typedef struct {
  int countdown;
  int interval_between_keys;
  int interval_between_lines;
  char files_g[MAX_FILES_SIZE];
} Options;

void opts_from_args(int argc, 
  char* argv[], 
  Options* opts);

void opts_from_stdin(
 Options* opts);

#endif
