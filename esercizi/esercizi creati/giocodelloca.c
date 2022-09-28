#include <stdio.h>
#include <stdlib.h> // per numero random
#include <time.h>   // per numero random
#include <unistd.h> // per pausa
#include <stdbool.h>

#define N 63

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

    printf("I tuoi dadi:\n");
    printf("-----  -----\n| %hu |  | %hu |\n-----  -----\n", dice1, dice2);
    printf("\n\n");

    return sum;
}

void print_tabellone(char *tabellone)
{
    /*
     ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    |   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   || 1 |
    ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
     ----
    |   |
    ----
     ----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    |   |      |   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |
    ----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
     ----      ----                                              ----
    |   |     |   |                                             |   |
    ----      ----                                              ----
     ----      ----                                              ----
    |   |     |   |                                             |   |
    ----      ----                                              ----
     ----      ----                                              ----
    |   |     |   |                                             |   |
    ----      ----                                              ----
     ----      ----                                ----          ----
    |   |     |   |                               | F |         |   |
    ----      ----                                ----          ----
     ----      ---- ---- ---- ---- ---- ---- ---- ----           ----
    |   |     |   ||   ||   ||   ||   ||   ||   ||   |          |   |
    ----      ---- ---- ---- ---- ---- ---- ---- ----           ----
     ----                                                        ----
    |   |                                                       |   |
    ----                                                        ----
     ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    |   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   |
    ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    */

    // ---------POPOLAMENTO E STAMPA TABELLONE ----------

    printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    printf("| %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[11], tabellone[10], tabellone[9], tabellone[8], tabellone[7], tabellone[6], tabellone[5], tabellone[4], tabellone[3], tabellone[2], tabellone[1], tabellone[0]);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // ----- divisore righe
    printf(" ----\n");
    printf("| %c |\n", tabellone[12]);
    printf("----\n");
    // ----- divisore righe
    printf(" ----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    printf("| %c |      | %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[13], tabellone[49], tabellone[48], tabellone[47], tabellone[46], tabellone[45], tabellone[44], tabellone[43], tabellone[42], tabellone[41], tabellone[40], tabellone[39]);
    printf("----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // ----- divisore righe
    printf(" ----      ----                                              ----\n");
    printf("| %c |     | %c |                                             | %c |\n", tabellone[14], tabellone[50], tabellone[38]);
    printf("----      ----                                              ----\n");
    // ----- divisore righe
    printf(" ----      ----                                              ----\n");
    printf("| %c |     | %c |                                             | %c |\n", tabellone[15], tabellone[51], tabellone[37]);
    printf("----      ----                                              ----\n");
    // ----- divisore righe
    printf(" ----      ----                                              ----\n");
    printf("| %c |     | %c |                                             | %c |\n", tabellone[16], tabellone[52], tabellone[36]);
    printf("----      ----                                              ----\n");
    // ----- divisore righe
    printf(" ----      ----                                ----          ----\n");
    printf("| %c |     | %c |                               | %c |         | %c |\n", tabellone[17], tabellone[53], tabellone[62], tabellone[35]);
    printf("----      ----                                ----          ----\n");
    // ----- divisore righe
    printf(" ----      ---- ---- ---- ---- ---- ---- ---- ----           ----\n");
    printf("| %c |     | %c || %c || %c || %c || %c || %c || %c || %c |          | %c |\n", tabellone[18], tabellone[54], tabellone[55], tabellone[56], tabellone[57], tabellone[58], tabellone[59], tabellone[60], tabellone[61], tabellone[34]);
    printf("----      ---- ---- ---- ---- ---- ---- ---- ----           ----\n");
    // ----- divisore righe
    printf(" ----                                                        ----\n");
    printf("| %c |                                                       | %c |\n", tabellone[19], tabellone[33]);
    printf("----                                                        ----\n");
    // ----- divisore righe
    printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    printf("| %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[20], tabellone[21], tabellone[22], tabellone[23], tabellone[24], tabellone[25], tabellone[26], tabellone[27], tabellone[28], tabellone[29], tabellone[30], tabellone[31], tabellone[32]);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // ----- divisore righe
}

int main(void)
{

    // 63 caselle totali
    // CASELLE DELL’OCA (5, 9, 18, 27, 36, 45, 54): il giocatore che si muove su una casella dell’oca si muove di un numero di caselle pari a quelle di cui si è appena spostato; la disposizione delle caselle dell’oca fa sì che se un giocatore, durante il primo turno, lancia un 9, vincerà la partita in una sola mossa;
    // PONTE (6): si ripete il movimento;
    // CASA (19): si rimane fermi per tre turni;
    // PRIGIONE (31): si rimane fermi finché un altro giocatore non finisce sulla stessa casella;
    // POZZO (52): si rimane fermi finché un altro giocatore non finisce sulla stessa casella;
    // LABIRINTO (42): si torna indietro alla casella 39;
    // SCHELETRO (58): si torna alla casella 1.

    // ----SELEZIONE NUMERO PLAYER ----
    short turn = 0;
    short num_players = 0;
    printf("Seleziona il numero di giocatori (da 2 a 4 giocatori):");
    scanf("%hu", &num_players);
    while (num_players < 2 || num_players > 4)
    {
        printf("Inserisci un valore valido (da 2 a 4 giocatori):");
        scanf("%hu", &num_players);
    }

    char players[num_players];
    char emoji = 3;

    // ------- 2 PLAYERS -------
    if (num_players == 2)
    {
        for (int i = 0; i < num_players; i++)
        {
            players[i] = emoji + i;
        }

        turn = 2;

        for (int i = 0; i < num_players; i++)
        {
            printf("Player%d: %c\n", i + 1, players[i]);
        }
    }

    // ------- 3 PLAYERS -------
    if (num_players == 3)
    {
        for (int i = 0; i < num_players; i++)
        {
            players[i] = emoji + i;
        }

        turn = 3;

        for (int i = 0; i < num_players; i++)
        {
            printf("Player%d: %c\n", i + 1, players[i]);
        }
    }
    // ------- 4 PLAYERS -------
    if (num_players == 4)
    {
        for (int i = 0; i < num_players; i++)
        {
            players[i] = emoji + i;
        }

        turn = 4;

        for (int i = 0; i < num_players; i++)
        {
            printf("Player%d: %c\n", i + 1, players[i]);
        }
    }

    // -------INIZIO GIOCO ---------
    short player_position[num_players];

    for (int i = 0; i < num_players; i++)
    {
        player_position[i] = 0;
    }

    char tabellone[N];
    for (int i = 0; i < N; i++)
    {
        tabellone[i] = ' ';
    }

    // char more_player_same_place = 2; //---> faccina che rappresenta più giocatori sulla stessa casella
    short dice_sum = 0;
    // char transition_icon = ' ';

    // -----TURNI -------
    do
    {
        for (int i = 0; i < turn; i++)
        {
            printf("Turno del player%d\n", i + 1);
            sleep(2);
            dice_sum = dice_roll_and_print();
            tabellone[player_position[i]] = ' ';
            player_position[i] += dice_sum;
            if (player_position[i] > N)
            {
                short difference = 0;
                difference = player_position[i] - N;
                player_position[i] = N - difference;
            }
            // if (tabellone[player_position[i]] != ' ')
            // {
            //     transition_icon = players[i];
            //     tabellone[player_position[i]] = more_player_same_place;
            // }
            // else
            // {
            tabellone[player_position[i]] = players[i];
            //     transition_icon = ' ';
            // }

            sleep(3);
            print_tabellone(tabellone);
            if (player_position[i] == N - 1)
            {
                printf("Player%d Wins!", i + 1);
                return 0;
            }
        }
    } while (tabellone[N - 1] == ' ');

    return 0;
}