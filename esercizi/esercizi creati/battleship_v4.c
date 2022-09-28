#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // --> per la chiamata di pulizia system("cls");

#define N 5
#define M 5

char sea[N][M];
char attack[N][M];

void separation_line()
{
    printf(" ");
    for (int i = 0; i < N; i++)
    {
        printf("----");
    }
    printf("-");
}

bool result_lose(short errors)
{
    bool lose = false;
    if (errors == 0)
    {
        lose = true;
    }

    return lose;
}

bool result_win(short sunken_ships)
{
    bool win = false;
    if (sunken_ships == 0)
    {
        win = true;
    }

    return win;
}

void start_attacked_sea()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            attack[i][j] = ' ';
        }
    }
}

void print_attacked_sea()
{
    char yvalue = 'A';

    printf("  ");
    for (int xvalue = 1; xvalue <= N; xvalue++)
    {
        printf(" %d  ", xvalue);
    }
    printf("\n");

    separation_line();
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("%c", yvalue);
        yvalue++;
        for (int j = 0; j < M; j++)
        {
            printf("| %c ", attack[i][j]);
        }
        printf("|");
        printf("\n");
        separation_line();
        printf("\n");
    }
}

bool hitted_ship(short converted_x, short y)
{
    // letter to number
    bool hitted = false;
    if (sea[converted_x][y] == 'x')
    {
        hitted = true;
    }

    return hitted;
}

int letter_to_number(char x)
{
    // A --> 65
    // a --> 97
    int converted_x = 0;

    if (x >= 'A' && x <= 'Z')
    {
        converted_x = x - 64;
    }
    else
    {
        if (x >= 'a' && x <= 'z')
        {
            converted_x = x - 96;
        }
    }

    return converted_x;
}

bool control_ship_position_not_occuped(short converted_x, short y)
{
    // letter to number
    bool isoccuped = false;
    // -------CONTROLLO IN POSIZIONE ------
    if (sea[converted_x][y] == 'x')
    {
        printf("position occuped!\n");
        isoccuped = true;
    }
    // -------CONTROLLO IN VERTICALE ------
    if (sea[converted_x + 1][y] == 'x' || sea[converted_x - 1][y] == 'x')
    {
        if (converted_x > N || converted_x < 0)
        {
            printf("position out of limit!\n");
            isoccuped = true;
        }

        printf("position occuped!\n");
        isoccuped = true;
    }
    // -------CONTROLLO IN ORIZZONTALE ------
    if (sea[converted_x][y - 1] == 'x' || sea[converted_x][y + 1] == 'x')
    {
        if (y > N || y < 0)
        {
            printf("position out of limit!\n");
            isoccuped = true;
        }
        printf("position occuped!\n");
        isoccuped = true;
    }

    return isoccuped;
}

void start_sea()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sea[i][j] = ' ';
        }
    }
}

void print_sea()
{
    char yvalue = 'A';

    printf("  ");
    for (int xvalue = 1; xvalue <= N; xvalue++)
    {
        printf(" %d  ", xvalue);
    }
    printf("\n");

    separation_line();
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("%c", yvalue);
        yvalue++;
        for (int j = 0; j < M; j++)
        {
            printf("| %c ", sea[i][j]);
        }
        printf("|");
        printf("\n");
        separation_line();
        printf("\n");
    }
}

