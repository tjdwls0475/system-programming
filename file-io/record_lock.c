#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define LOCK_T 0
#define UNLOCK_T 1
#define BUFSIZE 1024

int record_lock(int type, int fd, int start, int len) {
  int ret;
  struct flock lock;

  lock.l_type = (type == LOCK_T) ? F_WRLCK : F_UNLCK;
  lock.l_start = start;
  lock.l_whence = SEEK_SET;
  lock.l_len = len;

  ret = fcntl(fd, F_SETLK, &lock);

  return ret;
}

int main(int argc, char**argv) {
  int fd;
  int record_start, record_len;
  char buf[BUFSIZE] = {0};
  int i;

  if(argc < 4) {
    printf("You need more arguments.\n");
    exit(0);
  }

  fd = open(argv[1], O_RDWR);  // open() API is used, when opening a file or creating new file. And it returns file descripter.

  if(fd == -1) {
    perror("File open error: ");
    exit(0);
  }

  record_start = atoi(argv[2]);
  record_len = atoi(argv[3]);

  if(record_len > BUFSIZE) {
    printf("record_len(%d) cannot be over %d\n", record_len, BUFSIZE);
    exit(0);
  }

  /* Record Lock */
  if(record_lock(LOCK_T, fd, record_start, record_len) == -1) {
    perror("record lock error: ");
    exit(0);
  }

  /* Process Data */
  lseek(fd, record_start, SEEK_SET);  // lseek() API changes the location of the pointer of open file descripter.

  if(read(fd, buf, record_len) < 0) {  // read() API returns the size of buffer that has been read. It returns 0, if file ends.
    perror("read error: ");
    exit(0);
  }

  printf("record data = %s\n", buf);

  /* Data Modify */
  for(i=0; i<record_len; i++) {
    if(buf[i] == '0' || buf[i] == '9') buf[i] = 'x';
  }

  lseek(fd, record_start, SEEK_SET);
  write(fd, buf, record_len);  // write() API returns the size of buffer that has been written. It returns 0, if it writes nothing.

  /* Delay 20sec */
  sleep(20);
  printf("record lock process done\n");

  /* Record Unlock */
  if(record_lock(UNLOCK_T, fd, record_start, record_len) == -1) {
    perror("record unlock error: ");
    exit(0);
  }

  close(fd);  // close() API returns file descripter, when it successes. Or it returns -1.

  return 0;
}
