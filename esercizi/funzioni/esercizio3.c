#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    bool primo = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            primo = 0;
            return primo;
        }
        else
        {
            primo = 1;
        }
    }

    return primo;
}

int main(void)
{

    // definire una funzione pura booleana che prende in input un numero
    // se il numero è primo restituisce true
    // altrimenti false

    // esempio
    // is_prime(10) --> false
    // is_prime(11) --> true
    // is_prime(11) --> true
    // is_prime(7) --> true
    // is_prime(1) --> true
    // is_prime(2) --> true
    // is_prime(130) --> false
    bool risult;

    risult = is_prime(20);
    printf("%d ", risult);
    risult = is_prime(18);
    printf("%d ", risult);
    risult = is_prime(50);
    printf("%d ", risult);
    risult = is_prime(3);
    printf("%d ", risult);
    risult = is_prime(5);
    printf("%d ", risult);
    risult = is_prime(2);
    printf("%d ", risult);
    risult = is_prime(11);
    printf("%d ", risult);

    return 0;
}