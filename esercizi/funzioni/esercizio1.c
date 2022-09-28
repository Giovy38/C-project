#include <stdio.h>

// 1) definire una funzione che restituisce a^b senza utilizzare la funzione power
int potenza(int base, int esponente)
{
    int risult = 1;
    for (int i = 0; i < esponente; i++)
    {
        risult *= base;
    }
    return risult;
}

// 2) definire una funzione che se a>b restituisce 2*b altrimenti 3*a-b
void max_operation(int a, int b)
{
    int risult = 0;
    if (a > b)
    {
        risult = 2 * b;
        printf("a>b, risultato(2*b) --> 2*(%d)= %d\n", b, risult);
    }
    else
    {
        risult = 3 * a - b;
        printf("a<b, risultato(3*a-b) --> 3*%d-%d= %d\n", a, b, risult);
    }
}

// 3) definire una funzione che restituisce la distanza tra i 2 numeri |a-b| (valore assoluto differenza)
int distance(int a, int b)
{
    int dist = 0;
    if (b > a)
    {
        for (int i = a + 1; i < b; i++)
        {
            dist++;
        }
    }
    else
    {
        for (int i = b + 1; i < a; i++)
        {
            dist++;
        }
    }

    return dist;
}

int main(void)
{

    // dati a,b interi in input
    int a, b;
    int dist = 0;
    scanf("%d%d", &a, &b);

    printf("la potenza di %d^%d e': %d\n", a, b, potenza(a, b));
    max_operation(a, b);

    dist = distance(a, b);
    printf("la distanza tra a(%d) e b(%d) e' di: %d", a, b, dist);

    return 0;
}