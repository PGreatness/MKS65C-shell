#include "forkin.h"

//char ** count_str(char )

int main() {
  while(1){
     char ** arr = malloc(sizeof(char *)*256);
     printf("YeOldUsr: ");
     scanf("%s", *arr);
     deal_with_command(*arr);
  }
  /* code */
  return 0;
}
