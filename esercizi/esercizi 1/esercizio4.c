#include <stdio.h>

int main(void)
{

    unsigned int n;
    int p;
    int ris;

    printf("dammi n e p");
    scanf("%u%d", &n, &p);

    int i = 1;
    ris = n;
    while (i < p)
    {
        ris *= n;
        i++;
    }
    printf("%d", ris);

    return 0;
}