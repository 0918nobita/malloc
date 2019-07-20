#include<stdio.h>

int memory[20];
int used[20];

int *my_malloc(int size) {
  for (int i = 0; i < 20 - (size - 1); i ++) {
    if (used[i] == 0) {
      int not_used = 1;
      for (int k = 0; k < size; k++)
        if (used[i+k] == 1) not_used = 0;
      if (not_used == 1) {
        for (int k = 0; k < size; k++) used[i+k] = size - k;
        return memory + i;
      }
    }
  }
  return NULL;
}

void my_free(int *ptr) {
  int index = ptr - memory;
  int size = used[index];
  for (int i = 0; i < size; i++) used[i + index] = 0;
}

int main(void) {
  int *a = my_malloc(10);
  int *b = my_malloc(10);
  printf("a address = %p, b address = %p\n", a, b);
  my_free(a);
  int *c = my_malloc(10);
  printf("c address = %p\n", c);
  return 0;
}
