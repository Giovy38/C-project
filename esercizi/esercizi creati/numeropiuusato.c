#include <stdio.h>

#define N 10

int main(void)
{

    // qual'ora ci siano più numeri che compaiono lo stesso numero di volte, stampare il maggiore

    // leggere un array di interi di 10 posizioni
    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // e stampare il numero che compare più volte all'interno dell'array

    int attuale = 0;
    int nv_attuale = 0;
    int maggiore = V[0];
    int nv_maggiore = 0;

    for (int i = 0; i < N; i++)
    {
        attuale = V[i];
        nv_attuale = 0;
        for (int j = 0; j < N; j++)
        {
            if (V[i] == V[j])
            {
                nv_attuale++;
            }
            if (nv_attuale > nv_maggiore)
            {
                maggiore = attuale;
                nv_maggiore = nv_attuale;
            }
        }
    }

    printf("il numero che compare piu' volte e' %d ", maggiore);
    printf("e compare %d volte", nv_maggiore);

    return 0;
}