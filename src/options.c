#include "options.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "constants.h"

#define HELP_LONG "--help"
#define HELP_SHORT "-h"

void show_usage(const char* app_name) {
  printf("\n");
  printf("usage: %s <files> <countdown> <interval between keys> <interval between lines>\n", app_name);
  printf("\n");
  printf("       files           : files to read and write on keyboard (admits glob)\n");
  printf("      coundown         : countdown, gives you time to place your mouse correctly\n");
  printf("interval between keys  : time (ms) between key press\n");
  printf("interval between lines : time (ms) between each line\n");
}
void opts_from_args(int argc, 
  char* argv[],
  Options* options) {
  if (strcmp(argv[1], HELP_LONG) == 0 || strcmp(argv[1], HELP_SHORT) == 0) {
    show_usage(argv[0]);
    exit(EXIT_SUCCESS);
  }
  if (argc < 5) {
    printf("error: insufficient arguments\n");
    show_usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  strncpy(options->files_g, argv[1], sizeof(options->files_g) - 1);
  options->files_g[sizeof(options->files_g) - 1] = '\0';

  if ((options->countdown = atoi(argv[2])) == 0) {
    printf("error: can't parse countdown : setting to %d\n", DEFAULT_COUNTDOWN);
    options->countdown = DEFAULT_COUNTDOWN;
  }
  if ((options->interval_between_keys = atoi(argv[3])) == 0) {
    printf("error: can't parse interval between keys : setting to %d\n", DEFAULT_KEY_INTERVAL);
    options->interval_between_keys = DEFAULT_KEY_INTERVAL;
  }
  if ((options->interval_between_lines = atoi(argv[4])) == 0) {
    printf("error: can't parse interval between lines : setting to %d\n", DEFAULT_LINE_INTERVAL);
    options->interval_between_lines = DEFAULT_LINE_INTERVAL;
  }
}
void opts_from_stdin(Options* opts) {
  printf("Select your file(s): ");
  read_line(opts->files_g);
  
  printf("Countdown (default=%d): ", DEFAULT_COUNTDOWN);
  scanf("%d", &opts->countdown);

  printf("Interval between keys (in ms) (default=%d): ", DEFAULT_KEY_INTERVAL);
  scanf("%d", &opts->interval_between_keys);
   
  printf("Interval between lines (in ms) (default=%d): ", DEFAULT_LINE_INTERVAL);
  scanf("%d", &opts->interval_between_lines);      
}
