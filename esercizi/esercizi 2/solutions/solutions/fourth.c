#include <stdio.h>

int main () {
  int h;
  scanf("%d", &h);

  for(int i = 0; i < h / 3; i++) {
    for(int j = 0; j < h - 1; j++) {
      printf(" ");
    }
    printf("*\n");
  }

  for(int i = h; i >= 0; i--) {
    for(int j = 0; j < h - i; j++) {
      printf(" ");
    }
    for(int j = 0; j < i; j++) {
      printf("* ");
    }

    printf("\n");
  }
  return 0; 
}