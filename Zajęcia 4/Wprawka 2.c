/*W systemie kontroli jakości produkty otrzymują numery identyfikacyjne będące liczbami całkowitymi.
Dla zwiększenia bezpieczeństwa, niektóre operacje (np. testy lub aktualizacje) są wykonywane tylko dla produktów o numerach pierwszych – to proste zabezpieczenie przed przypadkowym wyborem zbyt wielu rekordów. Napisz funkcję:
int isPrime(int id);
która sprawdza, czy numer identyfikacyjny id spełnia warunek „liczby pierwszej”. Funkcja powinna zwrócić 1 dla numerów pierwszych i 0 dla pozostałych.

W main() wczytaj numer produktu i wyświetl informację, czy należy do grupy „priorytetowej”.*/

#include <stdio.h>

int isPrime(int id);

int main() {

    int id;

    while (1) {
        scanf("%d", &id);
        while (getchar() != '\n');

        int wynik = isPrime(id);

        if (wynik==1) {
            printf("\nid spelnia warunek!\n");
        }else printf("\nid nie spelnia warunek!\n");
    }

}

int isPrime(int id) {
    int zliczanie=0;

    for (int i = 1; i <= id; i++) {
        if (id%i == 0) zliczanie+=1;
    }

    if (zliczanie == 2) {
        return 1;
    }else return 0;

}
