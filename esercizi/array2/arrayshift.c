#include <stdio.h>
#include <stdbool.h>

#define N 9
int main(void)
{

    // esempio
    // array V, K=2
    // 6 6 4 8 -10 3 2 8 -7
    // 8 -7 6 6 4 8 -10 3 2

    // dato un array V di N elementi di tipo T
    int V[N];

    // ----- INSERIMENTO DATI IN ARRAY --------
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // e un numero K
    int K = 0;
    printf("inserisci il valore di K: ");

    do
    {
        bool validK = (K < N);
        if (!validK)
        {
            printf("Attenzione non puoi inserire K > N!\ninserisci il valore di K: ");
        }
        scanf("%d", &K);
    } while (K > N);

    // shiftare (translare) tutti gli elementi di K verso destra

    // int translate_item;

    int last_item;
    for (int i = 0; i < K; i++)
    {
        last_item = V[N - 1];
        for (int index = 1; index < N; index++)
        {
            // translate_item = V[N - index];
            V[N - index] = V[N - index - 1];
        }
        V[0] = last_item;
    }

    // ------ STAMPA ARRAY --------
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }

    return 0;
}