/*W akademii magów badacze gromadzą kolekcje artefaktów, z których każdy ma swoją "moc energetyczną" wyrażoną jako liczba całkowita. Stwórz zestaw funkcji, które analizują i modyfikują tablice takich wartości.
Wszystkie operacje na tablicy mają być wykonane wyłącznie przez wskaźniki.
double average(const int *tab, int size);
Funkcja oblicza i zwraca średnią arytmetyczną wszystkich wartości.

int minValue(const int *tab, int size);
Zwraca najmniejszą wartość z tablicy.

int maxValue(const int *tab, int size);
Zwraca największą wartość z tablicy.

void swapValues(int *a, int *b);
Funkcja zamienia wartości w dwóch podanych miejscach tablicy. Zamiana odbywa się wyłącznie poprzez operacje na wskaźnikach, tzn. funkcja "widzi" tylko adresy zamienianych elementów - nie przekazujemy całej tablicy.

void printArray(const int *tab, int size);
Wyświetla zawartość tablicy na ekranie.*/

#include <stdio.h>
#define N 5

double average(const int *tab, int size);
int minValue(const int *tab, int size);
int maxValue(const int *tab, int size);
void swapValues(int *a, int *b);
void printArray(const int *tab, int size);

int main() {
    int moc_energetyczna[N] = {5, 3, 67, 2,1};

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
