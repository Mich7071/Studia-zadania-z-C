//W codziennych obserwacjach pogodowych często analizuje się zmiany temperatur w kolejnych dniach, aby określić ogólne tendencje i wahania warunków atmosferycznych. Napisz program, który wczyta z klawiatury temperatury z ostatnich 10 dni i zapisze je w tablicy typu float. Każdą wartość należy wczytywać do skutku, dopóki użytkownik nie poda poprawnej liczby rzeczywistej. Program powinien obliczyć średnią temperaturę, oraz amplitudę temperatur, czyli różnicę między wartością maksymalną a minimalną. Dodatkowo należy określić, w ilu dniach temperatura była wyższa od średniej. Wszystkie obliczone wyniki powinny zostać wyświetlone w czytelnej formie wraz z krótkimi opisami.
#include <stdio.h>

int main() {
    float temp [10],srednia=0, max, min;
    int i=0, ile=0;

    printf("Podaj 10 temperatur: \n");

   while (i<10) {

        if (scanf("%f",&temp[i]) == 1) {
            srednia+=temp[i];
            i++;

        }else{
            printf("Zle dane! \n");
            while (getchar() != '\n');
        }
    }

    srednia=srednia/10;
    printf("\nSrednia temperatura to: %.2f",srednia);

    max=min=temp[0];
    for (int i=0; i<=9;i++) {
        if (srednia<temp[i]) {
            ile++;
        }
        if (max<temp[i]) {
            max=temp[i];
        }
        if (min>temp[i]) {
            min=temp[i];
        }
    }

    printf("\namplituda temperatur wynosci: %.2f",max-min);

    printf("\nTempereatura byla wysza od sredniej w %d dniach",ile);

    return 0;
}
