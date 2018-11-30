#include "forkin.h"

// char ** count_str(char )

int main() {
  while(1){
     char str[256];
     printf("YeOldUsr: ");
     fgets(str, 256, stdin);
     char * index = strchr(str, '\n');
     index = NULL;
     deal_with_command(str);
     sleep(3);
     for (int i = 0; i < 100; i++) {
       printf("This is str[%i]: %c\n", i, str[i]);
    }
  }
  /* code */
  return 0;
}
