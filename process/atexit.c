#include <stdio.h>
#include <stdlib.h>

void final(void) {
  printf("atexit() succeeded\n");
}

int main(void) {
  if(atexit(final)) // If atexit() function succeeds, it returns 0. 0 means false in C lang.
    fprintf(stderr, "atexit() failed!\n");
  return 0;
}
