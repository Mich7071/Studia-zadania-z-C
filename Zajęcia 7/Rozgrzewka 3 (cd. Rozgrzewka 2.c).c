/*Magowie rozszerzyli swoje laboratorium i teraz przechowują zmienną liczbę artefaktów - dlatego tablica ich mocy musi być tworzona dynamicznie.
Napisz program, który:
tworzy tablicę dynamiczną o wielkości pobranej od użytkownika,
wypełnia ją wartościami podanymi przez użytkownika,
korzysta z funkcji napisanych w poprzednim zadaniu (average, minValue, maxValue, swapValues),
zwalnia pamięć po zakończeniu pracy.*/

#include <stdio.h>
#include <stdlib.h>

double average(const int *tab, int size);
int minValue(const int *tab, int size);
int maxValue(const int *tab, int size);
void swapValues(int *a, int *b);
void printArray(const int *tab, int size);

int main() {
    int ilosc, min, max, art1, art2;
    double srednia;

    printf("Podaj ile ma byc artefaktow: ");
    scanf("%d", &ilosc);

    int *moc_energetyczna = malloc(ilosc * sizeof(*moc_energetyczna));

    for (int i = 0; i < ilosc; i++) {
        printf("Podaj moc artefaktu: ");
        scanf("%d",(moc_energetyczna+i));
        while (getchar() != '\n');
    }

    srednia = average(moc_energetyczna, ilosc);
    printf("\nSrednia %.2lf\n",srednia);

    min = minValue(moc_energetyczna, ilosc);
    printf("\nminimalna moc: %d",min);

    max = maxValue(moc_energetyczna, ilosc);
    printf("\nmaksymalna moc: %d",max);

    printf("\nJakie dwa artefaky chcesz zamienic: ");
    scanf("%d%d",&art1,&art2);
    swapValues(moc_energetyczna + art1, moc_energetyczna + art2);

    printArray(moc_energetyczna, ilosc);

    free(moc_energetyczna);
    moc_energetyczna = NULL;

    return 0;
}

double average(const int *tab, int size) {
    double srednia=0.0;

    for (int i = 0; i < size; i++) {
        srednia+=*(tab+i);
    }

    return srednia/size;
}

int minValue(const int *tab, int size) {
    int minimalna=*tab;

    for (int i = 1; i < size; i++) {

        if (minimalna>*(tab+i)) {
            minimalna=*(tab+i);
        }
    }

    return minimalna;
}

int maxValue(const int *tab, int size) {
    int maksymalna=*tab;

    for (int i = 1; i < size; i++) {

        if (maksymalna < *(tab+i)) {
            maksymalna = *(tab+i);
        }
    }

    return maksymalna;
}

void swapValues(int *a, int *b) {
    int tymczasowa = *a;
    *a=*b;
    *b=tymczasowa;
}

void printArray(const int *tab, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d.moc energetyczna: %d\n",i,(int)*(tab+i));
    }
}
