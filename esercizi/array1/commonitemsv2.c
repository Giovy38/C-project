#include <stdio.h>
#include <stdbool.h>

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
    int V1[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V1[i]);
    }

    // V2 di M elementi di tipo T
    int V2[M];

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &V2[i]);
    }

    // V3 per rimuovere i doppioni
    int NM = 0;

    if (N > M)
    {
        NM = N;
    }
    else
    {
        NM = M;
    }

    int V3[NM];
    int useditems = 0;
    int index = 0;

    // identificare e stampare gli elementi che appartengono ad entrambi gli array

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (V1[i] == V2[j])
            {
                V3[index] = V1[i];
                useditems++;
                index++;
            }
        }
    }

    // controllo doppioni
    for (int i = 0; i < useditems; i++)
    {

        for (int j = i + 1; j < useditems; j++)
        {
            // bool isduplicate = V3[i] == V3[j];
            if (V3[i] == V3[j])
            {
                V3[i] = V3[useditems - 1];
                useditems--;
            }
        }
    }

    if (useditems > 2)
    {
        if (V3[useditems - 1] == V3[useditems - 2])
        {
            useditems--;
        }
    }

    for (int i = 0; i < useditems; i++)
    {
        printf("%d ", V3[i]);
    }

    return 0;
}