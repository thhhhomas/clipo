#pragma once

#include <stdbool.h>
#include <pwd.h>
#include "util.h"

#define STD_FOCUSING_TIME 25
#define STD_RESTING_TIME 5
#define STD_LONG_BREAK 10

#define MAX_LINE 256

typedef struct timer_pomodoro {
  int focusing_time;
  int resting_time;
  int long_break;
} timer_pomodoro_t;

bool save_configuration(timer_pomodoro_t timer_configuration);

timer_pomodoro_t retrieve_configuration();

bool create_configuration_file();
