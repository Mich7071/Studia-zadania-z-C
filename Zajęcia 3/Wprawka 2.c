//Wahania kursów walut są naturalnym zjawiskiem na rynku finansowym i mogą być analizowane przy użyciu prostych narzędzi informatycznych. Napisz program, który  wczyta do tablicy wartości kursu wybranej waluty (np. euro) z ostatnich 7 dni. Każdą wartość należy wczytywać do skutku, dopóki użytkownik nie poda poprawnej liczby dodatniej. Po zebraniu danych program powinien obliczyć średni kurs, znaleźć najwyższy i najniższy kurs w badanym okresie, a także wyznaczyć największy wzrost i największy spadek kursu pomiędzy kolejnymi dniami. Na koniec program powinien wypisać wszystkie obliczone wartości w czytelnej formie, tak aby można było łatwo porównać uzyskane wyniki
#include <stdio.h>

int main() {
    float kurs [7], srednia=0, max, min, spadek, wzrost;
    int i=0;

    printf("Podaj cene Euro z ostatnich 7 dni: \n");

    while (i<7) {
        if (scanf("%f",&kurs[i]) == 1 && kurs[i]>0) {
            srednia += kurs[i];
            i++;

        }else{
            printf("Zle dane! \n");
            while (getchar() != '\n');
        }
    }

    srednia=srednia/7;
    printf("\n średni kurs Euro to: %.2f",srednia);

    max=min=kurs[0];
    spadek=wzrost=kurs[1]-kurs[0];
    for (int i=0; i <= 6;i++) {
        if (max<kurs[i]) {
            max=kurs[i];
        }
        if (min>kurs[i]) {
            min=kurs[i];
        }
        if (i <= 4) {
            if (kurs[i+2] - kurs[i+1]<0) {
                if (kurs[i+2] - kurs[i+1]<spadek) {
                    spadek=kurs[i+2] - kurs[i+1];
                }
            }
            if (kurs[i+2] - kurs[i+1]>wzrost) {
                wzrost=kurs[i+2] - kurs[i+1];
            }
        }
    }

    printf("\nmaksymalna cena to %.2f",max);
    printf("\nminimalna cena to %.2f",min);

    if (spadek >= 0) {
        printf("\nBrak spadku");
    }else printf("\nnajwiekszy spadek to %.2f",-spadek);

    if (wzrost <= 0) {
        printf("\nbrak wzrostu");
    }else printf("\nnajwiekszy wzrost to %.2f",wzrost);

    return 0;
}