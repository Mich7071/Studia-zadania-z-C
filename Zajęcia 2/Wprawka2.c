//Napisz program obliczający, ile dni zajęło użytkownikowi przejście 100 000 kroków. Każdego dnia użytkownik wprowadza kolejne liczby całkowite oznaczające liczbę przebytych kroków.

#include <stdio.h>

int main() {
    int kroki=0,dzien=0,k=0;

    while (kroki<100000) {
        dzien+=1;

        while (1) {
            if (scanf("%d",&k) !=1 || k<0 || getchar()!='\n') {
                printf("Bledne dane!");
                while (getchar() !='\n');
            }else break;
        }

        kroki+=k;

    }
    printf("Przejscie zajelo: %d Dni",dzien);

    return 0;
}
