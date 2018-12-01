#include "forkin.h"

// char ** count_str(char )

int main() {
  while(1){
     char str[256];
     printf("YeOldUsr: ");
     fgets(str, 256, stdin);
     //printf("Got here\n");
     char * tmp_pointer = str;
     char * prev = strsep(&tmp_pointer, "\n");
     //printf("This is prev: %s\n", prev);
     deal_with_command(str);
     //sleep(1);
     //for (int i = 0; i < 100; i++) {
     //  printf("This is str[%i]: %c\n", i, str[i]);
   // }
  }
  /* code */
  return 0;
}
