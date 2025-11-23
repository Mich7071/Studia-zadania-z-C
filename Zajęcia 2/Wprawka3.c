/*Napisz program symulujący działanie prostego kalkulatora. Program powinien wyświetlać menu z dostępnymi operacjami matematycznymi, pozwalać użytkownikowi wybrać działanie, wczytać dwie liczby i wyświetlić wynik.
Po wykonaniu obliczeń program ponownie pokazuje menu, dopóki użytkownik nie wybierze opcji zakończenia.*/

#include <stdio.h>

int main(void) {
    while (1) {
        int w=0;
        float x=0,y=0;


        printf("\n1.Dodowanie\n"
               "2.Odejmowanie\n"
               "3.Mnożenie\n"
               "4.dzielenie\n"
               "5.zakończ działanie\n"
               "Wybór: ");

        if (scanf("%d",&w) !=1 || w<1 || w>5) {
            printf("\nZle dane");
            while (getchar() != '\n');
            continue;
        }

        if (w==5) return 0;

        printf("\nPodaj 2 liczby: \n");

        if (scanf("%f %f",&x, &y) != 2) {
            printf("\nZle dane");
            while (getchar() != '\n');
            continue;
        }

        if (w==1) printf("Wynik to %.1f\n", x+y);
        else if (w==2) printf("Wynik to %.1f\n", x-y);
        else if (w==3) printf("Wynik to %.1f\n", x*y);
        else if (w==4) {
            if (y==0) {
                printf("blad zle  dane\n");
                continue;
            }
            printf("Wynik to %.1f\n", x/y);
        }
    }
}