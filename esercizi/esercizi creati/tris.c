#include <stdio.h>
#include <stdbool.h>

#define N 9
int position[N] = {32, 32, 32, 32, 32, 32, 32, 32, 32};

bool iswin()
{
    bool winner = false;
    int zero, one, two, three, four, five, six, seven, eight;
    int empty_space = 32;

    zero = position[0];
    one = position[1];
    two = position[2];
    three = position[3];
    four = position[4];
    five = position[5];
    six = position[6];
    seven = position[7];
    eight = position[8];

    // --------CONTROLLO ORIZZONTALE
    // 012
    // 345
    // 678
    if ((zero == one && zero == two) && zero != empty_space)
    {
        winner = true;
    }

    if ((three == four && three == five) && three != empty_space)
    {
        winner = true;
    }

    if ((six == seven && six == eight) && six != empty_space)
    {
        winner = true;
    }

    // --------CONTROLLO VERTICALE
    // 036
    // 147
    // 258
    if ((zero == three && zero == six) && zero != empty_space)
    {
        winner = true;
    }

    if ((one == four && one == seven) && one != empty_space)
    {
        winner = true;
    }

    if ((two == five && two == eight) && two != empty_space)
    {
        winner = true;
    }

    // --------CONTROLLO OBLIQUO
    // 048
    // 246
    if ((zero == four && zero == eight) && zero != empty_space)
    {
        winner = true;
    }

    if ((two == four && two == six) && two != empty_space)
    {
        winner = true;
    }

    return winner;
}

void separation_of_turn()
{
    printf("-----------\n");
}

void orizzontal_line()
{
    printf("---|---|---\n");
}

void print()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (count < 3)
        {
            if (count < 2)
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
            orizzontal_line();
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

    printf("inserisci il numero della casella corrispondente per inserire il tuo simbolo\n(Esempio: 1 per la casella in alto a sx, 5 per la casella centrale e cosi' via):\n\n");

    // -------- STAMPA DI SPIEGAZIONE ---------
    print();

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

        print();
        printf("\n");
        separation_of_turn();
        turno++;
        win = iswin();
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