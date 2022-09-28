#include <stdio.h>

int main(void)
{

    int x = 0, y = 0;
    char direction;

    printf("(%d,%d)\n", x, y);

    while (!(x == 19 && y == 19))
    {
        scanf("\n%c", &direction);

        // SU
        if (direction == 'w' || direction == 'W')
        {
            if (y < 20)
            {
                y++;
                printf("(%d,%d)\n", x, y);
            }
            else
            {
                printf("(%d,%d) non posso andare piu' su'\n", x, y);
            }
        }
        // GIU

        if (direction == 's' || direction == 'S')
        {
            if (y > 0)
            {
                y--;
                printf("(%d,%d)\n", x, y);
            }
            else
            {
                printf("(%d,%d) non posso andare piu' giu'\n", x, y);
            }
        }

        // DX

        if (direction == 'd' || direction == 'D')
        {
            if (x < 20)
            {
                x++;
                printf("(%d,%d)\n", x, y);
            }
            else
            {
                printf("(%d,%d) non posso andare piu' a destra\n", x, y);
            }
        }

        // SX

        if (direction == 'a' || direction == 'A')
        {
            if (x > 0)
            {
                x--;
                printf("(%d,%d)\n", x, y);
            }
            else
            {
                printf("(%d,%d) non posso andare piu' a sinistra\n", x, y);
            }
        }
    }

    return 0;
}