
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>


int lenarray(char*** arr);
int sizeofarray(char ** arr);
char * trimwhitespace(char *str);
char ** parse_args( char * line );
char *** parse_lines (char* line);
int deal_with_command(char ** command);
int deal_with_multiple_commands(char * command);
