#include "forkin.h"

// char ** count_str(char )

int main() {
  while(1){
     char cwd[256];
     getcwd(cwd, sizeof(cwd));
     char* ending_cwd = strrchr(cwd, '/') + 1;

     char str[256];
     printf("%s:Shell$ ", ending_cwd);
     fgets(str, 256, stdin);
     //printf("Got here\n");
     char * tmp_pointer = str;
     char * prev = strsep(&tmp_pointer, "\n");
     //printf("This is prev: %s\n", prev
     if(!strcmp(str,"")) continue;
     deal_with_multiple_commands(str);
     // if(!strcmp(str[0],"cd")){
     // chdir(command[1]);
     // }
  }
  /* code */
  return 0;
}
