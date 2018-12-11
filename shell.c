#include "forkin.h"

// char ** count_str(char )

int main() {
  /*
   * Acts as the "Shell"
   *
   * prompts for input after every command
   * Each input is passed to deal_with_multiple_commands()
   * Ends when prompted with "exit"
   *
   */
  while(1){
     char cwd[256];
     char usr[256];
     getcwd(cwd, sizeof(cwd));
     char* ending_cwd = strrchr(cwd, '/') + 1;
     getlogin_r(usr, sizeof(usr));

     char str[256];
     printf("%s:%s$ ", ending_cwd, usr);
     fgets(str, 256, stdin);
     if (!strncmp("exit", str, 4 )) {
       dup2(0,1);
       break;
     }
     //printf("Got here\n");
     char * tmp_pointer = str;
     char * prev = strsep(&tmp_pointer, "\n");
     //printf("This is prev: %s\n", prev
     if(!strcmp(str,"")) continue;
     deal_with_multiple_commands(str);

  }
  /* code */
  return 0;
}
