/*W systemie akwizycji danych dwa czujniki zostały błędnie podłączone — ich odczyty zapisują się w odwrotnej kolejności. Aby poprawić dane, potrzebna jest funkcja, która zamienia miejscami wartości zmiennych reprezentujących odczyty z czujników. Napisz funkcję:
void swapValues(int *a, int *b);
która zamienia wartości dwóch zmiennych przekazanych przez wskaźniki.

W funkcji main() wczytaj dwie wartości, wyświetl je przed i po wywołaniu funkcji.*/

#include <stdio.h>

void swapValues(int *a, int *b);

int main(void) {
    int a,b;


    while (1) {
        printf("Podaj dane do czujnikow: \n");

        if (scanf("%d%d",&a,&b) != 2) {
            printf("Zle dane!\n");
            while (getchar() != '\n');
        }else break;
    }

    printf("liczby to: %d, %d\n",a,b);
    swapValues(&a, &b);
    printf("liczby to: %d, %d\n",a,b);
    return 0;
}


void swapValues(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
