#include <stdio.h>
#include <unistd.h>

int main() {
  char *pathname = "./creat";  // This file is executable file created by creat.c
  int mode = R_OK | W_OK | X_OK;

  if(access(pathname, mode) == 0) {
    printf("You can read, write or execute this file.\n");
  }
  else{
    printf("You do not have permission or this file does not exist.\n");
  }

  return 0;
}
