/*  Esercizio 1:
    Inserire 5 valori interi non negativi e ne disegna l'istogramma
    a barre verticali come mostrato nel seguente esempio.
    Nel caso di inserimento di valori negativi il programma deve terminare
    con un messaggio di errore.
    Esempio:
     5       *
     4     * *
     3     * *
     2     * * *
     1   * * * * *
         1 4 5 2 1
*/

#include <stdio.h>
#define DIM 5

void disegna(int vet[], int max)
{
    while (max > 0)
    {
        for (int i = 0; i < DIM; i++)
        {
            if (vet[i] >= max)
            {
                printf("%c ", '*');
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
        max--;
    }
}

int main()
{
    int lista[DIM];
    int max = 0;

    for (int i = 0; i < DIM; i++) // caricamento vettore
    {
        printf("Inserisci il %d valore intero: ", i + 1);
        scanf("%d", &lista[i]);

        if (lista[i] < 0) // controllo elemento negativo
        {
            puts("Errore, elemento negativo. (devi inserire un numero intero positivo");
            return 0;
        }

        if (lista[i] > max)
        {
            max = lista[i];
        }
    }

    disegna(lista, max);

    return 0;
}