#include <stdio.h>

#define N 9

int main(void)
{

    // identificare e stampare in output i duplicati

    // esempio
    // Array V: 6 6 4 8 -10 3 2 8 3
    // output: duplicati: 6 8 3

    // dato un array V di N elementi di tipo T
    int V[N];

    // assegnazione valori array
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    int Duplicate[N];
    int k = 0;
    int value = 0;

    for (int i = 0; i < N; i++)
    {
        value = V[i];
        for (int j = i + 1; j < N; j++)
        {
            if (value == V[j])
            {
                Duplicate[k] = value;
                k++;
            }
        }
    }

    printf("Duplicati: ");
    if (k == 0)
    {
        printf("0, non ci sono numeri duplicati");
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", Duplicate[i]);
    }

    return 0;
}