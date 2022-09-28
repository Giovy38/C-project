#include <stdio.h>

#define N 9

int main(void)
{

    // SOMMA IN RANGE

    // Array esempio: 6 6 4 8 | -10 3 2 5 | -3
    // input: i=4 j=7
    // output: S(i,j) --> S(4,7) --> v[4] + v[5] + v[6] + v[7] --> -10 + 3 + 2 + 5 = 0

    // dato un array V di N elementi di tipo numerico T (int)
    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    // calcola la somma S(i,j) di un intervallo chiuso [i,j] di V
    int i = 0, j = 0;

    do
    {
        printf("inserisci i e j come numeri di intervallo, i(primo numero) j (ultimo numero)\n");
        scanf("%d%d", &i, &j);
        if (j > N - 1)
        {
            printf("j non puo' avere valore superiore alla lunghezza dell'array che e' di %d\n", N - 1);
        }
        if (i < 0)
        {
            printf("i non puo' essere un valore inferiore a 0\n");
        }
    } while (i < 0 || j > N);

    int somma = 0;
    for (int index = i; index <= j; index++)
    {
        somma += V[index];
    }
    printf("la somma dell'intervallo (i,j) dove i=%d e j=%d e': %d", i, j, somma);

    return 0;
}