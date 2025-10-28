//Napisz program, który monitoruje wyniki pomiarów z czujnika temperatury. Program wczytuje kolejne wartości całkowite reprezentujące odczyty z czujnika, dopóki ta sama wartość nie pojawi się trzy razy z rzędu. Taki przypadek oznacza, że temperatura ustabilizowała się i pomiary można zakończyć. Po wykryciu trzykrotnego powtórzenia program kończy działanie, wyświetlając komunikat informujący o stabilnym odczycie.

#include <stdio.h>

int main() {
    int x=0,y=0,z=0,ilosc=0;

    //Sprawdzanie wyników
    while (x != y || y != z || ilosc<3) {
        z=y;
        y=x;

        if (scanf("%d",&x) !=1) {
            printf("Zle dane!");
            return 1;
        }
        ilosc+=1;
    }

    printf("Stabilny odczyt");
    return 0;
}