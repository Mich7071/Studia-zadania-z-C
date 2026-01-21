#include <time.h>
#include <stdlib.h>
#include "mechaniki.h"
#include <stdio.h>
#include <string.h>

void odpal_generator() {

    srand(time(NULL));
}


enum Planeta losowanie_planety(){
    odpal_generator();

    int dzien = rand() % 7;
    return dzien;
}


struct Bohaterowie *nowy_bohater(struct Bohaterowie *ostatni) {
    char nazwa[101];
    int rasa, poziom,reputacja,klasa;

    struct Bohaterowie *tmp = malloc(sizeof(struct Bohaterowie));

    if (!tmp) {
        printf("Blad");
        exit(1);
    }

//---------------------------------------------------------------------------------------------

    //Dodanie imienia bohatera
    printf("\nPodaj nazwę Bohatera (Do 100 znaków): ");

    while (1) {
        if(scanf("%100[^\n]s", nazwa) != 1) {
            while (getchar() != '\n');
            printf("\nZle dane!\n");
            continue;
        }else {
            while (getchar() != '\n');
            strcpy(tmp->imie, nazwa);
            break;
        }
    }

//---------------------------------------------------------------------------------------------

    //Dodanie rasy
    printf("\nWybierz rasę bohatera: "
           "\n1.Elf"
           "\n2.Krasnal"
           "\n3.Czlowiek"
           "\n4.Mutant"
           "\n5.Cyklop\n");

    while (1) {
        if(scanf("%d", &rasa) != 1 || rasa>5 || rasa<1) {
            while (getchar() != '\n');
            printf("\nZle dane!\n");
            continue;
        }else {
            while (getchar() != '\n');
            break;
        }
    }
    switch(rasa){

        case 1:
            strcpy(tmp->rasa, "Elf");
            break;

        case 2:
            strcpy(tmp->rasa, "Krasnal");
            break;

        case 3:
            strcpy(tmp->rasa, "Czlowiek");
            break;

        case 4:
            strcpy(tmp->rasa, "Mutant");
            break;

        case 5:
            strcpy(tmp->rasa, "Cyklop");
            break;

    }

//---------------------------------------------------------------------------------------------

    //poziom bohatera
    printf("\nPodaj poziom bohatera: ");
    while (1) {
        if(scanf("%d", &poziom) != 1 || poziom>100 || poziom<0) {
            while (getchar() != '\n');
            printf("\nZle dane!\n");
            continue;
        }else {
            while (getchar() != '\n');
            tmp->poziom = poziom;
            break;
        }
    }

//---------------------------------------------------------------------------------------------

    //reputacja bohatera
    printf("\nPodaj reputacje bohatera: ");
    while (1) {
        if(scanf("%d", &reputacja) != 1 || reputacja>100 || reputacja<0) {
            while (getchar() != '\n');
            printf("\nZle dane!\n");
            continue;
        }else {
            while (getchar() != '\n');
            tmp->reputacja = reputacja;
            break;
        }
    }

//---------------------------------------------------------------------------------------------

    //klasa bohatera
    printf("\nWybierz klase bohatera: "
           "\n1.Rycerz"
           "\n2.Strzelec"
           "\n3.Snajper"
           "\n4.Medyk"
           "\n5.Zamachowiec"
           "\n6.Mag\n");

    while (1) {
        if(scanf("%d", &klasa) != 1 || klasa>6 || klasa<1) {
            while (getchar() != '\n');
            printf("\nZle dane!\n");
            continue;
        }else {
            while (getchar() != '\n');
            break;
        }
    }
    switch(klasa){

        case 1:
            strcpy(tmp->klasa, "Rycerz");
            break;

        case 2:
            strcpy(tmp->klasa, "Strzelec");
            break;

        case 3:
            strcpy(tmp->klasa, "Snajper");
            break;

        case 4:
            strcpy(tmp->klasa, "Medyk");
            break;

        case 5:
            strcpy(tmp->klasa, "Zamachowiec");
            break;
        case 6:
            strcpy(tmp->klasa, "Mag");
            break;

    }

//---------------------------------------------------------------------------------------------

    //status bohatera
    tmp->status = AKTYWNY;
    tmp->dni = 0;

    //Dodanie do listy
    tmp->Next = ostatni;

    return tmp;
}

void wyswietlenie_listy(struct Bohaterowie *bohaterowie) {
    int i=0;

    printf("\nLista bohaterow\n");

    while (bohaterowie->imie != NULL) {
        printf("\n\n--- Bohater nr %d ---\n", i);
        printf("Imie: %s\n",bohaterowie->imie);
        printf("Rasa: %s\n",bohaterowie->rasa);
        printf("Poziom: %d\n",bohaterowie->poziom);
        printf("Reputacja: %d\n",bohaterowie->reputacja);
        printf("Klasa: %s\n",bohaterowie->klasa);

        printf("Status: ");
        switch(bohaterowie->status) {
            case AKTYWNY:    printf("Aktywny"); break;
            case NA_MISJI:   printf("Na misji"); break;
            case RANNY:      printf("Ranny"); break;
            case ZAGINIONY:  printf("Zaginiony"); break;
            case ZAWIESZONY: printf("Zawieszony"); break;
        }

        bohaterowie = bohaterowie->Next;
        i++;
    }
}

