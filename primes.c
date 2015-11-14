#include <stdio.h>
#include <stdlib.h>

typedef short int bool;

long primes[100000];
long primeCount = 0;

long hasPrime(long num)
{
  for(long j = 0;j < primeCount;j++) {
    if(num % primes[j] == 0) {
      return primes[j];
    }
  }
  return 0;
}

// 2 3 5 7....
int main(int argc, char* argv[])
{
  if(argc < 2) {
    printf("arg error");
    return 1;
  }

  long max = atoi(argv[1]);
  
  printf("Max = %ld\n", max);
  long foundNum = 1;
  primes[0] = 2;
  primeCount = 1;
  for(long i = 3;i < max;i += 2) {
    if(!hasPrime(i)) {
      primes[primeCount] = i;
      primeCount++;
      foundNum++;
    }
  }
  printf("%ld primes\n", foundNum);

  return 0;
}
