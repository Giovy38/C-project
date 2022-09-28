#include <stdio.h>
// oldest_age(N, V, &max1, &max2);
void oldest_age(int N, int *V, int *max1, int *max2)
{
    int maxone = *max1, maxtwo = *max2;
    for (int i = 2; i < N; i++)
    {
        // portiamo il più grande in prima posizione
        int swipemax = 0;
        if (maxone < maxtwo)
        {
            swipemax = maxtwo;
            maxtwo = maxone;
            maxone = swipemax;
        }

        if (V[i] > maxone || V[i] > maxtwo)
        {
            if (V[i] > maxtwo)
            {
                maxtwo = V[i];
            }
            else
            {
                maxone = V[i];
            }
        }
    }

    *max1 = maxone;
    *max2 = maxtwo;
}

int main(void)
{

    // Write a function called two_oldest_ages.
    //  The function should take a list of numbers as its argument and return the two highest numbers within the list.
    // The returned value should be a list in the format
    //[second oldest age, oldest age].

    /*
    The order of the numbers passed in could be any order.
    '''
    two_oldest_ages( [1, 2, 10, 8] ) # [8, 10]
    two_oldest_ages( [6,1,9,10,4] ) # [9,10]
    two_oldest_ages( [4,25,3,20,19,5] ) # [20,25]
    ''
    */

    int N = 5;
    int V[N];

    do
    {
        if (N < 2)
        {
            printf("ATTENZIONE non puoi inserire un array con meno di 2 valori\n");
        }
        printf("inserisci il numero di eta' da inserire: ");
        scanf("%d", &N);
    } while (N < 2);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }

    int max1 = V[0], max2 = V[1];

    oldest_age(N, V, &max1, &max2);

    printf("second oldest age: %d, oldest age: %d", max2, max1);

    return 0;
}