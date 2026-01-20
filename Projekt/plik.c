#include "plik.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bohaterowie *lista() {

    FILE *f = fopen("bohaterowie.txt","r");

    if (!f) {
        printf("Error pobrania pliku\n");
        exit(1);
    }
    struct Bohaterowie *glowa = NULL; // Na początku lista jest pusta
    char buforImie[102];

    while (fscanf(f, "%101s", buforImie) == 1) {

        // 1. Tworzymy nowy element
        struct Bohaterowie *nowy = malloc(sizeof(struct Bohaterowie));

        // 2. Wypełniamy danymi
        strcpy(nowy->imie, buforImie);
        fscanf(f, "%14s", nowy->rasa);
        fscanf(f, "%d", &nowy->poziom);
        fscanf(f, "%d", &nowy->reputacja);
        fscanf(f, "%14s", nowy->klasa);

        int status;
        fscanf(f, "%d", &nowy->status);
        nowy->status = (StatusBohatera)status;
        fscanf(f, "%d", &nowy->dni);

        // 3. MAGICZNY MOMENT (Wstawianie na początek listy jednokierunkowej)
        nowy->Next = glowa; // Nowy trzyma za rękę "starą" głowę
        glowa = nowy;           // Nowy staje się "nową" głową
    }

    fclose(f);
    return glowa;
}
