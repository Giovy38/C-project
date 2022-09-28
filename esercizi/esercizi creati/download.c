// input --> totMB - velMB1 - velMB2 - velMB3 - bool ISGB

#include <stdio.h>

int main(void)
{

    float totdownload = 0;
    int totMB = 0;
    float totGB = 0;
    int velMB1 = 0, velMB2 = 0, velMB3 = 0;
    char isGB;

    printf("dammi il totale da scaricare: ");
    scanf("%f", &totdownload);

REINSERT:
    printf("il valore e' in GB o MB? (G o g per GB, M o m per MB)");
    scanf("\n%c", &isGB);

    if (isGB == 'G' || isGB == 'g')
    {
        totMB = totdownload * 1000;
        totMB = totMB % 1000;
        totGB = totdownload;
    }
    else if (isGB == 'M' || isGB == 'm')
    {
        if (totdownload > 1000)
        {
            totGB = totdownload / 1000; //--> tot GB da scaricare

            while (totdownload >= 1000)
            {
                totdownload -= 1000;
            }

            totMB = totdownload; //--> tot MB da scaricare
        }
    }
    else
    {
        printf("hai inserito un formato non valido\n");
        goto REINSERT;
    }

    int parteintera = (int)totGB; //--> per stampare solo la parte intera

    printf("Totale da scaricare %dGB e %dMB\n", parteintera, totMB);

    printf("dammi 3 velocita' di download in MB: ");
    scanf("%d%d%d", &velMB1, &velMB2, &velMB3);

    // calcolo media velocità
    int mediavel = (velMB1 + velMB2 + velMB3) / 3;

    // tempo di download

    int totsec = (totMB + totGB * 1000) / mediavel;

    int h = 0, m = 0;

    while (totsec > 60)
    {
        m = totsec / 60;
        h = m / 60;
        totsec = totsec % 60;
        m = m % 60;
    }
    printf("%d ore %d minuti %d secondi", h, m, totsec);

    return 0;
}