#include <stdio.h>

#define N 7

int main(void)
{

    // esempio:
    // V before: 6 6 4 8 10 3 11
    // V after: 11 3 10 8 4 6 6

    // dato un array V di N elementi di tipo T
    int V[N];

    // assegnazione valori
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // stampa array originale
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d ", V[i]);
    // }
    // printf("\n");

    // invertire V in loco (senza un secondo array)
    int x = 0;
    for (int i = 0; i < N / 2; i++)
    {
        x = V[i];
        V[i] = V[N - 1 - i];
        V[N - 1 - i] = x;
    }

    // STAMPA ARRAY
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }

    return 0;
}