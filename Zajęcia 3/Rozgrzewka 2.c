/*W grach losowych i symulacjach komputerowych często wykorzystuje się generowanie liczb pseudolosowych, aby odwzorować przypadkowe zdarzenia. Napisz program, który zasymuluje serię 50 rzutów sześciościenną kostką. Po zakończeniu symulacji należy policzyć, ile razy wypadła każda z możliwych wartości oczek. Wyniki należy zaprezentować w formie prostego histogramu tekstowego, w którym liczba gwiazdek odpowiada liczbie wystąpień danej wartości, np.:
1: ********
2: **********
3: *****
4: *********
5: *******
6: *********** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tab[6]={0},x;

    for (int i=0;i<50;i++) {
        x=rand()%6;
        tab[x]+=1;
    }
    for (int i=0;i<=5;i++) {
        x=tab[i];
        printf("%d: ",i+1);


        for (;x>0;x--) printf("*");

            printf("\n");

        }
    return 0;
}