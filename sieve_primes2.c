#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// 2 3 5 7....
int main(int argc, char* argv[])
{
  if(argc < 2) {
    printf("arg error");
    return 1;
  }
  long count = 0;
  long max = atoi(argv[1]);
  if(max < 2) {
    printf("max error");
    return 1;
  }
  int end = ceil(sqrt(max));
  max = max + 1;
  char* list = calloc(max, sizeof(char));
  
  printf("Max = %ld End = %d \n", max - 1, end);
  list[0] = 1;
  list[1] = 1;

  for(int sieve = 2;sieve <= end;sieve++) {
    if(list[sieve] == 1) continue;
    for(int index = sieve * 2;index < max;index += sieve) {
      // printf("limit = %d seek = %d sieve = %d\n", limit, seek, sieve);
      list[index] = 1;
    }
  }

  for(int i = 2;i < max;i++) {
    // printf("%d = %d\n", i, list[i]);
    if(list[i] == 0) {
      count++;
    }
  }
  printf("%ld primes\n", count);

  free(list);
  return 0;
}
