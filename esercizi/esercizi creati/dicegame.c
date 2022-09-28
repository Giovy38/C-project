#include <stdio.h>
#include <stdlib.h> // per numero random
#include <time.h>   // per numero random
#include <stdbool.h>
#include <unistd.h> // per pausa

short dice_roll_and_print()
{
    /*
     ----   ----
    |   |  |   |
    ----   ----
    */

    short dice1, dice2;
    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    short sum = dice1 + dice2;

    printf("-----  -----\n| %hu |  | %hu |\n-----  -----\n", dice1, dice2);

    return sum;
}

int main(void)
{

    /* Scrivete un programma che simuli il gioco CRAPS che viene fatto con due dadi.

    // Alla fine di ogni partita il programma dovrà chiedere all'utente se vuole giocare ancora.

    Nel caso in cui l'utente risponda diversamente da y o Y, il programma, prima di terminarsi, ,dovrà visualizzare il numero di vittorie o perdite. */

    short dice_sum = 0;
    short punto;
    short choice = 0; // ---> continua a giocare o meno (Y/N) --> 1 gioca 0 non gioca
    int n_vittorie = 0, n_sconfitte = 0;

    do
    {
        // ----- PRIMO LANCIO -------
        punto = 0;
        dice_sum = dice_roll_and_print();
        printf("la somma dei 2 dadi e': %hu\n\n", dice_sum);
        // Al primo lancio il giocatore vince se la somma dei dadi è 7 o 11.
        if (dice_sum == 7 || dice_sum == 11)
        {
            printf("Complimenti, hai vinto!\n");
            n_vittorie++;
        }
        else
        {
            // Il giocatore perde se la somma è 2, 3 oppure 12.
            if (dice_sum == 2 || dice_sum == 3 || dice_sum == 12)
            {
                printf("Mi dispiace, hai perso!\n");
                n_sconfitte++;
            }
            else
            {
                // Qualsiasi altra uscita viene chiamata il "punto" e il gioco continua.
                punto = dice_sum;
                printf("si continua con IL PUNTO, che vale: %hu\n", punto);
            }
        }

        // ----- IL PUNTO (SE NON VINCI AL PRIMO LANCIO) ---------

        while (punto != 0)
        {
            sleep(2); // metti in pausa per generare il numero random
            dice_sum = dice_roll_and_print();
            printf("la somma dei 2 dadi e': %hu\n\n", dice_sum);
            if (dice_sum == punto)
            {
                // Su tutte le giocate seguenti il giocatore vince se realizza nuovamente il "punto".
                printf("Complimenti, hai vinto!\n");
                n_vittorie++;
                punto = 0;
            }
            // Perde invece se ottine un 7.
            if (dice_sum == 7)
            {
                printf("Mi dispiace, hai perso!\n");
                n_sconfitte++;
                punto = 0;
            }
            // Qualsiasi altro valore viene ignorato e il gioco continua.
        }

        // -------- CONTINUA IL GIOCO --------------
        printf("vuoi giocare ancora? (1 si 0 no)\n\n");
        scanf("%hu", &choice);

        while (choice != 1 && choice != 0)
        {
            printf("inserisci un valore valido (1 si 0 no)");
            scanf("%hu", &choice);
        }

    } while (choice == 1);

    printf("Hai vinto %d volte\nHai perso: %d volte", n_vittorie, n_sconfitte);

    return 0;
}