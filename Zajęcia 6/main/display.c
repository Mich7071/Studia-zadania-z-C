#include "display.h"
#include <stdio.h>
#include "analysis.h"

//wyswietlenie tabeli + nazwy
void tablica(int zadowolenie[A][A],char nazwy[A][30]) {
    int srednia = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {

            srednia += zadowolenie[i][j];

            if (zadowolenie[i][j]<10) {
                printf("  %d ", zadowolenie[i][j]);
            }else if (zadowolenie[i][j]==100) {
                printf("%d ", zadowolenie[i][j]);
            }else printf(" %d ", zadowolenie[i][j]);
        }

        printf(" - ");

        assessStatus(srednia);
        srednia = srednia/A;

        printf("   %s   %d",nazwy[i], srednia);



    }
}


