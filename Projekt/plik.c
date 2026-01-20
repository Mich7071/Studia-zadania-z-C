#include "plik.h"
#include <stdio.h>
#include <stdlib.h>

struct Bohaterowie *lista() {

    FILE *f = fopen("bohaterowie.txt","r");

    if (!f) {
        fprintf(stderr, "Error pobranie pliku.log\n");
        exit(1);
    }
<<<<<<< HEAD
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
        fscanf(f, "%d", &nowy->status);
        nowy->status = (StatusBohatera)status;
        fscanf(f, "%d", &nowy->dni);


        nowy->Next = HEAD;
        HEAD = nowy;
    }

    fclose(f);
    return HEAD;
=======

>>>>>>> parent of a4d5173 (dodatnie listy jedno kierunkowej i sprawdzanie błędów )
}