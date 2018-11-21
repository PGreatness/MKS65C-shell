#include "forkin.h"


char ** parse_args( char * line ) {
    char ** pArray = malloc(sizeof(char *) * 256);
    char * str = line;
    for (int i = 0; i < 6 && *(pArray + i)!= NULL; i++) {
    *(pArray + i) = strsep(&str , " ");
    }
    return pArray;
}


int deal_with_command(char * command) {
  int child1 = fork();
  if (!child1) {
     char * line = command;
     char ** args = parse_args(line);
     execvp(args[0], args);
     printf("this shouldnt print\n");
     return 0;
  }else{
    int status = 0;
    wait(&status);
    return WEXITSTATUS(status);
  }
}

int main(int argc, char * argv[]){
    deal_with_command("ls -l");
    return 0;
}
