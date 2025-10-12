/*Napisz program, który wylosuje temperaturę w zakresie od –10 do +35 stopni Celsjusza. Następnie wyświetli komunikat z prognozą pogody, np.:

jeśli temperatura jest poniżej 0 → „Mróz! Ubierz się ciepło.”
jeśli temperatura mieści się od 0 do 25 → „Całkiem przyjemnie.”
jeśli temperatura jest powyżej 25 → „Upał! Szukaj cienia.”*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int temp=(rand()%46)-10;

    if(temp<0) printf("Mróz! Ubierz się ciepło.");
    else if(25<temp) printf("Upał! Szukaj cienia.");
    else printf("Całkiem przyjemnie.");


    /*lub
    int temp=rand()%46;

    if(temp>35) printf("Mróz! Ubierz się ciepło.");
    else if(0<temp) printf("Całkiem przyjemnie.");
    else printf("Upał! Szukaj cienia.");

    -otrzymujemy jedna czynnosc mniej
    */


    return 0;
}
