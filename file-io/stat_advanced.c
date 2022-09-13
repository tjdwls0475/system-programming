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

  ret = stat(argv[1], &sb);

  if(ret) {
    perror("stat error: ");
    return -1;
  }

  switch(sb.st_mode & S_IFMT) {
    case S_IFBLK:
      printf("block device node\n");
      break;
    case S_IFCHR:
      printf("character device node\n");
      break;
    case S_IFDIR:
      printf("directory\n");
      break;
    case S_IFIFO:
      printf("FIFO\n");
      break;
    case S_IFLNK:
      printf("symbolic link\n");
      break;
    case S_IFREG:
      printf("regular file\n");
      break;
    case S_IFSOCK:
      printf("socket\n");
      break;
    default:
      printf("unknown\n");
      break;
  }

  return 0;
}
