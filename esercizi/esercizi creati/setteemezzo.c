#include <stdio.h>
#include <stdlib.h> // per numero random
#include <time.h>   // per numero random
#include <stdbool.h>
#include <unistd.h> // per pausa

float card_generate()
{
    float card;
    srand(time(NULL));
    card = rand() % 10 + 1;
    if (card == 8 || card == 9 || card == 10)
    {
        card = 0.5;
    }

    return card;
}

int main(void)
{

    float banco = 0;
    float player = 0;
    float card = 0;
    short num_choice = 0;
    bool choice = false;
    short replay = 0;

    do
    {

        banco = 0;
        player = 0;
        card = 0;
        num_choice = 0;
        choice = false;

        // -----PLAYER TURN ------
        printf("\nPLAYER turn:\n");

        do
        {
            card = card_generate();
            printf("la tua carta : %.1f\n", card);
            player += card;
            if (player < 7.5)
            {
                printf("Il totale delle tue carte e' di: %.1f\n", player);
                printf("\nvuoi un'altra carta?(1 si 0 no)");
                scanf("%hu", &num_choice);
                while (num_choice != 1 && num_choice != 0)
                {
                    printf("inserisci un valore valido (1 si 0 no)");
                    scanf("%hu", &num_choice);
                }
                if (num_choice == 1)
                {
                    choice = true;
                }
                else
                {
                    choice = false;
                }
            }

            sleep(1);
        } while (choice && player < 7.5);

        if (player > 7.5)
        {
            printf("Il totale delle tue carte e' di: %.1f\nHai perso!", player);
            return 0;
        }

        // ----- COM TURN ------
        printf("\nCOM turn:\n");

        do
        {
            card = card_generate();

            banco += card;
            printf("Il totale delle carte del banco e' : %.1f\n", banco);
            sleep(1);

        } while (banco < player && banco < 7.5); // banco < player perché in caso di pareggio vince il banco

        if (player > 7.5)
        {
            printf("\nHai PERSO!Hai superato 7.5...Il banco vince!");
        }
        else
        {
            if (player > banco || banco > 7.5)
            {
                printf("\nHai VINTO!Il giocatore vince!\nCon %.1f batti %.1f", player, banco);
            }
            else
            {
                printf("\nHai PERSO!Il banco vince!\nCon %.1f batte %.1f", banco, player);
            }
        }

        printf("\nVuoi giocare ancora?(1 si 0 no)");
        scanf("%hu", &replay);
        while (replay != 1 && replay != 0)
        {
            printf("\nInserisci un valore valido (1 si 0 no)");
            scanf("%hu", &replay);
        }

    } while (replay == 1);

    return 0;
}