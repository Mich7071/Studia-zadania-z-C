/* Napisz program, który symuluje grę w rzut kostką. Na początku użytkownik podaje wartość początkowego kredytu. Program losuje liczbę z zakresu od 1 do 6 i wyświetla wynik. Jeśli wylosowana liczba to 1, 2 lub 3, od kredytu odejmowana jest pewna stała kwota. Jeśli liczba to 4, 5 lub 6, do kredytu dodawana jest ta sama kwota. Po każdym rzucie program pyta użytkownika, czy chce kontynuować grę. Po zakończeniu działania program wyświetla końcowy stan kredytu oraz informację, czy gracz zyskał, czy stracił względem wartości początkowej.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main () {
    srand(time(NULL));
    int kredyt,kredyt1,los;
    char kon;

    printf("Podaj wielkosc kredytu: ");

    if (scanf("%d",&kredyt) !=1 || kredyt<1) {
        printf("zle dane!");
        return 1;
    }
    kredyt1=kredyt;

    while (1) {
        los=rand()%6+1;
        printf("\n\nwynik %d",los);

        if (los>3) {
            printf("\n Wygrana!");
            kredyt+=3;
        }else{
            printf("\n Przegrana!");
            kredyt-=3;
        }
        printf("\n\nCzy chcesz grac dalej\n"
               "T-Tak\n"
               "N-Nie\n\n");
        if (scanf(" %c",&kon) !=1) {
            printf("Zly znak!");
            return 1;
        }


        if (kon == 'T') {
            continue;
        }else if (kon == 'N'){
            printf("Aktualna suma to: %d", kredyt);
            if (kredyt>kredyt1) {
                printf("\nZysk");
            }else if (kredyt<kredyt1) {
                printf("\nStrata!");
            }else printf("Jesteś bez strat i zysku");

            return 0;
        }else {
            printf("Zly znak!");
            return 1;
        }
    }
}