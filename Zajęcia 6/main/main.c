#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "data.h"
#include "analysis.h"
#include "display.h"

int main() {
    srand(time(NULL));

    int zadowolenie[A][A], r=0,wybor;
    char nazwy[A][30];
    float wartosci[A];


    //wczytanie nazw systemow
    printf("Podaj nazwy pieciu systemow planetarnych (do 30 znakow) : \n");

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < 30; j++) {
            if (r==0) {
                scanf("%c", &nazwy[i][j]);
            }else nazwy[i][j]='\0';

            if (nazwy[i][j]=='\n') {
                r=1;
            }
        }
        r=0;
    }
    printf("\n\n");


    //inicjacja danych
    for (int i = 0; i < A; i++) {
        zadowolenie[i][4] = rand() % 101;
    }


    //wygenerowanie danych w tabelach
    for (int i=0;i<A-1;i++) generator_dnia5(zadowolenie);

    srednia(zadowolenie, wartosci);
    tablica(zadowolenie,nazwy);



    while (1) {

        printf("\n\n1. Oblicz średni poziom zadowolenia we wszystkich systemach\n"
               "2. Wskaż system o najwyższym średnim poziomie zadowolenia\n"
               "3. Wskaż system o najniższym średnim poziomie zadowolenia\n"
               "4. Znajdź systemy, w których występują niepokoje\n"
               "5. Zaktualizuj dane o zadowoleniu\n"
               "6. Wyświetl raport ponownie\n"
               "0. Zakończ program\n");

        while (1) {
            if (scanf("%d",&wybor) != 1) {
                printf("zle dane podaj jeszcze raz\n");
            }else break;
            while (getchar() !='\n');
        }

        switch(wybor) {

            case 1:
                for (int i=0;i<A;i++) {
                    printf("\n%.1f",wartosci[i]);
                }
                break;

            case 2:
                float max=0; int l=0;
                for (int i=0;i<A;i++) {
                    if (wartosci[i]>max) {
                        max=wartosci[i];
                        l=i;
                    }
                }
                printf("%.2f",max);
                printf(" - system nr %d",l+1);
                break;


            case 3:
                float ki=101; int q=0;
                for (int i=0;i<A;i++) {
                    if (wartosci[i]<ki) {
                        ki=wartosci[i];
                        q=i;
                    }
                }
                printf("%.2f",ki);
                printf(" - system nr %d",q+1);
                break;

            case 4:
                for (int i=0;i<A;i++) {
                    if (wartosci[i]<40) {
                        printf("Niepokoje w systemie - %d\n", i+1);
                    }
                }

                break;

            case 5:
                generator_dnia5(zadowolenie);
                srednia(zadowolenie, wartosci);

                printf("\n\n");

                for (int i=0;i<A;i++) {
                    if (wartosci[i]<20) {
                        printf("konieczność interwencji dyplomatycznej - %d\n", i+1);
                    }
                }
                break;

            case 6:
                tablica(zadowolenie,nazwy);
                break;

            case 0:
                return 0;

            default:
                printf("\nzle dane!\n");
                break;
        }
    }
}