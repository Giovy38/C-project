#include <stdio.h>

int main(void)
{

    int s;
    printf("inserire il numero in secondi: "),
        scanf("%d", &s);

    // secondi / 60 per minuti
    // minuti / 60 per ore
    // secondi / 3600 per 1 ora

    // verifica durata 3h e 25m
    // 3h= 3600*3 + 60*25 ---> 10800 + 1500 = 12300

    int h, m;

    h = 0;
    m = 0;

    while (s > 60)
    {
        m = s / 60;
        h = m / 60;
        s = s % 60;
        m = m % 60;
    }
    printf("%d ore %d minuti %d secondi", h, m, s);

    return 0;
}