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

void print_tabellone(char *tabellone, char *tabellone2, char *tabellone3, char *tabellone4)
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

    // ----- divisore righe 1

    // printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // printf("| %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[11], tabellone[10], tabellone[9], tabellone[8], tabellone[7], tabellone[6], tabellone[5], tabellone[4], tabellone[3], tabellone[2], tabellone[1], tabellone[0]);
    // printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");

    for (int i = 11; i >= 0; i--)
    {
        printf(" -----");
    }
    printf("\n");

    for (int i = 11; i >= 0; i--)
    {
        printf("| %c%c |", tabellone[i], tabellone2[i]);
    }
    printf("\n");
    for (int i = 11; i >= 0; i--)
    {
        printf("| %c%c |", tabellone3[i], tabellone4[i]);
    }
    printf("\n");
    for (int i = 11; i >= 0; i--)
    {
        printf(" -----");
    }
    printf("\n");

    // ----- divisore righe V 2
    printf(" -----\n");
    printf("| %c%c |\n", tabellone[12], tabellone2[12]);
    printf("| %c%c |\n", tabellone3[12], tabellone4[12]);
    printf("-----\n");

    // ----- divisore righe V 3
    // printf(" ----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // printf("| %c |      | %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[13], tabellone[49], tabellone[48], tabellone[47], tabellone[46], tabellone[45], tabellone[44], tabellone[43], tabellone[42], tabellone[41], tabellone[40], tabellone[39]);
    // printf("----       ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");

    printf(" -----      ");
    for (int i = 49; i >= 39; i--)
    {
        printf(" -----");
    }
    printf("\n");

    printf("| %c%c |      ", tabellone[13], tabellone2[13]);
    // printf("| %c%c |", tabellone3[13], tabellone4[13]);
    for (int i = 49; i >= 39; i--)
    {
        printf("| %c%c |", tabellone[i], tabellone2[i]);
    }
    printf("\n");

    printf("| %c%c |      ", tabellone3[13], tabellone4[13]);
    for (int i = 49; i >= 39; i--)
    {
        printf("| %c%c |", tabellone3[i], tabellone4[i]);
    }
    printf("\n");
    printf(" -----      ");
    for (int i = 49; i >= 39; i--)
    {
        printf(" -----");
    }
    printf("\n");

    // ----- divisore righe V 4
    printf(" -----       -----                                                       -----\n");
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone[14], tabellone2[14], tabellone[50], tabellone2[50], tabellone[38], tabellone2[38]);
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone3[14], tabellone4[14], tabellone3[50], tabellone4[50], tabellone3[38], tabellone4[38]);
    printf("-----       -----                                                       -----\n");

    // ----- divisore righe V 5
    printf(" -----       -----                                                       -----\n");
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone[15], tabellone2[15], tabellone[51], tabellone2[51], tabellone[37], tabellone2[37]);
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone3[15], tabellone4[15], tabellone3[51], tabellone4[51], tabellone3[37], tabellone4[37]);
    printf("-----       -----                                                       -----\n");

    // ----- divisore righe V 6
    printf(" -----       -----                                                       -----\n");
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone[16], tabellone2[16], tabellone[52], tabellone2[52], tabellone[36], tabellone2[36]);
    printf("| %c%c |      | %c%c |                                                      | %c%c |\n", tabellone3[16], tabellone4[16], tabellone3[52], tabellone4[52], tabellone3[36], tabellone4[36]);

    printf("-----       -----                                                       -----\n");

    // ----- divisore righe V 7
    printf(" -----       -----                                    -----              -----\n");
    printf("| %c%c |      | %c%c |                                   | %c%c |             | %c%c |\n", tabellone[17], tabellone2[17], tabellone[53], tabellone2[53], tabellone[62], tabellone2[62], tabellone[35], tabellone2[35]);
    printf("| %c%c |      | %c%c |                                   | %c%c |             | %c%c |\n", tabellone3[17], tabellone4[17], tabellone3[53], tabellone4[53], tabellone3[62], tabellone4[62], tabellone3[35], tabellone4[35]);
    printf("-----       -----                                    -----              -----\n");

    // ----- divisore righe V 9
    // printf(" ----      ---- ---- ---- ---- ---- ---- ---- ----           ----\n");
    // printf("| %c |     | %c || %c || %c || %c || %c || %c || %c || %c |          | %c |\n", tabellone[18], tabellone[54], tabellone[55], tabellone[56], tabellone[57], tabellone[58], tabellone[59], tabellone[60], tabellone[61], tabellone[34]);
    // printf("----      ---- ---- ---- ---- ---- ---- ---- ----           ----\n");

    printf(" -----     ");
    for (int i = 54; i <= 61; i++)
    {
        printf(" -----");
    }
    printf("              -----");
    printf("\n");

    printf("| %c%c |     ", tabellone[18], tabellone2[18]);
    for (int i = 54; i <= 61; i++)
    {
        printf("| %c%c |", tabellone[i], tabellone2[i]);
    }
    printf("             | %c%c |\n", tabellone[34], tabellone2[34]);

    printf("| %c%c |     ", tabellone3[18], tabellone4[18]);
    for (int i = 54; i <= 61; i++)
    {
        printf("| %c%c |", tabellone3[i], tabellone4[i]);
    }
    printf("             | %c%c |\n", tabellone3[34], tabellone4[34]);

    printf(" -----     ");
    for (int i = 54; i <= 61; i++)
    {
        printf(" -----");
    }
    printf("              -----");
    printf("\n");

    // ----- divisore righe V 9
    printf(" -----                                                                   -----\n");
    printf("| %c%c |                                                                  | %c%c |\n", tabellone[19], tabellone2[19], tabellone[33], tabellone2[33]);
    printf("| %c%c |                                                                  | %c%c |\n", tabellone3[19], tabellone4[19], tabellone3[33], tabellone4[33]);

    printf("-----                                                                   -----\n");

    // ----- divisore righe V 10
    // printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
    // printf("| %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c || %c |\n", tabellone[20], tabellone[21], tabellone[22], tabellone[23], tabellone[24], tabellone[25], tabellone[26], tabellone[27], tabellone[28], tabellone[29], tabellone[30], tabellone[31], tabellone[32]);
    // printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");

    for (int i = 20; i <= 32; i++)
    {
        printf(" -----");
    }
    printf("\n");

    for (int i = 20; i <= 32; i++)
    {
        printf("| %c%c |", tabellone[i], tabellone2[i]);
    }
    printf("\n");
    for (int i = 20; i <= 32; i++)
    {
        printf("| %c%c |", tabellone3[i], tabellone4[i]);
    }
    printf("\n");

    for (int i = 20; i <= 32; i++)
    {
        printf(" -----");
    }
    printf("\n");

    // ----- divisore righe
}

