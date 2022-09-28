#include <stdio.h>

int main(void)
{

    int n;
    printf("inserisci il numero:");
    scanf("%d", &n);

    int i = 0;
    int x = 0;

    do
    {
        x = i * i;
        printf("%d ", x);
        i++;
    } while (i <= n);

    return 0;
}