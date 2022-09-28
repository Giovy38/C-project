#include <stdio.h>

#define N 9

int main(void)
{

    // esempio
    // array V --> 6(0) 6(1) 4(2) 8(3) -10(4) 3(5) 2(6) 8(7) 3(8)
    // K = -7
    // output : 4,5 -> -10+3= -7 || 4,8 -> -10+3=-7

    // dato un array V di N elementi di tipo numerico

    int V[N] = {6, 6, 4, 8, -10, 3, 2, 8, 3};

    // e un numero K

    int k = 0;
    int trovati = 0;
    printf("inserisci k come risultato somma di 2 elementi dell'array: ");
    scanf("%d", &k);

    // identificare e stampare gli indici (i,j) t.c. V[i] + V[j]
    for (int i = 0; i < N; i++)
    {
        int value = V[i];
        for (int j = i + 1; j < N; j++)
        {
            if (value + V[j] == k)
            {
                printf("posizione di i: %d (%d) + posizione di j: %d (%d) = k: %d\n", i, V[i], j, V[j], k);
                trovati++;
            }
        }
    }

    if (trovati == 0)
    {
        printf("non ci sono combinazioni disponibili per ottenere il risultato k= %d", k);
    }
    else
    {
        printf("sono state trovate %d possibili combinazioni", trovati);
    }

    return 0;
}