int main(void)
{
    start_sea();
    start_attacked_sea();
    print_sea();

    short ship1 = 4, ship2 = 3; // --> %hu  ---> navi disponibili
    short total_ship = ship1 + (ship2 * 2);
    short total_error = total_ship;
    char x = 0;
    short converted_x = 0;
    short y = 0;      // --> %hu ---> coordinate posizionamento navi
    short sh_dir = 0; //--> ship direction in short da convertire in bool
    bool ship_direction = 0;
    bool isoccuped = false;

    // ------POSIZIONAMENTO NAVI --------

    // ------ POSIZIONAMENTO NAVI DA 1 -----------

    printf("posiziona le navi di dimensione 1, inserendo le coordinate (A-B-C...) e (1-2-3...) --> Esempio:A1-b4...\n");

    while (ship1 > 0)
    {
        printf("(hai ancora a disposizione %hu navi)\n", ship1);
        scanf("\n%c%hu", &x, &y);
        converted_x = letter_to_number(x);
        converted_x--;
        y--;

        while (converted_x < 0 || converted_x >= N || y < 0 || y >= M)
        {
            printf("NON puoi inserire coordinate non esistenti, inserisci nuove coordinate: ");
            scanf("\n%c%hu", &x, &y);
            converted_x = letter_to_number(x);
            converted_x--;
            y--;
        }

        isoccuped = control_ship_position_not_occuped(converted_x, y);

        if (!isoccuped)
        {
            sea[converted_x][y] = 'x';
            ship1--;
        }

        print_sea();
    }

    // ------ POSIZIONAMENTO NAVI DA 2 -----------
    printf("posiziona le navi di dimensione 2, inserendo le coordinate (A-B-C...) e (1-2-3...) --> Esempio:A1-b4...\n");

    while (ship2 > 0)
    {
        printf("seleziona la direzione della nave(0 verticale 1 orizontale): ");
        scanf("%hu", &sh_dir);
        while (sh_dir != 0 && sh_dir != 1)
        {
            printf("seleziona un valore valido (0 o 1): ");
            scanf("%hu", &sh_dir);
        }
        ship_direction = sh_dir;

        printf("(hai ancora a disposizione %hu navi): \n", ship2);
        scanf("\n%c%hu", &x, &y);
        converted_x = letter_to_number(x);
        converted_x--;
        y--;

        while (converted_x < 0 || converted_x >= N || y < 0 || y >= M)
        {
            printf("NON puoi inserire coordinate non esistenti, inserisci nuove coordinate: ");
            scanf("\n%c%hu", &x, &y);
            converted_x = letter_to_number(x);
            converted_x--;
            y--;
        }

        isoccuped = control_ship_position_not_occuped(converted_x, y);

        if (!isoccuped)
        {
            if (ship_direction)
            {
                // se è 1 --> ORIZZONTALE
                if ((y + 1) >= N)
                {
                    sea[converted_x][y] = 'x';
                    sea[converted_x][y - 1] = 'x';
                }
                else
                {
                    sea[converted_x][y] = 'x';
                    sea[converted_x][y + 1] = 'x';
                }
            }
            else
            {
                // se è 0 --> VERTICALE
                if ((converted_x + 1) >= N)
                {
                    sea[converted_x][y] = 'x';
                    sea[converted_x - 1][y] = 'x';
                }
                else
                {
                    sea[converted_x][y] = 'x';
                    sea[converted_x + 1][y] = 'x';
                }
            }
            ship2--;
        }
        print_sea();
    }

    print_sea();

    // -------PULIAMO L'OUTPUT ---------

    char yn;
    printf("vuoi pulire lo schermo? (Y/N) ");
    scanf("\n%c", &yn);
    while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n')
    {
        printf("valore inserito non valido\nvuoi pulire lo schermo? (Y/N) ");
        scanf("%c", &yn);
    }

    if (yn == 'Y' || yn == 'y')
    {
        system("cls");
    }

    // --------FASE D'ATTACCO---------
    bool winner = false;
    bool loser = false;
    printf("adesso inizia la fase d'attacco... indica le coordinate da attacare(A-B-C...) e (1-2-3...) --> Esempio:A1-b4...\n");
    do
    {
        char x_atk = ' ';
        short converted_x_atk = 0;
        short y_atk = 0;

        bool hit = false;

        printf("(devi colpire ancora %hu navi e hai ancora %hu errori disponibili)\ninserisci le coordinate d'attacco: ", total_ship, total_error);
        scanf("\n%c%hu", &x_atk, &y_atk);

        converted_x_atk = letter_to_number(x_atk);
        converted_x_atk--;
        y_atk--;

        while (converted_x_atk < 0 || converted_x_atk >= N || y_atk < 0 || y_atk >= M)
        {
            printf("NON puoi inserire coordinate non esistenti, inserisci nuove coordinate: ");
            scanf("\n%c%hu", &x_atk, &y_atk);
            converted_x_atk = letter_to_number(x_atk);
            converted_x_atk--;
            y_atk--;
        }

        hit = hitted_ship(converted_x_atk, y_atk);

        if (hit)
        {
            attack[converted_x_atk][y_atk] = 'x';
            total_ship--;
        }
        else
        {
            attack[converted_x_atk][y_atk] = 'o';
            total_error--;
        }

        print_attacked_sea();
        winner = result_win(total_ship);
        loser = result_lose(total_error);
    } while (!winner && !loser);

    if (winner)
    {
        printf("COMPLIMENTI HAI VINTO!");
    }
    else
    {
        printf("MI DISPIACE HAI PERSO!");
    }

    return 0;
}