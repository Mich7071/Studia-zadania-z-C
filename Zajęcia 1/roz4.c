//Napisz program, który symuluje rzut kostką o dowolnej liczbie ścian. Najpierw użytkownik podaje, ile ścian ma mieć kostka (np. 4, 6, 10, 20…), a następnie komputer losuje wynik od 1 do podanej liczby i wyświetla go na ekranie.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
    srand(time(NULL));
    
    //wybor
    int kosc;

    printf("Ile scian ma miec kostka: ");

    if(scanf("%d",&kosc)!=1 || kosc<0){
        printf("Zla wartosc!");
        return 1;
    }

    //losowanie

    int los = rand()%kosc + 1;

    printf("wylosowana liczba to: %d",los);




    return 0;
}

