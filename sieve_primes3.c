#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// #define DEBUG 1

void intTo2digit(int num, char* digitDest)
{
  for(int i = 0;i < 8;i++) {
    digitDest[7 - i]= '0';
    int bit = 1 << i;
    if((num & bit) == bit) {
      digitDest[7 - i] = '1';
    }
  }
}

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
  int booleanBytes = ceil(max / 8.0);
  char* list = calloc(booleanBytes, sizeof(char));
  char outBuff[] = "00000000";

  printf("Max = %ld End = %d Bytes = %d \n", max - 1, end, booleanBytes);

  list[0] = 0x03;

  for(int sieve = 4;sieve <= max;sieve += 2) {
    int index = sieve / 8;
    int value = 1 << (sieve % 8);
    list[index] = list[index] | value;
  }

#ifdef DEBUG
  // Show all pirmes
  for(int i = 0;i < booleanBytes;i++) {
    intTo2digit(list[i], outBuff);
    printf("[%d]:%s\n", i, outBuff);
  }
#endif

  for(int sieve = 3;sieve <= end;sieve+=2) {
    int index = sieve / 8;
#ifdef DEBUG
    printf("%02d: index=%d value=%d\n", sieve, index, (1 << (sieve % 8)));
#endif
    if((list[index] & (1 << (sieve % 8))) == 1) continue;
    for(int index2 = sieve * 2;index2 < max;index2 += sieve) {
      int index3 = index2 / 8;
      int value = 1 << ((index2 % 8));
      list[index3] = list[index3] | value;
#ifdef DEBUG
      intTo2digit(list[index3], outBuff);
      printf("%02d:%d index3=%d value=%d after=%s \n", sieve, index2, index3, value, outBuff);
#endif
    }
  }


  for(int i = 0;i < booleanBytes - 1;i++) {
#ifdef DEBUG
    intTo2digit(list[i], outBuff);
    printf("[%d]:%s\n", i, outBuff);
#endif
    int value = list[i];
    for(int j = 0;j < 8;j++) {
      int index = 1 << j;
#ifdef DEBUG
      printf("%d - %d = %d\n", i * 8 + j, index, (value & index) != 0);
#endif
      if((value & index) == 0) {
        count++;
      }
    }
  }
#ifdef DEBUG
  printf("max = %ld booleanBytes*8 = %d\n", max, booleanBytes * 8);
#endif
  if(max > ((booleanBytes - 1) * 8)) {
    int loop = max - (booleanBytes - 1) * 8;
    int value = list[booleanBytes - 1];
    for(int j = 0;j < loop;j++) {
      int index = 1 << j;
#ifdef DEBUG
      printf("%d - %d = %d\n", (booleanBytes - 1) * 8 + j, index, (value & index) != 0);
#endif
      if((value & index) == 0) {
        count++;
      }
    }
  }
  free(list);
  printf("%ld primes\n", count);
  return 0;
}
