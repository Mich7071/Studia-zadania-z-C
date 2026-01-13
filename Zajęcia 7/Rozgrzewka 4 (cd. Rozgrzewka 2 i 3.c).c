/*Po ostatnich sukcesach Akademii Magów Laboratorium Artefaktów Mocy zostało oficjalnie wpisane do długoterminowego planu rozwoju. Rada Starszych przewiduje, że w przyszłości może powstać więcej laboratoriów, a każde będzie przechowywać własny zestaw artefaktów.
Zmodyfikuj wcześniejsze zadanie w taki sposób, by tworzenie, wypełnianie oraz zwalnianie tablicy odbywało się poprzez zdefiniowane funkcje. Dodaj również możliwość zmiany wielkości tablicy.
Takie podejście umożliwi Radzie Starszym skalowanie infrastruktury Akademii wraz z rosnącą liczbą laboratoriów, co będzie niezbędne, gdy w kolejnych latach Akademia uruchomi nowe projekty badawcze.*/

#include <stdio.h>
#include <stdlib.h>

double average(const int *tab, int size);
int minValue(const int *tab, int size);
int maxValue(const int *tab, int size);
void swapValues(int *a, int *b);
void printArray(const int *tab, int size);
int* generator_pomieszczenia(int size);
void wypelnanie(int* tab, int size);
void zwalnianie_tablicy(int* tab);
int* zminana_pomieszczenia(int size, int* tab);

int main() {
    int ilosc, min, max, art1, art2, decyzja;
    double srednia;

    printf("Podaj ile ma byc artefaktow: ");
    scanf("%d", &ilosc);

    int *moc_energetyczna = generator_pomieszczenia(ilosc);

    printf("\nCzy chcesz miniec wielkosc magazynu (1=tak/0=nie): ");
    scanf("%d",&decyzja);

    if (decyzja == 1) {
        printf("\nJak duze ma byc pomieszczenie: ");
        scanf("%d",&ilosc);
        moc_energetyczna = zminana_pomieszczenia(ilosc,moc_energetyczna);
    }

    wypelnanie(moc_energetyczna,ilosc);

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

    zwalnianie_tablicy(moc_energetyczna);

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

int* generator_pomieszczenia(int size) {

    int *wskaznik = malloc(size * sizeof(*wskaznik));
    return wskaznik;
}

void wypelnanie(int* tab, int size) {

    for (int i = 0; i < size; i++) {
        printf("Podaj moc artefaktu: ");
        scanf("%d",(tab+i));
        while (getchar() != '\n');
    }
}

void zwalnianie_tablicy(int* tab) {
    free(tab);
    tab=NULL;
}

int* zminana_pomieszczenia(int size, int* tab) {
    int *tym;
    tym = realloc(tab, size * sizeof(size));

    return tym;
}
