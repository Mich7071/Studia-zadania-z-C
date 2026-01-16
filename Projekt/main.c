#include <stdio.h>

int main() {
    int wybor;
    int systemDziala = 1;

    while (systemDziala) {
        printf("\n==================================================\n");
        printf("   SYSTEM ZARZADZANIA GILDIA POSZUKIWACZY PRZYGOD\n");
        printf("==================================================\n");
        printf("[1] Rejestracja nowego bohatera\n");
        printf("[2] Przeglad rejestru\n");
        printf("[3] Wyszukiwanie bohatera\n");
        printf("[4] Modyfikacja danych\n");
        printf("[5] Usun bohatera z rejestru\n");
        printf("[6] Sortowanie listy\n");
        printf("[7] Zapisz zmiany i zakoncz prace\n");
        printf("==================================================\n");
        printf("Twoj wybor: ");

        if (scanf("%d", &wybor) != 1) {
            while (getchar() != '\n');
            printf("Blad: Prosze podac liczbe.\n");
            continue;
        }

        switch (wybor) {
            case 1:
                printf(">>> Rejestracja...\n");
                break;
            case 2:
                printf(">>> Wyswietlanie listy...\n");
                break;
            case 3:
                printf(">>> Wyszukiwanie...\n");
                break;
            case 4:
                printf(">>> Edycja danych...\n");
                break;
            case 5:
                printf(">>> Usuwanie...\n");
                break;
            case 6:
                printf(">>> Sortowanie...\n");
                break;
            case 7:
                printf(">>> Zapis i wyjscie...\n");
                systemDziala = 0;
                break;
            default:
                printf("Nieznana opcja.\n");
        }
    }

    return 0;
}
