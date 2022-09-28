#include <stdio.h>

#define N 9

int main(void)
{

    // esempio
    // array V: 6 6 4 8 -10 3 2 8 -7 --> -10 * -7 = 70
    // array V: 5 2 -4 7 10 -3 3 8 7 --> 10 * 8 = 80

    // dato un array V di N elementi di tipo numerico
    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // identificare e stampare gli elementi p,q in V cha hanno prodotto massimo
    int max1 = V[0], max2 = V[1];
    int imax1 = 0, imax2 = 1;
    int min1 = V[0], min2 = V[1];
    int imin1 = 0, imin2 = 1;

    // ------ NUMERO MAGGIORE --------
    for (int i = 2; i < N; i++)
    {
        // portiamo il più grande in prima posizione
        int swipemax = 0;
        if (max1 < max2)
        {
            swipemax = max2;
            max2 = max1;
            max1 = swipemax;
            imax1 = 1;
            imax2 = 0;
        }

        if (V[i] > max1 || V[i] > max2)
        {
            if (V[i] > max1)
            {
                max1 = V[i];
                imax1 = i;
            }
            else
            {
                max2 = V[i];
                imax2 = i;
            }
        }
    }

    // ------ NUMERO MINORE -------
    for (int i = 2; i < N; i++)
    {
        // portiamo il più grande in prima posizione
        int swipemin = 0;
        if (min1 > min2)
        {
            swipemin = min2;
            min2 = min1;
            min1 = swipemin;
            imin1 = 1;
            imin2 = 0;
        }

        if (V[i] < min1 || V[i] < min2)
        {
            if (V[i] < min1)
            {
                min1 = V[i];
                imin1 = i;
            }
            else
            {
                min2 = V[i];
                imin2 = i;
            }
        }
    }

    // // stampa dei 2 numeri maggiori

    // printf("primo maggiore: %d[%d] secondo maggiore: %d[%d] --> %d\n", max1, imax1, max2, imax2, max1 * max2);

    // // stampa dei 2 numeri minori

    // printf("primo minore: %d[%d] secondo minore: %d[%d] --> %d\n", min1, imin1, min2, imin2, min1 * min2);

    // print the max product of 2 numbers possible
    int p = 0, q = 0;

    p = max1 * max2;
    q = min1 * min2;

    if (p == q)
    {
        printf("il numero piu' alto e' %d ottenuto da: \n", p);
        printf("%d[%d] * %d[%d] e ", max1, imax1, max2, imax2);
        printf("%d[%d] * %d[%d]", min1, imin1, min2, imin2);
    }
    else
    {
        if (p > q)
        {
            printf("il numero piu' alto e' %d ottenuto da %d[%d] * %d[%d]", p, max1, imax1, max2, imax2);
        }
        else
        {
            printf("il numero piu' alto e' %d ottenuto da %d[%d] * %d[%d]", q, min1, imin1, min2, imin2);
        }
    }

    return 0;
}