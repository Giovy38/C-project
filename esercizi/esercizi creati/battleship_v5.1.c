#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // --> per la chiamata di pulizia system("cls");

#define N 10
#define M 10

char sea[N][M];
char attack[N][M];

// -------STAMPA LINEA SEPARAZIONE ----------

void separation_line()
{
    printf(" ");
    for (int i = 0; i < N; i++)
    {
        printf("----");
    }
    printf("-");
}

// -------- RISULTATO ------------

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

// -------- ARRAY DI ATTACCO, INIZIALIZZAZIONE E STAMPA ----------

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

// ------ CONTROLLO NAVE COLPITA ------------

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

// ---------- CONVERSIONE DA LETTERA A NUMERO -----------

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

// ---------- CONTROLLO POSIZIONE NAVE NON OCCUPATA -------------

bool empty_space(short converted_x, short y, short ship_dimension, bool ship_direction)
{
    // letter to number
    bool isoccuped = false;
    // ----- CONTROLLO NAVI DA 1 ---------
    if (ship_dimension == 1)
    {
        // -------CONTROLLO IN POSIZIONE ------
        if (sea[converted_x][y] == 'x')
        {
            printf("position occuped!\n");
            isoccuped = true;
        }
        return isoccuped;
    }
    else
    {
        if (ship_direction == 0) // nave in verticale
        {
            // -------CONTROLLO IN VERTICALE ------
            for (int i = 1; i <= ship_dimension; i++)
            {
                if (converted_x > N || converted_x < 0 || converted_x + i > N)
                {
                    isoccuped = true;
                }

                if (sea[converted_x][y] == 'x')
                {
                    isoccuped = true;
                }

                if (sea[converted_x + i][y] == 'x')
                {
                    isoccuped = true;
                }
            }
            if (isoccuped)
            {
                printf("position out of limit or occuped!\n");
            }
        }
        else
        {
            // -------CONTROLLO IN ORIZZONTALE ------

            for (int i = 1; i <= ship_dimension; i++)
            {
                if (y > N || y < 0 || y + i > N)
                {
                    isoccuped = true;
                }

                if (sea[converted_x][y] == 'x')
                {
                    isoccuped = true;
                }

                if (sea[converted_x][y + i] == 'x')
                {
                    isoccuped = true;
                }
            }
            if (isoccuped)
            {
                printf("position out of limit or occuped!\n");
            }
        }
    }

    return isoccuped;
}

// --------- ARRAY INIZIALE, INIZIALIZZAZIONE E STAMPA -----------

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

// ------ POSIZIONAMENTO NAVI ---------
void ship_positioning(short ship_dimension, short ship, char x, short converted_x, short y, bool ship_direction, bool isoccuped, short sh_dir)
{

    printf("posiziona le navi di dimensione %hu, inserendo le coordinate (A-B-C...) e (1-2-3...) --> Esempio:A1-b4...\n", ship_dimension);

    while (ship > 0)
    {
        printf("seleziona la direzione della nave(0 verticale 1 orizontale): ");
        scanf("%hu", &sh_dir);
        while (sh_dir != 0 && sh_dir != 1)
        {
            printf("seleziona un valore valido (0 o 1): ");
            scanf("%hu", &sh_dir);
        }
        ship_direction = sh_dir;

        printf("(hai ancora a disposizione %hu navi): \n", ship);
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

        isoccuped = empty_space(converted_x, y, ship_dimension, ship_direction);

        if (!isoccuped)
        {
            if (ship_direction)
            {
                // se è 1 --> ORIZZONTALE
                for (int i = 0; i < ship_dimension; i++)
                {
                    sea[converted_x][y + i] = 'x';
                }
            }
            else
            {
                // se è 0 --> VERTICALE
                for (int i = 0; i < ship_dimension; i++)
                {
                    sea[converted_x + i][y] = 'x';
                }
            }
            ship--;
        }
        print_sea();
    }

    print_sea();
}

// ---------- INIZIO PROGRAMMA -----------

int main(void)
{
    start_sea();
    start_attacked_sea();
    print_sea();

    short ship1 = 4, ship2 = 3; // --> %hu  ---> navi disponibili
    short ship3 = 2, ship4 = 1; // --> %hu  ---> navi disponibili
    short ship_dimension = 0;
    short total_ship = ship1 + (ship2 * 2) + (ship3 * 3) + (ship4 * 4);
    short total_error = total_ship;
    char x = 0;
    short converted_x = 0;
    short y = 0;      // --> %hu ---> coordinate posizionamento navi
    short sh_dir = 0; //--> ship direction in short da convertire in bool
    bool ship_direction = 0;
    bool isoccuped = false;

    // ------POSIZIONAMENTO NAVI --------

    // ------ POSIZIONAMENTO NAVI DA 1 -----------

    ship_dimension = 1;

    printf("posiziona le navi di dimensione %hu, inserendo le coordinate (A-B-C...) e (1-2-3...) --> Esempio:A1-b4...\n", ship_dimension);

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

        isoccuped = empty_space(converted_x, y, ship_dimension, ship_direction);

        if (!isoccuped)
        {
            sea[converted_x][y] = 'x';
            ship1--;
        }

        print_sea();
    }

    // ------ POSIZIONAMENTO NAVI DA 2 -----------
    ship_dimension = 2;

    ship_positioning(ship_dimension, ship2, x, converted_x, y, ship_direction, isoccuped, sh_dir);

    // ------ POSIZIONAMENTO NAVI DA 3 -----------
    ship_dimension = 3;

    ship_positioning(ship_dimension, ship3, x, converted_x, y, ship_direction, isoccuped, sh_dir);

    // ------ POSIZIONAMENTO NAVI DA 4 -----------
    ship_dimension = 4;

    ship_positioning(ship_dimension, ship4, x, converted_x, y, ship_direction, isoccuped, sh_dir);

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