//Napisz program, kt�ry symuluje rzut kostk� o dowolnej liczbie �cian. Najpierw u�ytkownik podaje, ile �cian ma mie� kostka (np. 4, 6, 10, 20�), a nast�pnie komputer losuje wynik od 1 do podanej liczby i wy�wietla go na ekranie.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    //wybor
    int kosc;

    printf("Ile scian ma miec kostka: ");

    if(scanf("%d",&kosc)!=1 || kosc<0){
        printf("Zla wartosc!");
        return 1;
    }

    //losowanie
    srand(time(NULL));
    int los = rand()%kosc + 1;

    printf("wylosowana liczba to: %d",los);




    return 0;
}
