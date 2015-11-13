#include <stdio.h>
#include <stdlib.h>

struct linkNode {
    int value;
    struct linkNode *next;
};

// 2 3 5 7....
int main(int argc, char* argv[])
{
  if(argc < 2) {
    printf("arg error");
    return 1;
  }
  long max = atoi(argv[1]);
  
  printf("Max = %ld\n", max);
  struct linkNode *start;
  struct linkNode *current;
  start = (struct linkNode *)malloc(sizeof(struct linkNode));
  current = start;

  for(int i = 0;i < max;i++) {
    current->next = (struct linkNode *)malloc(sizeof(struct linkNode));
    current->next->next = NULL;
    current->value = i + 1;
    current = current->next;
  }
  current = start;
  while(1) {
    if(current->next == NULL) {
      break;
    } else {
      printf("%d\n", current->value);
      current = current->next;
    }
  }
  return 0;
}
