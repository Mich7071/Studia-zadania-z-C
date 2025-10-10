//Napisz program, który wczyta liczbê ca³kowit¹ oznaczaj¹c¹ rok. Nastêpnie sprawdzi, czy ten rok jest przestêpny, czy nie, i poda odpowiedni¹ informacjê.
#include <stdio.h>


int main()
{
    //wczytanie wartosci
    int rok;
    printf("Podaj rok a sprawdze czy jest to rok przestepny: ");

    if(scanf("%d",&rok)!=1){
        printf("zle dane!");
        return 1;
    }

    //warunek
    if (rok%4!=0 || (rok%100==0 && rok%400!=0)){
        printf("rok nie jest przestêpny.");
        return 0;
    }

    printf("rok jest przestêpny");

    return 0;
}
