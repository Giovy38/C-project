#include <stdio.h>

// definire una funzione chiamata double_half che prende come parametri 4 numeri interi
void double_half(int *i, int *j, int *k, int *t)
{
    // la funzione dovrà dimezzare tutti i parametri con valore pari (pari / 2)
    if (*i % 2 == 0)
    {
        *i /= 2;
    }
    else
    {
        // e raddoppiare e sommare 1 a tutti i parametri con valore dispari (dispari * 2 + 1)
        *i = *i * 2 + 1;
    }

    if (*j % 2 == 0)
    {
        *j /= 2;
    }
    else
    {
        *j = *j * 2 + 1;
    }

    if (*k % 2 == 0)
    {
        *k /= 2;
    }
    else
    {
        *k = *k * 2 + 1;
    }

    if (*t % 2 == 0)
    {
        *t /= 2;
    }
    else
    {
        *t = *t * 2 + 1;
    }
}

int main(void)
{

    // int i=10, j=12, k=7, t=0;
    // double_half(&i, &j, &k, &t);
    // printf("%d %d %d %d ", i, j, k, t);

    // output --> 5 6 15 0

    int i = 10, j = 12, k = 7, t = 0;
    double_half(&i, &j, &k, &t);
    printf("%d %d %d %d ", i, j, k, t);

    return 0;
}