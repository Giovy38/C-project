#include <stdio.h>

#define N 9

int main(void)
{

    // e a sx tutti gli elementi pari
    // esempio
    // array V : 6 5 4 7 -10 3 2 8 -7
    // array v aggregato: 6 4 -10 2 8 | 5 7 3 -7

    // dato un array V di N elementi di tioi INT
    int V[N];

    // ----- RIEMPIMENTO ARRAY ------
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // portare a dx tutti gli elementi dispari
    int last_item;

    // se il numero è pari, passa alla i successiva
    for (int i = 0; i < N; i++)
    {
        int control = 0;
        while (V[i] % 2 != 0 && control < N)
        {
            last_item = V[i];
            for (int j = i; j < N; j++)
            {
                V[j] = V[j + 1];
            }

            V[N - 1] = last_item;
            control++;
        }
    }

    // ------ STAMPA ARRAY --------
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }

    return 0;
}