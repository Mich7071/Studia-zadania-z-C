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
    struct Bohaterowie *HEAD = NULL;
    char buforImie[102];

    while (fscanf(f, "%101s", buforImie) == 1) {


        struct Bohaterowie *nowy = malloc(sizeof(struct Bohaterowie));


        strcpy(nowy->imie, buforImie);
        fscanf(f, "%14s", nowy->rasa);
        fscanf(f, "%d", &nowy->poziom);
        fscanf(f, "%d", &nowy->reputacja);
        fscanf(f, "%14s", nowy->klasa);

        int status;
        fscanf(f, "%d", &status);
        nowy->status = (StatusBohatera)status;

        fscanf(f, "%d", &nowy->dni);


        nowy->Next = HEAD;
        HEAD = nowy;
    }

    fclose(f);
    return HEAD;
}
