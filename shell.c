#include "forkin.h"

// char ** count_str(char )

int main() {
  while(1){
     char str[256];
     char cwd[PATH_MAX];
     char usr[CHAR_MAX];
     //printf("\n%s", getcwd(cwd, sizeof(cwd)));
     getcwd(cwd, sizeof(cwd));
     getlogin_r(usr, sizeof(usr));
     //printf("cwd: %s\n", cwd);
     char * tmp_u = usr;
     char * tmp_d = cwd;
     /*char * index = strstr(tmp_d, tmp_u);
     char replace[PATH_MAX];
     int i = 0;
     while(*index) {
	replace[i] = index[i];
        i++;
     }*/
     //char * prev_tmp = strsep(&tmp_d, tmp_u);
     //printf("tmp_u: %s\ttmp_d: %s\treplace: %s\n", tmp_u, tmp_d, replace);
     printf("\n%s", tmp_d);
     printf("\n%s: ", tmp_u);
     fgets(str, 256, stdin);
     //printf("Got here\n");
     char * tmp_pointer = str;
     char * prev = strsep(&tmp_pointer, "\n");
     //printf("This is prev: %s and this is tmp_pointer: %s\n", prev, tmp_pointer);
     char * segment = strsep(&prev, ";");
     while (segment) {
       // printf("This is segment: %s\n", segment);
	deal_with_command(segment);
        segment = strsep(&prev, ";");
        //printf("Here");
        if (segment && segment[0] == ' ') {
           int i = 1;
           char replace[CHAR_MAX];
           while (segment[i]) {
                 replace[i - 1] = segment[i];
                 i++;
          }
          segment = replace;
       }
     }
     //sleep(1);
     //for (int i = 0; i < 100; i++) {
     //  printf("This is str[%i]: %c\n", i, str[i]);
   // }
  }
  return 0;
}
