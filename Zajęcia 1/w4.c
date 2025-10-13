/*Napisz program, który pomo¿e wybraæ odpowiedni typ autobusu dla podanej liczby pasa¿erów. Do wyboru s¹ dwa modele: pierwszy ma rzêdy trzyosobowe (uk³ad 1+2), a drugi rzêdy piêcioosobowe (uk³ad 2+3). Program powinien sprawdziæ, czy pasa¿erowie mieszcz¹ siê dok³adnie w którymœ z autobusów. Jeœli nie, nale¿y obliczyæ, ile miejsc pozostanie pustych w ka¿dym przypadku i wskazaæ ten wariant, w którym marnuje siê mniej miejsc. Je¿eli oba rozwi¹zania s¹ równie dobre, program powinien to zakomunikowaæ.*/


#include <stdio.h>

int main()
{
    //dane
    printf("Podaj liczbe pasa¿erów: ");

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
