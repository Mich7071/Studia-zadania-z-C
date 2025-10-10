//Napisz program, kt�ry wczyta liczb� ca�kowit� oznaczaj�c� rok. Nast�pnie sprawdzi, czy ten rok jest przest�pny, czy nie, i poda odpowiedni� informacj�.
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
        printf("rok nie jest przest�pny.");
        return 0;
    }

    printf("rok jest przest�pny");

    return 0;
}
