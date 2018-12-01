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
  char ** args = parse_args(command);
  int parent = fork();
  //printf("we are here\n");
  if(parent){
      //printf("Got here, parent\n");
      int status = 0;
      wait(&status);
      //if (!(strcmp(args[0], "cd"))) {
	//char ** first = strsep(args, "\0");
	//chdir(strsep(args[
      return WEXITSTATUS(status);
    }
  else {
     //printf("Got here, child\n");
     //printf("%s\n", );
     execvp(args[0], args);
     printf("%s : Unknown command. Type \"help\" for more commands\n", args[0]);
     return 0;
   }
}

/*int main(){
    char str[] = "ls -l";
    deal_with_command(str);
    return 0;
}*/
