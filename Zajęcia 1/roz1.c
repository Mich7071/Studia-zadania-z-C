//Napisz program, który poprosi użytkownika o dwie liczby całkowite. Następnie obliczy ich sumę i średnią arytmetyczną i poda wynik na ekranie.

#include <stdio.h>

int main()
{
    //Pobieranie danych
    int x,y;
    printf("Podaj dwie liczby calkowite: ");

    if (scanf("%d %d",&x,&y) !=2){
        printf("zle dane");
        return 1;
    }

    //oblicznia
    int suma=x+y;
    printf("suma %d\n",suma);

    double srednia = (double) suma/2.0; 


    //Wynik
    printf("srednia %.1f",srednia);


    return 0;
}

