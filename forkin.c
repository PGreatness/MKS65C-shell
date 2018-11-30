#include "forkin.h"


char ** parse_args( char * line ) {
    char ** pArray = malloc(sizeof(char *) * 6);
    char * str = line;
    for (int i = 0; i < 6; i++) {
    *(pArray + i) = strsep(&str , " ");
    }
    return pArray;
}


int deal_with_command(char * command) {
  int parent = fork();
  printf("we are here\n");
  if(parent){
      printf("Got here, parent\n");
      int status = 0;
      wait(&status);
      return WEXITSTATUS(status);
    }
  else {
     printf("Got here, child\n");
     char ** args = parse_args(command);
     //printf("%s\n", );
     execvp(args[0], args);
     printf("this shouldnt print\n");
     return 0;
   }
}

/*int main(){
    char str[] = "ls -l";
    deal_with_command(str);
    return 0;
}*/
