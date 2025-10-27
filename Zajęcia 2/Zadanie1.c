//Pewna konstrukcja składa się z warstw modułów ułożonych jedna na drugiej. Pierwsza (dolna) warstwa zawiera 15 modułów, a każda kolejna ma o jeden mniej od poprzedniej. Każdy moduł waży 2 jednostki. Napisz program, który oblicza całkowitą masę konstrukcji, czyli sumę mas wszystkich modułów we wszystkich warstwach.
#include <stdio.h>

int main() {
    int waga=0;

    //obliczanie wagi
    for (int i=15;i>0;i--) waga=waga+i*2;

    printf("laczna masa to: %d",waga);

    return 0;
}
