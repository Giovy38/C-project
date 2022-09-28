#include <stdio.h>
#include <stdbool.h>

#define N 5
#define M 5

char sea[N][M];
char attack[N][M];

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
    if (sea[converted_x][y] == 'x')
    {
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

void separation_line()
{
    printf(" ");
    for (int i = 0; i < N; i++)
    {
        printf("----");
    }
    printf("-");
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
    print_sea();

    short ship1 = 4, ship2 = 3; // --> %hu  ---> navi disponibili
    char x = 0;
    short converted_x = 0;
    short y = 0;      // --> %hu ---> coordinate posizionamento navi
    short sh_dir = 0; //--> ship direction in short da convertire in bool
    bool ship_direction = 0;
    bool isoccuped = false;

    // ------POSIZIONAMENTO NAVI --------

    // ------ POSIZIONAMENTO NAVI DA 1 -----------

    printf("posiziona le navi di dimensione 1, inserendo le coordinate (A-B-C...) e (1-2-3...)\n");

    while (ship1 > 0)
    {
        printf("(hai ancora a disposizione %hu navi)\n", ship1);
        scanf("\n%c%hu", &x, &y);
        converted_x = letter_to_number(x);
        converted_x--;
        y--;
        isoccuped = control_ship_position_not_occuped(converted_x, y);

        if (!isoccuped)
        {
            sea[converted_x][y] = 'x';
            ship1--;
        }

        print_sea();
    }

    // ------ POSIZIONAMENTO NAVI DA 2 -----------
    printf("posiziona le navi di dimensione 2, inserendo le coordinate (A-B-C...) e (1-2-3...)\n");

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

    return 0;
}