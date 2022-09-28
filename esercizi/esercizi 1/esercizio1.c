#include <stdio.h>

int main(void)
{

    int cel;
    printf("inserisci la temperatura in gradi celsius: ");
    scanf("%d", &cel);

    float far;
    far = (1.8 * cel) + 32;
    printf("i gradi in fahrenheit sono: %.1f", far);

    return 0;
}