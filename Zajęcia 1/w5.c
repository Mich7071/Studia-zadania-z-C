#include <stdio.h>

int main()
{
    //wpisywanie danych
    int x,y,z;

    printf("Podaj 3 wartosci: ");

    if(scanf("%d %d %d", &x, &y, &z) !=3 || x<1 || y<1 || z<1 ){
        printf("zle dane");
        return 1;
    }

    //ustalanie wartosci
    int high, mid, low;
    if(x>y) {mid=x; low=y;}
    else {mid=y; low=x;}

    if(mid>z){high=mid; mid=z;}
    else high=z;

    //sprawdzenie
    if (high*high == mid*mid+low*low) printf("z podanych d�ugo�ci mo�na zbudowa� tr�jk�t prostok�tny.");
    else printf("liczby nie tworz� tr�jki pitagorejskiej.");

    return 0;
}
