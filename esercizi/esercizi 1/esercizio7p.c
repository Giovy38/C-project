#include <stdio.h>

int main(void)
{

    int h = 0;
    printf("inserire l'altezza: ");
    scanf("%d", &h);

    char a = 42;

    int count = 2;
    int z = h;

    for (int i = 0; i < h; i++)
    {
        int y = 0;
        // ciclo per il tab

        while (z != 0)
        {
            printf("\t");
            z--;
        }
        while (y < count)
        {
            printf("%c", a);
            y++;
        }

        printf("\n");
        count += 2;
        z = h;
    }
    return 0;
}