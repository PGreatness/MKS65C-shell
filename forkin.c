#include "forkin.h"


char ** parse_args( char * line ) {
    char ** pArray = malloc(sizeof(char *) * 6);
    char * str = line;
    for (int i = 0; i < 6; i++) {
    *(pArray + i) = strsep(&str , " ");
    }
    return pArray;
}

char *** parse_lines (char* line){
	char *** ret = calloc(8, sizeof(char**));
	char *s = strsep(&line, ";");
	int i = 0;
	while (s) {
	        ret[i]=parse_args(s);
		/*printf("%d : %s", i, ans[i]);*/
		s = strsep(&line, ";");
		i++;
	}
	return ret;
}

int lenarray(char*** arr){
	int i=0;
	while(arr[i]){
		i++;
	}
	return i;
}

int sizeofarray(char ** arr){
  int i=0;
  while(arr[i]){
    i++;
  }
  return i;
}

int deal_with_command(char ** command) {
  if (!strcmp(command[0], "exit" )) {
          exit(0);
  }
  if(!strcmp(command[0],"cd")){
			int dir = chdir(command[1]);
      if(dir){
        printf("%s\n", strerror(errno));
      }
	}
  else{
    int parent = fork();
    if(parent){
        //printf("Got here, parent\n");
        int status = 0;
        wait(&status);
        return WEXITSTATUS(status);
      }
    else {
    		 execvp(command[0], command);
         printf("%s : Unknown command. Type \"help\" for more commands\n", command[0]);
         return 0;
       }
   }
}

int deal_with_multiple_commands(char * command){
     char *** lines = parse_lines(command);
     for(int i=0;i<lenarray(lines);i++){
        deal_with_command(lines[i]);
     }
}
