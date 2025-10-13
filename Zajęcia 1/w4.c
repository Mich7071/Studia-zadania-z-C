/*Napisz program, kt�ry pomo�e wybra� odpowiedni typ autobusu dla podanej liczby pasa�er�w. Do wyboru s� dwa modele: pierwszy ma rz�dy trzyosobowe (uk�ad 1+2), a drugi rz�dy pi�cioosobowe (uk�ad 2+3). Program powinien sprawdzi�, czy pasa�erowie mieszcz� si� dok�adnie w kt�rym� z autobus�w. Je�li nie, nale�y obliczy�, ile miejsc pozostanie pustych w ka�dym przypadku i wskaza� ten wariant, w kt�rym marnuje si� mniej miejsc. Je�eli oba rozwi�zania s� r�wnie dobre, program powinien to zakomunikowa�.*/


#include <stdio.h>

int main()
{
    //dane
    printf("Podaj liczbe pasa�er�w: ");

    int pas;
    if(scanf("%d", &pas) !=1 || pas<1){
        printf("zle dane");
        return 1;
    }

    //wybor
    if (pas%3==0 && pas%5==0) {printf("Oba beda dobre."); return 0;}
    else if(pas%3==0) {printf("autobus majacy trzyosobowe rzedy bedzie najlepszy."); return 0;}
    else if(pas%5==0) {printf("autobus majacy piecioosobowe rzedy bedzie najlepszy."); return 0;}
    else{
        int w1,w2;
        w1=3-pas%3;
        w2=5-pas%5;
        if (w1<w2) printf("autobus majacy trzyosobowe rzedy bedzie najlepszy.");
        else if (w1>w2) printf("autobus majacy piecioosobowe rzedy bedzie najlepszy.");
        else printf("Oba beda dobre.");
    }

    return 0;
}
