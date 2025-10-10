//Napisz program, który symuluje rzut kostk¹ o dowolnej liczbie œcian. Najpierw u¿ytkownik podaje, ile œcian ma mieæ kostka (np. 4, 6, 10, 20…), a nastêpnie komputer losuje wynik od 1 do podanej liczby i wyœwietla go na ekranie.
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
