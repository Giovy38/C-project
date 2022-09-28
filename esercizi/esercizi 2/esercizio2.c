#include <stdio.h>

int main(void)
{

    char x = 0;
    scanf("%c", &x);

    int vocali = 0, consonanti = 0;

    while (x != 45)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        {
            vocali++;
        }
        else
        {
            consonanti++;
        }
        scanf("\n%c", &x);
    }
    printf("Vocali: %d\nConsonanti: %d", vocali, consonanti);

    return 0;
}