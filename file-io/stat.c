#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat sb;
  int ret;

  if(argc < 2) {
    printf("You need more argument\n");
    return -1;
  }

  ret = stat(argv[1], &sb);  // stat API returns 0, if it succeeds. And it returns other integer otherwise.

  if(ret) {
    perror("stat error: ");
    return -1;
  }

  printf("File '%s' is %ld bytes\n", argv[1], sb.st_size);  // 

  return 0;
}
