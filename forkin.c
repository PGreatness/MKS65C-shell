#include "forkin.h"


char ** parse_args( char * line ) {
  /*
   * Breaks the line into tokens and places
   * the tokens in an arry
   *
   * Takes in parameters line, which is a terminal command, and a delimiter, with which parse_args strseps by.
   * Returns an array with index 0 being the command and all other indices being command arguments.
   */
    char ** pArray = calloc(256, sizeof(char *));
    char * str = trimwhitespace(line);
    for (int i = 0; i < 255; i++) {
    *(pArray + i) = strsep(&str , " ");
    }
    return pArray;
}

char *** parse_lines (char* line){
  /*
   * Breaks the string of lines into individual lines using ";" delimiter
   * parse_args is then called on each line with the result being placed in an index of ret
   *
   * Takes in parameters line which is a string containg multiple commands
   * Returns an array with each index containing a command and its arguments
   */
	char *** ret = calloc(256, sizeof(char**));
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
  /*
   * Returns the length of the given char ***
   */
	int i=0;
	while(arr[i]){
		i++;
	}
	return i;
}

int sizeofarray(char ** arr){
  /*
   * Returns the length of the given char **
   */
  int i=0;
  while(arr[i]){
    i++;
  }
  return i;
}

char * trimwhitespace(char *str){
  /*
   * takes in a string
   * removes the trailing and leading whitespaces of the string
   * returns the modified string
   */
  char *end;
  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)return str;

  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
 }

int deal_with_command(char ** command) {
  /*
   * Deals with an individual command through execvp
   *
   * expected types for command are:
   * cd , > , <, >>, pipes
   *
   * return value is 0 which is only returned if the given command
   * is invalid, otherwise end through execvp
   */
  if(!strcmp(command[0],"cd")){
			int dir = chdir(command[1]);
      if(dir){
        printf("%s\n", strerror(errno));
      }
	}
  else{

        int backup_stdout=dup(STDOUT_FILENO);
        int backup_stdin=dup(STDIN_FILENO);
        int parent = fork();
        if(parent){
            int status = 0;
            wait(&status);
	    			dup2(backup_stdout,STDOUT_FILENO);
		    		dup2(backup_stdin,STDIN_FILENO);
            return WEXITSTATUS(status);
          }
        else {

          				for(int j=0;j<sizeofarray(command);j++){
                    // For redirecting stdout
          					if(!strcmp(command[j],">")){
        	  					int fd=open(command[j+1], O_WRONLY|O_CREAT, 0644);
          						int new=dup2(fd,STDOUT_FILENO);
                      char ** temp = calloc(256, sizeof(char *)); ;
                      for (int index = 0; index < j; index++){
                        temp[index] = command[index];
                      }
          						execvp(temp[0],temp);
                      close(fd);
                      dup2(backup_stdout,STDOUT_FILENO);
                      printf("error: Invalid Command\n");
                      exit(0);
          					}
                    // for redirecting stdin
          					else if(!strcmp(command[j],"<")){
          						int fd=open(command[j+1],O_RDONLY);
          						int new=dup2(fd,STDIN_FILENO);
                      char ** temp = calloc(256, sizeof(char *)); ;
                      for (int index = 0; index < j; index++){
                        temp[index] = command[index];
                      }
          						execvp(temp[0],temp);
                      close(fd);
                      dup2(backup_stdin,STDIN_FILENO);
                      printf("error: Invalid Command\n");
                      exit(0);
          					}
                    // for redirecting stdin while appending
                    else if(!strcmp(command[j],">>")){
                      int fd=open(command[j+1], O_WRONLY|O_CREAT| O_APPEND, 0644);
                      int new=dup2(fd,STDOUT_FILENO);
                      char ** temp = calloc(256, sizeof(char *)); ;
                      for (int index = 0; index < j; index++){
                        temp[index] = command[index];
                      }
                      execvp(temp[0],temp);
                      close(fd);
                      dup2(backup_stdout,STDOUT_FILENO);
                      printf("error: Invalid Command\n");
                      exit(0);
                    }
                    // for dealing with pipes
                    else if (!strcmp(command[j],"|")){
                      int fd[2];
                      pipe(fd);
                      char ** temp = calloc(256, sizeof(char *)); ;
                      for (int index = 0; index < j; index++){
                        temp[index] = command[index];
                      }
                      int frk = fork();
                      if(!frk){
                      	close(fd[0]);
                        int new=dup2(fd[1],STDOUT_FILENO);
                        execvp(temp[0],temp);
                      	exit(0);
                      }
                      else{
                        int status = 0;
                        wait(&status);
                        int rd=dup2(fd[0],STDIN_FILENO);
					            	close(fd[1]);
                      }
                      free(temp);
                      char ** temp1 = calloc(256, sizeof(char *));
                      for (int index = j+ 1; index < sizeofarray(command); index++){
                        temp1[index - j -1] = command[index];
                      }
                        execvp(temp1[0],temp1);
                        printf("error: Invalid Command\n");
                        exit(0);
                      }
          				}
        		 execvp(command[0], command);
             printf("%s : Unknown command. Type \"help\" for more commands\n", command[0]);
             return 0;
           }
      }
}

int deal_with_multiple_commands(char * command){
  /*
   * Takes in a string of multiple commands
   * Parses the string of commands using parse_line
   * Each command is place in an index of parse_lines
   *
   * Iterates through lines while executing each command in each index
   */
     char *** lines = parse_lines(command);
     for(int i=0;i<lenarray(lines);i++){
        deal_with_command(lines[i]);
     }
     return 0;
}
