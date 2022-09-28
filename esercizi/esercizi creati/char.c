#include <stdio.h>

int main(void)
{

    // calcola lunghezza media in una frase
    // ferma con .
    // non contare gli spazi

    // it was deja vu all over again. --> Average word lenght: 3.4

    char frase;
    printf("inserisci la frase: ");
    // scanf("%c", &frase);

    float lenght = 0; // --> sum/n_word
    float n_word = 0, sum = 0;

    do
    {
        do
        {
            scanf("%c", &frase);
            sum++;
        } while (frase != ' ' && frase != '.');
        n_word++;
        sum--;

        while (frase == ' ')
        {
            scanf("%c", &frase);
        }
        sum++;
    } while (frase != '.');

    lenght = sum / n_word;
    printf("Average word lenght: %.1f", lenght);

    return 0;
}