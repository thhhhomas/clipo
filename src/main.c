#include "../include/animations.h"
#include "../include/configuration.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// change to configuration source code?
const unsigned int STD_SECONDS = 10;

/*
 * m -> Mode - 1 for 'focusing' 2 for 'resting'
 * t -> define Time
 */

const char *options = "m:t:";

int main (int argc, char **argv) {
  int opt;
  unsigned int seconds = STD_SECONDS;
  unsigned short int mode = 0;

  create_configuration_file(); // insert logic to create configuration file

  while ((opt = getopt(argc, argv, options)) != -1) {
    switch (opt) {
      case 'm':
        mode = atoi(optarg);
        break;

      case 't':
        seconds = atoi(optarg);
        break;

      case '?':
        /*Unknown arguments*/
        break;
    }
  }

  for (; optind < argc; optind++)
    printf("%s", argv[optind]);

  if (mode == 1) {
    cat_focusing(seconds);
  }
  else if (mode == 2) {
    cat_resting(seconds);
  }

  return 0;
}
