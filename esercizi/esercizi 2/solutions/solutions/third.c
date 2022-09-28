#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
  char choice;
  int x = 0, y = 0;

  do
  {
    scanf("%c", &choice);
    getchar();
    if (choice == 'W')
    {
      if (y < HEIGHT - 1)
        y++;
    }

    if (choice == 'A')
    {
      if (x > 0)
        x--;
    }

    if (choice == 'S')
    {
      if (y > 0)
        y--;
    }

    if (choice == 'D')
    {
      if (x < WIDTH - 1)
      {
        x++;
      }
    }

    printf("Current position: (%d, %d)\n", x, y);
  } while (x != WIDTH - 1 || y != WIDTH - 1);

  // Sono arrivato se x == 19 and y == 19
  printf("You won!");

  return 0;
}