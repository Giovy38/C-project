#include <stdio.h>

int main(void)
{

    int s;
    printf("inserire il numero in secondi: ");
    scanf("%d", &s);

    // secondi / 60 per minuti
    // minuti / 60 per ore
    // secondi / 3600 per 1 ora

    // verifica durata 3h e 25m
    // 3h= 3600*3 + 60*25 ---> 10800 + 1500 = 12300

    printf("%d", s >= (3 * 3600 + 25 * 60));

    return 0;
}