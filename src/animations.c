#include "../include/animations.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void cat_focusing(int seconds) {
  int temp_minutes;
  int temp_seconds;
  int cat_version;

  for (int i = seconds; i >= 0; i--) {
    temp_minutes = i / 60;
    temp_seconds = i % 60;
    cat_version = rand() % 15;

    switch (cat_version) {
      case 0:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t('¨' ) \\\n");
        printf("\t `|~|(\\/\n");
        break;
      
      case 1:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t('¨' )  /\n");
        printf("\t `|~|(\\/\n");
        break;

      case 2:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t('¨- )  /\n");
        printf("\t `|~|(\\/\n");
        break;

      case 3:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t(-¨- ) \\\n");
        printf("\t `|~|(\\/\n");
        break;

      case 4:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t('¨- )  /\n");
        printf("\t `|~|(\\/\n");
        break;

      default:
        system("clear");
        printf("[%02d:%02d]", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t('¨' ) \\\n");
        printf("\t `|~|(\\/\n");
        break;
    }
    sleep(1);
  }
}

void cat_resting(int seconds) {
  int temp_minutes;
  int temp_seconds;
  int cat_version ;

  for (int i = seconds; i >= 0; i--) {
    temp_minutes = i / 60;
    temp_seconds = i % 60;
    cat_version = rand() % 5;

    switch (cat_version) {
      case 0:
        system("clear");
        printf("[%02d:%02d]\t\tZzz\n", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t(_, _)(\\__\n");
        break;
      
      case 1:
        system("clear");
        printf("[%02d:%02d]\t\tzZz\n", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t(_, _)(\\__\n");
        break;

      case 2:
        system("clear");
        printf("[%02d:%02d]\t\tzzZ\n", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t(_, _)(\\_/\n");
        break;

      default:
        system("clear");
        printf("[%02d:%02d]\t\tZzz\n", temp_minutes, temp_seconds);
        printf("\t /|_/|\n");
        printf("\t(_, _)(\\__\n");
        break;
    }
    sleep(1);
  }
}
