#include <stdio.h>
#include <fcntl.h>  // for mode_t
#include <errno.h>  // for errno
#include <string.h>  // for strerror

int main() {
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  char *filename = "/tmp/file";

  fd = creat(filename, mode);

  if(fd < 0) {
    printf("creat error: %s\n", strerror(errno));
    return -1;
  }

  printf("your file descripter number: %d\n", fd);

  return 0;
}
