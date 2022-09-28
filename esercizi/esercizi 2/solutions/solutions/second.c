#include <stdio.h>

int main() {
  char letter;
  int vowels = 0, consonants = 0;
  printf("Insert a single lowercase character: ");

  do {
    char useless;
    scanf("%c", &letter);
    scanf("%c", &useless);

    printf("Letter: [%c]\n", letter);
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
      vowels++;
    } else {
      consonants++;
    }
  } while (letter != '-');

  printf("Vowels: %d\nConsonants: %d\n", vowels, consonants - 1);
  return 0;
}