short player_choice(char *players, short num_players, char emoji, short turn)
{

    for (int i = 0; i < num_players; i++)
    {
        players[i] = emoji + i;
    }

    turn = num_players;

    for (int i = 0; i < num_players; i++)
    {
        printf("Player%d: %c\n", i + 1, players[i]);
    }

    return turn;
}

void null_population(bool *turnover, short *player_position, char *tabellone, char *tabellone2, char *tabellone3, char *tabellone4, short num_players)
{
    for (int i = 0; i < num_players; i++)
    {
        turnover[i] = false;
    }

    for (int i = 0; i < num_players; i++)
    {
        player_position[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        tabellone[i] = ' ';
    }

    for (int i = 0; i < N; i++)
    {
        tabellone2[i] = ' ';
    }

    for (int i = 0; i < N; i++)
    {
        tabellone3[i] = ' ';
    }

    for (int i = 0; i < N; i++)
    {
        tabellone4[i] = ' ';
    }
}

void print_regole()
{
    printf("Regole:\n-Si inizia dal Player1 e si gioca a turni\n-Vince chi arriva alla casella finale con un lancio perfetto, ovvero si torna indietro se rimangono movimenti dal lancio ma il tabellone e' terminato\nLe caselle speciali sono:\n-CASELLE DELL'OCA\n(5, 9, 18, 27, 36, 45, 54): il giocatore che si muove su una casella dell'oca si muove di un numero di caselle pari a quelle di cui si e' appena spostato; la disposizione delle caselle dell'oca fa si' che se un giocatore, durante il primo turno, lancia un 9, vincera' la partita in una sola mossa\n-PONTE\n(6): si ripete il movimento\n-CASA\n(19): si rimane fermi per tre turni\n-LABIRINTO\n(42): si torna indietro alla casella 39\n-SCHELETRO\n(58): si torna alla casella 1\n\n");
}

void delete_moovment_player(char *tabellone, char *tabellone2, char *tabellone3, char *tabellone4, short *player_position, int i)
{
    if (tabellone[player_position[i]] == ' ' && tabellone2[player_position[i]] == ' ' && tabellone3[player_position[i]] == ' ')
    {
        tabellone4[player_position[i]] = ' ';
    }
    else
    {
        if (tabellone[player_position[i]] == ' ' && tabellone2[player_position[i]] == ' ')
        {
            tabellone3[player_position[i]] = ' ';
        }
        else
        {
            if (tabellone[player_position[i]] == ' ')
            {
                tabellone2[player_position[i]] = ' ';
            }
        }
    }

    tabellone[player_position[i]] = ' ';
}

int main(void)
{
    printf("vuoi vedere le regole? (1 si 0 no)");
    short regole = 0;
    scanf("%hu", &regole);
    while (regole != 0 && regole != 1)
    {
        printf("Inserisci un valore valido (1 si 0 no)");
        scanf("%hu", &regole);
    }

    if (regole == 1)
    {
        print_regole();
    }

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

    // ------- PLAYERS CHOICE -------
    turn = player_choice(players, num_players, emoji, turn);

    // -------INIZIO GIOCO ---------
    short player_position[num_players];
    bool turnover[num_players];
    char tabellone[N];
    char tabellone2[N];
    char tabellone3[N];
    char tabellone4[N];

    null_population(turnover, player_position, tabellone, tabellone2, tabellone3, tabellone4, num_players);

    // char more_player_same_place = 2; //---> faccina che rappresenta più giocatori sulla stessa casella
    short dice_sum = 0;
    short counter_turn = 0;

    // char transition_icon = ' ';

    // -----TURNI -------
    do
    {
        for (int i = 0; i < turn; i++)
        {
            printf("Turno del player%d\n", i + 1);
            sleep(2);
            if (turnover[i] == true)
            {
                dice_sum = 0;
                printf("Player%d, sei fermo per altri %d turni\n", i + 1, counter_turn);
                counter_turn--;
                if (counter_turn == 0)
                {
                    turnover[i] = false;
                    dice_sum = dice_roll_and_print();

                    delete_moovment_player(tabellone, tabellone2, tabellone3, tabellone4, player_position, i);

                    player_position[i] += dice_sum;
                }
            }
            else
            {
                dice_sum = dice_roll_and_print();
                delete_moovment_player(tabellone, tabellone2, tabellone3, tabellone4, player_position, i);

                player_position[i] += dice_sum;
            }

            // CASELLE DELL’OCA (5, 9, 18, 27, 36, 45, 54): il giocatore che si muove su una casella dell’oca si muove di un numero di caselle pari a quelle di cui si è appena spostato; la disposizione delle caselle dell’oca fa sì che se un giocatore, durante il primo turno, lancia un 9, vincerà la partita in una sola mossa;
            if (player_position[i] == 5 || player_position[i] == 9 || player_position[i] == 18 || player_position[i] == 27 || player_position[i] == 36 || player_position[i] == 45 || player_position[i] == 54)
            {
                if (player_position[i] == 9 && dice_sum == 9)
                {
                    player_position[i] = 62;
                }
                else
                {
                    player_position[i] += dice_sum;
                }
            }
            // PONTE (6): si ripete il movimento;
            if (player_position[i] == 6)
            {
                player_position[i] += dice_sum;
            }

            // CASA (19): si rimane fermi per tre turni;
            if (turnover[i] == false)
            {
                if (player_position[i] == 19)
                {
                    turnover[i] = true;
                    counter_turn = 3;
                    printf("Player%d, devi stare fermo per %d turni\n", i + 1, counter_turn);
                }
            }

            // PRIGIONE (31): si rimane fermi finché un altro giocatore non finisce sulla stessa casella;
            // POZZO (52): si rimane fermi finché un altro giocatore non finisce sulla stessa casella;

            // LABIRINTO (42): si torna indietro alla casella 39;
            if (player_position[i] == 42)
            {
                player_position[i] = 39;
                printf("Player%d, torni indietro alla casella 39", i + 1);
            }
            // SCHELETRO (58): si torna alla casella 1.
            if (player_position[i] == 58)
            {
                player_position[i] = 1;
                printf("Player%d, torni indietro alla casella 1", i + 1);
            }

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

            if (tabellone[player_position[i]] == ' ')
            {
                tabellone[player_position[i]] = players[i];
            }
            else
            {
                if (tabellone2[player_position[i]] == ' ')
                {
                    tabellone2[player_position[i]] = players[i];
                }
                else
                {
                    if (tabellone3[player_position[i]] == ' ')
                    {
                        tabellone3[player_position[i]] = players[i];
                    }
                    else
                    {
                        tabellone4[player_position[i]] = players[i];
                    }
                }
            }

            //     transition_icon = ' ';
            // }

            sleep(3);
            print_tabellone(tabellone, tabellone2, tabellone3, tabellone4);
            sleep(8);
            if (player_position[i] == N - 1)
            {
                printf("Player%d Wins!", i + 1);
                return 0;
            }
        }
    } while (tabellone[N - 1] == ' ');

    return 0;
}
