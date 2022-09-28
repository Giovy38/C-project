#include <stdio.h>

int main(void)
{

    int h = 0;
    printf("inserire l'altezza: ");
    scanf("%d", &h);

    // asterisco
    char a = 42; //--> *

    int tronco = h / 3;
    int count = h;
    int z = count; //--> variabile per stampare gli spazi

    // stampa tronco
    int spacecounter = (h - 2);
    int ispace = 0;

    for (int itronco = 0; itronco < tronco; itronco++)
    {
        // stampa spazio
        while (ispace < spacecounter)
        {
            printf(" ");
            ispace++;
        }
        ispace = 0;
        printf("*\n");
    }

    for (int i = 0; i < h; i++)
    {
        // stampa spazio
        while (z < h)
        {
            printf(" ");
            z++;
        }
        z -= i + 1;

        // stampa 1 riga
        int y = 1;
        while (y < count)
        {
            printf("* ");
            y++;
        }
        count--;

        printf("\n");
    }

    return 0;
}