#include "forkin.h"

int deal_with_command(char ** command) {
  int child1 = fork();
  if (!child1) {
    return execvp(*(&command[0]), command);
  }else{
    int status = 0;
    wait(&status);
    return WEXITSTATUS(status);
  }
}



// int main() {
  /*int mainPid = getpid();
  int child1 = fork();
  int child2;
  if (child1) {
    child2 = fork();
  }

  int status;
  if(getpid() == mainPid){
    int pid = wait(&status);
    printf("I have waited for child %d, who has been asleep for %d seconds\n", pid, WEXITSTATUS(status));
    printf("I am the parent and I am done\n");
    exit(0);
  }
  int randval;
  if(getpid() != mainPid){
      printf("I am child with Pid: %d\n", getpid() );
      srand(getpid());
      randval = abs(rand()%16 + 5);
      sleep(abs(rand()%16 + 5));
      printf("I am Pid: %d, and I have finished.\n" , getpid() );
  }


  return randval;*/
// }
