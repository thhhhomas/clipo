#include "../include/util.h"
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

char* configuration_file_path() {
  struct passwd *p = getpwuid(getuid());
  char *config_path = p->pw_dir;
  char *configuration_file = "/.config/clipocat.conf";

  strcat(config_path, configuration_file);

  return config_path;
}
