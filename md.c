#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_user_input(char user_prompt[150], char buffer[150]) {

  char user_input[150];

  printf("%s", user_prompt);

  strcpy(buffer, fgets(user_input, sizeof(user_input), stdin));
  buffer[strcspn(buffer, "\n")] = '\0';

  return buffer;
}

int main(void) {

  // save location
  const char *HOME = getenv("HOME");
  char *inbox_sub_directory = "/sync-vault/Inbox";
  char SAVE_LOCATION[50];
  strcpy(SAVE_LOCATION, HOME);
  strcat(SAVE_LOCATION, inbox_sub_directory);

  printf("%s\n", SAVE_LOCATION);

  // datetime
  time_t rawtime;
  struct tm *timeinfo;
  char dtbuffer[11]; // "YYYY-MM-DD\0"
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(dtbuffer, sizeof(dtbuffer), "%Y-%m-%d", timeinfo);

  printf("%s\n", dtbuffer);

  // Title
  char title_buf[50];
  title_buf[0] = '\0';
  while (title_buf[0] == '\0') {
    get_user_input("What's your title?\n", title_buf);
  }
  printf("%s.md\n", title_buf);

  // Tags
  char tags_buf[100];
  get_user_input("Tags:\n", tags_buf);

  char *tags[20];
  const char *delimiters = " ,;";
  char *token;
  int count = 0;

  if (tags_buf[0] != '\0') {
    token = strtok(tags_buf, delimiters);

    while (token != NULL && count < 20) {
      tags[count] = token;
      printf("Tag %i: %s\n", count, tags[count]);
      count++;
      token = strtok(NULL, delimiters);
    }
    return 0;
  }
}
