#include <stdio.h>
#include <unistd.h>

int main() {
  char* filename = "./creat";
  int mode = F_OK;

  if(access(filename, mode) == 0) {
    if(chown(filename, 74, 995) != 0) {  // I'm not sure why chown() API alreay happened, but I guess System Call API in the 'if' statement have effect.
      printf("chown() error\n");

      return -1;
    }
  }
  else{
    printf("File '%s' access error\n", filename);

    return -1;
  }

  return 0;
}
