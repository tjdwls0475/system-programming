#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  char *filename = "./creat";            
  int mode = F_OK;

  if(access(filename, mode) == 0) {  // First argument of access() must be pointer variable.
    if(chmod(filename, S_IRWXU | S_IRWXG) != 0) {  // chmod() is basically same as the 'chmod' command in Linux.
      printf("chmod() error\n");
      
      return -1;
    }
  }else {
    printf("File '%s' access error\n", filename);

    return -1;
  }

  return 0;
}
