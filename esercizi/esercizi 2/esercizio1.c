#include <stdio.h>

int main(void)
{

    int n = 0, m = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    // uguale
    while (n == m)
    {
        scanf("%d", &n);
    }
    if (m > n)
    {
        while (m >= n)
        {
            n = m;
            scanf("%d", &m);
        }
        return 0;
    }
    else
    {
        while (m <= n)
        {
            n = m;
            scanf("%d", &m);
        }
        return 0;
    }

    return 0;
}