#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <glob.h>
#include <signal.h>

#include <X11/X.h>
#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "cli.h"
#include "constants.h"
#include "keyboard.h"
#include "options.h"
#include "utils.h"

void ctrl_c(int s) {
  printf("\nProgram interrupted: " FG_CYAN "quiting\n" FG_RESET);
  exit(0);
}
void init_writing(FILE* fptr, const char* fname, Display *display, Options* opts) {
  char current_line[MAX_LINE_SIZE];
  size_t lines = get_file_lines(fptr);

  for (int i = 0; fgets(current_line, MAX_LINE_SIZE, fptr); i++) {
    printf("[" FG_CYAN "%s" FG_RESET "] (line %d of %zu) > ", fname, i, lines);
    write_to_keyboard(current_line, display, opts->interval_between_keys);
    sleep_ms(opts->interval_between_lines) ;
  }
}

int main(int argc, char* argv[]) {
  FILE *current_file = NULL;
  Display *display;
  glob_t glob_results;
  Options opts;
  signal(SIGINT, ctrl_c);
  
  printf(BANNER);
  
  if (argc <= 1)
    opts_from_stdin(&opts);
  else
    opts_from_args(argc, argv, &opts);
    
  if ((display = XOpenDisplay(NULL)) == NULL) {
    perror("Can't open display");
    return 1;
  }

  if (glob(opts.files_g, 0, NULL, &glob_results) != 0) {
    perror("Can't get files");
    return EXIT_FAILURE;
  }

  for (int i = opts.countdown; i > 0; i--) {
    printf("Starting in %d...\r", i);
    fflush(stdout);
    sleep(1);
  }
  printf("Starting...           \n");
  
  for (int i = 0; glob_results.gl_pathv[i]; i++) {
    if ((current_file = fopen(glob_results.gl_pathv[i], "r")) == NULL) {
      printf("Can't open file: ignoring\n");
    } else {
      init_writing(current_file, glob_results.gl_pathv[i], display, &opts);
    }
  }

  if (current_file != NULL) fclose(current_file);
  XCloseDisplay(display);
  globfree(&glob_results);
  return 0;
}
