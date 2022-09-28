#include <stdio.h>

#define N 9

int main(void)
{

    // PSA --> prefix sum array

    // array esempio --> 6 6 4 8 -10 3 2 5 -3
    // PSA(V) --> 6 (=6) - 12(6+6) - 16(6+6+4) - 24(6+6+4+8) - 14 - 17 - 19 - 24 - 21

    // dato un array V di N elementi di tipo numerico (int)
    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d ", V[i]);
    // }

    printf("\n");

    int V2[N];

    // trasformare l'array in un array di somma prefissa basata su V
    int somma = 0;
    for (int i = 0; i < N; i++)
    {
        somma += V[i];
        V2[i] = somma;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", V2[i]);
    }

    return 0;
}