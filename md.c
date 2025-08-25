#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_user_input(char user_prompt[150], char buffer[150],
                     bool is_optional) {

  char user_input[150];

  printf("%s", user_prompt);

  bool need_input = true;

  while (need_input) {
    strcpy(buffer, fgets(user_input, sizeof(user_input), stdin));
    buffer[strcspn(buffer, "\n")] = '\0';
    if (need_input) {
      need_input = false;
    }
  }

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
  char titlebuf[50];
  get_user_input("What's your title?\n", titlebuf, true);

  printf("%s.md", titlebuf);

  return 0;
}
