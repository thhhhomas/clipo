#include "../include/configuration.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool create_configuration_file() {
  FILE *f = fopen(configuration_file_path(), "w");

  if (!f) {
    printf("Warning: Unable to open configuration file.\n");
    return false;
  }

  fprintf(f, "focusing_time=%d\nresting_time=%d\nlong_break=%d", STD_FOCUSING_TIME, STD_RESTING_TIME, STD_LONG_BREAK);

  fclose(f);

  return true;
}

timer_pomodoro_t retrieve_configuration() {
  timer_pomodoro_t timer = {
    STD_FOCUSING_TIME,
    STD_RESTING_TIME,
    STD_LONG_BREAK
  };

  FILE *f = fopen(configuration_file_path(), "r");

  if (!f) {
    printf("Warning: Unable to open configuration file. Using standard configuration.\n");
  }
  else {
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), f)) {
      char *end_of_line = strchr(line, '\n');
      if (end_of_line) *end_of_line = '\0';

      if (line[0] == '#' || line[0] == '\0') continue;

      char *eq = strchr(line, '=');
      if (!eq) continue;

      *eq = '\0';

      char *parameter = line;
      char *value = eq + 1;

      if (strcmp(parameter, "focusing_time") == 0) timer.focusing_time = atoi(value);
      else if (strcmp(parameter, "resting_time") == 0) timer.resting_time = atoi(value);
      else if (strcmp(parameter, "long_break") == 0) timer.long_break = atoi(value);
    }
  }

  return timer;
}

bool save_configuration(timer_pomodoro_t timer) {
  if (!timer.focusing_time || !timer.resting_time || !timer.long_break){
    printf("Warning: Missing value(s). Configuration not saved.\n");
    return false;
  }

  FILE *f = fopen(configuration_file_path(), "w");

  if (!f) {
    printf("Warning: Unable to open configuration file. Configuration not saved.\n");
    return false;
  }

  fprintf(f, "focusing_time=%d\nresting_time=%d\nlong_break=%d", timer.focusing_time, timer.resting_time, timer.long_break);

  fclose(f);

  return true;
}
