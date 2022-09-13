#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  char *filename = "./creat";            
  int mode = F_OK;  // 'F_OK' checks if file exists. But I don't know how 'F_OK' can be saved to 'int' date type..

  if(access(filename, mode) == 0) {  // First argument of access() API must be pointer variable.
    if(chmod(filename, S_IRWXU | S_IRWXG) != 0) {  // chmod() API is basically same as the 'chmod' command in Linux.
      printf("chmod() error\n");
      
      return -1;
    }
  }else {
    printf("File '%s' access error\n", filename);

    return -1;
  }

  return 0;
}
