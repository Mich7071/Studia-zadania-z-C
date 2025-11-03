//W niektórych konwersjach liczbowych (np. z systemu dziesiętnego na binarny, ósemkowy lub szesnastkowy) pierwszym etapem jest odwracanie liczby. Napisz program, który wczyta liczbę całkowitą, a następnie wypisze ją "od tyłu", np. z 1234 → 4321.
#include <stdio.h>

int main() {

    int liczba=0;

    if (scanf("%d",&liczba) !=1) {
        printf("Zle dane");
        return 1;
    }

    if (liczba<0) {
        printf("-");
        liczba=liczba*-1;
    }

    while (1) {
        if (liczba<10) {
            printf("%d",liczba%10);
            break;
        }
        printf("%d",liczba%10);
        liczba=liczba/10;

    }
    return 0;
}
