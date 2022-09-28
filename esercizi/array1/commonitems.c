#include <stdio.h>

#define N 9
#define M 8

int main(void)
{

    // dati in input 2 Array

    // esempio
    // array V1: 6(0) 6(1) 4(2) 8(3) -10(4) 3(5) 2(6) 8(7) 3(8)
    // array V2: 5(0) 1(1) 8(2) 4(3) 130(4) 123(5) 32(6) 6(7)
    // output: 6,4,8

    // V1 di N elementi di tipo T
    int V1[N] = {6, 6, 4, 8, -10, 3, 2, 8, 3};

    // V2 di M elementi di tipo T
    int V2[M] = {5, 1, 8, 4, 130, 123, 32, 6};

    // identificare e stampare gli elementi che appartengono ad entrambi gli array

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (V1[i] == V2[j])
            {
                printf("%d ", V1[i]);
            }
        }
    }

    return 0;
}