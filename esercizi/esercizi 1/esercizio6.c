#include <stdio.h>

int main(void)
{

    int n;
    printf("inserire n:");
    scanf("%d", &n);

    int i = 0;
    int numero = n;
    int numcifre = 1;

    if (n == 0)
    {
        numcifre = 1;
    }
    else
    {
        if (n > 0)
        {
            while (n >= 10)
            {
                n /= 10;
                numcifre++;
                i++;
            }
        }
        else
        {
            numcifre = 0;
            while (n < 0)
            {
                n /= 10;
                numcifre++;
                i++;
            }
        }
    }

    printf("N: %d\nNumero cifre:%d\nOrdine ", numero, numcifre);
    if (numcifre == 1)
    {
        printf("delle unita'");
    }
    if (numcifre == 2)
    {
        printf("delle decine");
    }
    if (numcifre == 3)
    {
        printf("delle centinaia");
    }
    if (numcifre == 4)
    {
        printf("delle migliaia");
    }
    if (numcifre == 5)
    {
        printf("dei milioni");
    }
    if (numcifre == 6)
    {
        printf("dei miliardi");
    }

    return 0;
}