#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int pause_minutes = 1;
int focusing_minutes = 1;

void cat_resting(int seconds, int cat_version) {
  int minutes = seconds / 60;
  int temp_seconds = seconds % 60;
  switch (cat_version) {
    case 1:
      system("clear");
      printf("[%02d:%02d]\t\tZzz\n", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t(_, _)(\\__\n");
      break;
    
    case 2:
      system("clear");
      printf("[%02d:%02d]\t\tzZz\n", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t(_, _)(\\__\n");
      break;

    case 3:
      system("clear");
      printf("[%02d:%02d]\t\tzzZ\n", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t(_, _)(\\_/\n");
      break;

    default:
      system("clear");
      printf("[%02d:%02d]\t\tZzz\n", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t(_, _)(\\__\n");
      break;
  }

}

void cat_animation(int seconds, int cat_version) {
  int minutes = seconds / 60;
  int temp_seconds = seconds % 60;
  switch (cat_version) {
    case 1:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t('¨' ) \\\n");
      printf("\t `|~|(\\/\n");
      break;
    
    case 2:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t('¨' )  /\n");
      printf("\t `|~|(\\/\n");
      break;

    case 3:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t('¨- )  /\n");
      printf("\t `|~|(\\/\n");
      break;

    case 4:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t(-¨- ) \\\n");
      printf("\t `|~|(\\/\n");

    case 5:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t('¨- )  /\n");
      printf("\t `|~|(\\/\n");
      break;

    default:
      system("clear");
      printf("[%02d:%02d]", minutes, temp_seconds);
      printf("\t /|_/|\n");
      printf("\t('¨' ) \\\n");
      printf("\t `|~|(\\/\n");
      break;

  }

}

void active_timer (int minutes, bool is_focus) {
  int seconds = minutes * 60;
  for (int i = seconds; i > 0; i--) {
    if (is_focus) cat_animation(i, (rand() % (15 - 2) + 1));
    else cat_resting(i, (rand() % (4 - 2) + 1));
    sleep(1);
  }
}

void pomodoro_menu() {
  int choice;

  do {
    printf("------=== CLIPO ===------\n");
    printf("1. Start focusing (%02d:00)\n", focusing_minutes);
    printf("2. Start pause    (%02d:00)\n", pause_minutes);
    printf("3. Back to main menu\n");
    printf("-------------------------\n");
    printf("Enter an option: ");

     // verifying entry
    if (scanf("%d", &choice) != 1) {
      system("clear");
      printf("Invalid input\n");
      while(getchar() != '\n'); // consumes until new line
      continue;
    }

    switch (choice) {
      case 1:
        active_timer(focusing_minutes, true);
        system("clear");
        break;

      case 2:
        active_timer(pause_minutes, false);
        system("clear");
        break;

      case 3:
        system("clear");
        break;

      default:
        system("clear");
        printf("Not an option\n");
    }
  } while(choice != 3);
}

void save_configurations(char *filename) {
  FILE *file = fopen(filename, "w");
  if(file == NULL) {
    printf("Warning: failed to open file to write");
    return;
  }

  fprintf(file, "%d;%d", focusing_minutes, pause_minutes);

  fclose(file);
}

void configuration_menu() {
  int choice, new_focusing_minutes, new_pause_minutes;
  do {
    printf("------=== CLIPO ===------\n");
    printf("Focusing time: %d minutes\n", focusing_minutes);
    printf("Pause time...: %d minutes\n", pause_minutes);
    printf("-------------------------\n");
    printf("1. Change focusing time\n");
    printf("2. Change pause time\n");
    printf("3. Save configurations\n");
    printf("4. Back to main menu\n");
    printf("-------------------------\n");
    printf("Enter an option: ");

    if (scanf("%d", &choice) != 1) {
      system("clear");
      printf("Invalid input\n");
      while(getchar() != '\n'); // consumes until new line
      continue;
    }
    
    while(getchar() != '\n'); // consumes until new line

    switch (choice) {
      case 1:
        system("clear");
        printf("Enter new amount (minutes): ");
        if (scanf("%d", &new_focusing_minutes) != 1) {
          system("clear");
          printf("Invalid input\n");
          while(getchar() != '\n'); // consumes until new line
          continue;
        }

        while(getchar() != '\n');

        focusing_minutes = new_focusing_minutes;
        break;

      case 2:
        system("clear");
        printf("Enter new amount (minutes): ");
        if (scanf("%d", &new_pause_minutes) != 1) {
          system("clear");
          printf("Invalid input\n");
          while(getchar() != '\n'); // consumes until new line
          continue;
        }

        while(getchar() != '\n');

        pause_minutes = new_pause_minutes;
        break;

      case 3:
        save_configurations("config");
        system("clear");
        break;


      case 4:
        system("clear");
        break;
    }
  } while(choice != 4);
}

void main_menu() {
  int choice;
  do {
    printf("------=== CLIPO ===------\n");
    printf("1. Start focusing\n");
    printf("2. Configurations\n");
    printf("3. Exit\n");
    printf("-------------------------\n");
    printf("Enter an option: ");

    // verifying entry
    if (scanf("%d", &choice) != 1){
      system("clear");
      printf("Invalid input\n");
      while(getchar() != '\n'); // consumes until new line
      continue;
    }

    switch (choice) {
      case 1:
        system("clear");
        pomodoro_menu();
        break;

      case 2:
        system("clear");
        configuration_menu();
        break;
        
      case 3:
        system("clear");
        break;
    }

  } while(choice != 3);
}

void read_configutarion(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Warning: Could not read configuration file. Using default values");
    return;
  }
  
  char line[6];
  
  while (fgets(line, sizeof(line), file) != NULL) {
    char *first_separator = strchr(line, ';');
    if (first_separator == NULL) {
      printf("Warning: Configuration file missing ';'. Using default values");
      continue;
    }

    *first_separator = '\0';
    focusing_minutes = atoi(line);

    pause_minutes = atoi(first_separator + 1);

    break;
  }

  fclose(file);
}

int main(void) {
  
  read_configutarion("config");
  
  system("clear");
  
  main_menu();

  return 0;
}
