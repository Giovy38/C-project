#include <stdio.h>
#include <stdbool.h>

int main() {
  int first, second;
  printf("Insert a number to start: ");
  scanf("%d", &first);

  printf("Keep inserting the sequence, looping until monotone: \n");

  // Determining the character of the sequence
  int behaviour = 0;
  do {
    scanf("%d", &second);

    printf("first: %d, second: %d, behaviour: %d\n", first, second, behaviour);
    // behaviour of the sequence
    // 1 is increasing
    // -1 is decreasing
    // 0 stationary

    if (second > first) {
      behaviour = 1;
    }

    if (second < first) {
      behaviour = -1;
    }
  } while (behaviour == 0);

  bool isMonotone = true;
  do {
    first = second;

    scanf("%d", &second);

    if(behaviour == 1) {
      // Is increasing
      isMonotone = second >= first;
    } else {
      // Is decreasing
      isMonotone = second <= first;
    }
    
    printf("first: %d, second: %d, behaviour: %d, isMonotone: %d\n", first, second, behaviour, isMonotone);
  } while(isMonotone);

  return 0;
}