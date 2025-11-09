#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define A 5

void generator_dnia5(int zadowolenie [A][A]);
void srednia(int zadowolenie [A][A],float wartosci[A]);
void tablica();
void tablica(int zadowolenie[A][A],char nazwy[A][30]);

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

            case 5:
                generator_dnia5(zadowolenie);
                srednia(zadowolenie, wartosci);
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



void generator_dnia5(int zadowolenie[A][A]) {

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A-1; j++) {
            zadowolenie[i][j] = zadowolenie[i][j+1];
        }
    }

    int szansa;

    for (int i=0;i<A;i++) {
        szansa = rand()%8+1;
        zadowolenie[i][A-1]=zadowolenie[i][3]+rand()%7-3;

        if (szansa==1) {
            zadowolenie[i][A-1]+=rand()%61-30;
        }
        if (zadowolenie[i][A-1]<0) {
            zadowolenie[i][A-1]=0;
        }else if (zadowolenie[i][A-1]>100) {
            zadowolenie[i][A-1]=100;
        }
    }
}

void srednia(int zadowolenie [A][A], float wartosci[A]) {
    float srednia;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            srednia+=(float) zadowolenie[i][j];
        }
        wartosci[i]=srednia/5;
        srednia=0;
    }
}

//wyswietlenie tabeli + nazwy
void tablica(int zadowolenie[A][A],char nazwy[A][30]) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            if (zadowolenie[i][j]<10) {
                printf("  %d ", zadowolenie[i][j]);
            }else if (zadowolenie[i][j]==100) {
                printf("%d ", zadowolenie[i][j]);
            }else printf(" %d ", zadowolenie[i][j]);
        }

        printf(" - ");
        for (int j = 0; j < 30; j++) {
            if (nazwy[i][j]=='\0') break;
            printf("%c",nazwy[i][j]);
        }
    }


}
