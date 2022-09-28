#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool iswin(char *position, short N, short R)
{
    bool winner = false;
    char empty_space = ' ';

    // --------CONTROLLO ORIZZONTALE
    // 012
    // 345
    // 678
    for (int i = 0; i < N; i = i + R)
    {
        for (int j = 0; j < R; j++)
        {
            if (position[i] == position[i + 1] && position[i] == position[i + 2] && position[i] != empty_space)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
        }
        if (winner)
        {
            return winner;
        }
    }

    // --------CONTROLLO VERTICALE
    // 036
    // 147
    // 258
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (position[i] == position[i + R] && position[i] == position[i + R + R] && position[i] != empty_space)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
        }
        if (winner)
        {
            return winner;
        }
    }

    // --------CONTROLLO OBLIQUO
    // 048
    // 246
    for (int i = 0; i < N; i++)
    {
        int tr = R + 1; // ---> temporany R (048)
        for (int j = 0; j < R; j++)
        {
            if (position[i] == position[i + tr] && position[i] == position[i + tr + tr] && position[i] != empty_space)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
        }
        if (winner)
        {
            return winner;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int trn = R - 1; // ---> temporany R (246)
        for (int j = 0; j < R; j++)
        {
            if (position[i] == position[i + trn] && position[i] == position[i + trn + trn] && position[i] != empty_space)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
        }
        if (winner)
        {
            return winner;
        }
    }

    return winner;
}

// --------- STAMPA RIGA DI SEPARAZIONE ----------

void separation_of_turn()
{
    printf("-----------\n");
}

// --------- STAMPA RIGA ORIZONTALE ----------

void orizzontal_line(short R)
{
    int count = 0;
    for (int i = 0; i < R; i++)
    {
        if (count < (R - 1))
        {
            printf("---|");
            count++;
        }
        else
        {
            printf("---");
        }
    }

    printf("\n");
}

// --------- STAMPA CAMPO DA GIOCO ----------

void print(char *position, short N, short R)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (count < R)
        {
            if (count < (R - 1))
            {
                printf(" %c |", position[i]);
                count++;
            }
            else
            {
                printf(" %c ", position[i]);
                count++;
            }
        }
        else
        {
            printf("\n");
            orizzontal_line(R);
            count = 0;
            i--;
        }
    }
}

int main(void)
{

    // V(0) | V(1) | V(2)
    // -----|------|-----     ----> orizzzontal_line
    // V(3) | V(4) | V(5)
    // -----|------|-----     ----> orizzzontal_line
    // V(6) | V(7) | V(8)
    short N;
    short R = 0;
    bool isradical = false;
    do
    {
        printf("inserisci il valore di N(numero con radice quadrata positiva) per definire il piano di gioco\n(es. N=25 --> campo: 5x5, N=9 --> 3x3): ");
        scanf("%hu", &N);
        float radice = sqrt(N);
        if (radice == (float)(int)radice)
        {
            R = sqrt(N);
            isradical = true;
        }
        else
        {
            printf("il valore inserito non ha radice quadrata positiva\n");
        }
    } while (!isradical);

    char position[N];

    // -------POPOLAZIONE ARRAY -----------
    for (int i = 0; i < N; i++)
    {
        position[i] = ' ';
    }

    printf("inserisci il numero della casella corrispondente per inserire il tuo simbolo\n(Esempio: 1 per la casella in alto a sx, 2 per la seconda casella e cosi' via):\n\n");

    // -------- STAMPA DI SPIEGAZIONE ---------
    print(position, N, R);

    printf("\n\nParte il simbolo 'x', poi i turni si alterneranno con il 'o'\n(ATTENZIONE!!*non e' possibile sovrascrivere un segno gia' iniserito*)\n\nx inserisci il tuo segno in una posizione libera:\n");

    // -------- CONTROLLO CHE LA CASELLA NON SIA OCCUPATA ---------
    int turno = 1;
    bool win = false;
    int value_of_symbol = 'x';

    while (turno <= N && !win)
    {
        // -------INSERIMENTO DATI --------
        // ------- CONTROLLO TURNO PER VEDERE SE METTERE X o O ------------
        int value_of_choise = 0;

        if (turno % 2 == 0)
        {
            value_of_symbol = 'o';
        }
        else
        {
            value_of_symbol = 'x';
        }

        // --------PRENDO IN INPUT LA POSIZIONE DEL SEGNO ----------

        printf("YOUR CHOICE FOR THIS TURN -->");
        scanf("%d", &value_of_choise);

        // -------- INSERISCO I SEGNI NEL PIANO DI GIOCO ----------

        while (value_of_choise > N)
        {
            printf("Non puoi inserire una posizione non esistente\n");
            scanf("%d", &value_of_choise);
        }

        if (position[value_of_choise - 1] == 'x' || position[value_of_choise - 1] == 'o')
        {
            printf("ATTENZIONE!La casella inserita e' gia' occupata da un simbolo!\n");
            turno--;
        }
        else
        {
            position[value_of_choise - 1] = value_of_symbol;
        }

        print(position, N, R);
        printf("\n");
        separation_of_turn();
        turno++;
        win = iswin(position, N, R);
    }

    if (win)
    {
        printf("%c WIN!", value_of_symbol);
    }
    else
    {
        printf("ITS A DRAW!");
    }

    return 0;
}