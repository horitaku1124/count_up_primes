#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct linkNode {
    int value;
    struct linkNode *next;
};

void printAllNodes(struct linkNode *start)
{
  struct linkNode *current = start;
  while(1) {
    if(current->next == NULL) {
      break;
    } else {
      printf("%d\n", current->value);
      current = current->next;
    }
  }
}
long countAllNodes(struct linkNode *start)
{
  long num = 0;
  struct linkNode *current = start;
  while(1) {
    if(current->next == NULL) {
      break;
    } else {
      current = current->next;
      num++;
    }
  }
  return num;
}

void freeAllNodes(struct linkNode *start)
{
  struct linkNode *current = start;
  while(1) {
    if(current->next == NULL) {
      break;
    } else {
      struct linkNode *old = current;
      current = current->next;
      free(old);
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
  long max = atoi(argv[1]);
  int end = ceil(sqrt(max));
  
  printf("Max = %ld End = %d \n", max, end);
  struct linkNode *start;
  struct linkNode *current;
  start = (struct linkNode *)malloc(sizeof(struct linkNode));
  current = start;

  current->next = (struct linkNode *)malloc(sizeof(struct linkNode));
  current->next->next = NULL;
  current->value = 2;
  current = current->next;

  for(int i = 2;i < max;i += 2) {
    current->next = (struct linkNode *)malloc(sizeof(struct linkNode));
    current->next->next = NULL;
    current->value = i + 1;
    current = current->next;
  }
  current = start;

  while(1) {
    if(current->next == NULL || current->next->value == 0) {
      break;
    } 
    int num = current->value;
    // printf("N = %d\n", num);

    struct linkNode *seek = current;
    while(1) {
      // printf("seek.value = %d\n", seek->value);
      if(seek->next == NULL || seek->next->value == 0) {
        break;
      }
      if(seek->next->value % num == 0) {
          // printf("seek.next.value = %d\n", seek->next->value);
          struct linkNode *old = seek->next;
          seek->next = seek->next->next;
          free(old);
      }
      seek = seek->next;
      if(seek == NULL) {
        break;
      }
    }
    current = current->next;
  }
  printf("%ld primes\n", countAllNodes(start));

  freeAllNodes(start);
  return 0;
}
