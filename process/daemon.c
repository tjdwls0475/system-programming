#include <stdio.h>
#include <unistd.h>

int main() {
  printf("daemon started\n");

  if(daemon(0,0) == -1) {
    perror("daemon error: ");
    return -1;
  }

  while(1) {
    printf("not print line!\n");
    sleep(1);
  }

  return 0;
}
