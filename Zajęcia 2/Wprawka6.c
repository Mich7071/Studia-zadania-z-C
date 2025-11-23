//Napisz program, symulujący pomiary temperatury w laboratorium. W ciągu 24 godzin co godzinę ma miejsce odczyt (wartości losowe z zakresu od -5 do 30). Program po "upływie" doby powinien wyświetlić wszystkie pomiary oraz obliczyć i podać średnią temperaturę dobową.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int tab[24];
    float sr = 0;

    //Pomiary
    for (int i=0;i<24;i++) {
        tab[i]=rand()%36-5;
    }

    for (int i=0;i<24;i++) {
        printf("%d\n",tab[i]);
        sr+=(float) tab[i];
    }

    printf("\nSrednia temperatura: %.2f",sr/24.0);

    return 0;
}