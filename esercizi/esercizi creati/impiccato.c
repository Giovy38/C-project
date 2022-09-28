#include <stdio.h>
#include <stdbool.h>

#define M 7

int main(void)
{

    int N = 60;
    int i = 0;
    char word_to_find[N];

    printf("inserisci la parola da indovinare seguita da un punto.(Es. cane --> cane.): ");
    char word;
    short word_counter = 0;
    short error = 0;
    bool found = false;
    short found_letters = 0;

    do
    {
        scanf("%c", &word);
        word_counter++;
        word_to_find[i] = word;
        i++;

    } while (word != '.');

    word_counter--;

    char try_word[word_counter];

    for (int i = 0; i < word_counter; i++)
    {
        try_word[i] = 95;
        printf("%c", try_word[i]);
    }
    printf("\n");

    char errors[M];

    for (int i = 0; i < M; i++)
    {
        errors[i] = 3;
    }

    do
    {
        char letter;
        printf("inserisci una lettera: ");
        scanf("\n%c", &letter);
        for (int i = 0; i < word_counter; i++)
        {
            if (letter == word_to_find[i])
            {
                found = true;
                try_word[i] = letter;
                found_letters++;
            }
        }
        if (found == true)
        {
            // ---- STAMPA ARRAY DI PROVA PAROLA -------
            for (int i = 0; i < word_counter; i++)
            {
                printf("%c", try_word[i]);
            }
            printf("\n");
            // ------- STAMPA VITE -------
            printf("vite disponibili: ");
            for (int i = 0; i < (M - error); i++)
            {
                printf("%c", errors[i]);
            }

            printf("\n");
        }

        if (found == false)
        {
            printf("La lettera inserita non corrisponde...\n");
            printf("vite disponibili: ");
            error++;
            for (int i = 0; i < (M - error); i++)
            {
                printf("%c", errors[i]);
            }
            printf("\n");
        }
        found = false;

    } while (error < M && found_letters != word_counter);

    if (error == M)
    {
        printf("Mi dispiace, Hai perso!");
    }
    else
    {
        printf("Complimenti, Hai vinto!");
    }

    return 0;
}