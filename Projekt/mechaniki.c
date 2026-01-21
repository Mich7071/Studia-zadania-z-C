#include <time.h>
#include <stdlib.h>
#include "mechaniki.h"
#include <stdio.h>
#include <string.h>


enum Planeta losowanie_planety(){

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


void edycja(struct Bohaterowie *bohaterowie) {
    char postac[101];
    int decyzja, rasa, poziom, reputacja, klasa, status;
    struct Bohaterowie *f = bohaterowie;

    printf("\n------------------------------------------------------------------------------\n");


    while (1) {
        printf("\nJakiego bohatera chcesz edytowac (Podaj imie): ");

        if (scanf(" %100[^\n]", postac) != 1) {
            while (getchar() != '\n');
            continue;
        }


        struct Bohaterowie *obecny = f;
        int znaleziono = 0;

        while (obecny != NULL) {
            if (strcmp(obecny->imie, postac) == 0) {
                znaleziono = 1;

                while (1) {
                    printf("\nEdycja:"
                           "\n1. Rasa"
                           "\n2. Poziom"
                           "\n3. Reputacja"
                           "\n4. Klasa"
                           "\n5. Status"
                           "\n6. Zakoncz edycje\nWybor: ");

                    if(scanf(" %d", &decyzja) != 1) {
                        while (getchar() != '\n');
                        printf("\nZle dane!\n");
                        continue;
                    }

                    switch(decyzja) {
                        case 1: // Zmiana rasy
                            printf("\nWybierz nowa rase:"
                                   "\n1.Elf "
                                   "\n2.Krasnal "
                                   "\n3.Czlowiek "
                                   "\n4.Mutant "
                                   "\n5.Cyklop\n");

                            while (1) {
                                if(scanf("%d", &rasa) != 1 || rasa > 5 || rasa < 1) {
                                    while (getchar() != '\n');
                                    printf("Zle dane! ");
                                    continue;
                                } else break;
                            }
                            switch(rasa) {
                                case 1:
                                    strcpy(obecny->rasa, "Elf");
                                    break;
                                case 2:
                                    strcpy(obecny->rasa, "Krasnal");
                                    break;
                                case 3:
                                    strcpy(obecny->rasa, "Czlowiek");
                                    break;
                                case 4:
                                    strcpy(obecny->rasa, "Mutant");
                                    break;
                                case 5:
                                    strcpy(obecny->rasa, "Cyklop");
                                    break;
                            }
                            printf("Zmieniono rase.\n");
                            break;

                        case 2: // Zmiana poziomu
                            printf("\nPodaj nowy poziom: ");
                            while (1) {
                                if(scanf("%d", &poziom) != 1 || poziom > 100 || poziom < 0) {
                                    while (getchar() != '\n');
                                    printf("Zle dane! ");
                                    continue;
                                } else {
                                    obecny->poziom = poziom;
                                    break;
                                }
                            }
                            break;

                        case 3: // Zmiana reputacji
                            printf("\nPodaj nowa reputacje: ");
                            while (1) {
                                if(scanf("%d", &reputacja) != 1 || reputacja > 100 || reputacja < 0) {
                                    while (getchar() != '\n');
                                    printf("Zle dane! ");
                                    continue;
                                } else {
                                    obecny->reputacja = reputacja;
                                    break;
                                }
                            }
                            break;

                        case 4:
                            printf("\nWybierz nowa klase: "
                                   "\n1.Rycerz "
                                   "\n2.Strzelec "
                                   "\n3.Snajper "
                                   "\n4.Medyk "
                                   "\n5.Zamachowiec "
                                   "\n6.Mag\n");
                            while (1) {
                                if(scanf("%d", &klasa) != 1 || klasa > 6 || klasa < 1) {
                                    while (getchar() != '\n');
                                    printf("Zle dane! ");
                                    continue;
                                } else break;
                            }
                            switch(klasa) {
                                case 1:
                                    strcpy(obecny->klasa, "Rycerz");
                                    break;
                                case 2:
                                    strcpy(obecny->klasa, "Strzelec");
                                    break;
                                case 3:
                                    strcpy(obecny->klasa, "Snajper");
                                    break;
                                case 4:
                                    strcpy(obecny->klasa, "Medyk");
                                    break;
                                case 5:
                                    strcpy(obecny->klasa, "Zamachowiec");
                                    break;
                                case 6:
                                    strcpy(obecny->klasa, "Mag");
                                    break;
                            }
                            break;

                        case 5: // Zmiana statusu
                            if (obecny->status == NA_MISJI) {
                                printf("\nNie mozna edytowac statusu, bohater jest na misji\n");
                                break;
                            }

                            printf("\nWybierz status: "
                                   "\n1.AKTYWNY "
                                   "\n2.NA_MISJI "
                                   "\n3.RANNY "
                                   "\n4.ZAGINIONY "
                                   "\n5.ZAWIESZONY\n");
                            while (1) {
                                if(scanf("%d", &status) != 1 || status > 5 || status < 1) {
                                    while (getchar() != '\n');
                                    printf("Zle dane! ");
                                    continue;
                                } else break;
                            }

                            switch(status) {
                                case 1:
                                    obecny->status = AKTYWNY;
                                    break;
                                case 2:
                                    obecny->status = NA_MISJI;
                                    break;
                                case 3:
                                    obecny->status = RANNY;
                                    break;
                                case 4:
                                    obecny->status = ZAGINIONY;
                                    break;
                                case 5:
                                    obecny->status = ZAWIESZONY;
                                    break;
                            }
                            printf("Zmieniono status.\n");
                            break;

                        case 6: //exit
                            return;

                        default:
                            printf("Nie ma takiej opcji.\n");
                    }
                }
            }
            obecny = obecny->Next;
        }

        if (znaleziono == 0) {
            printf("\nNie ma takiej osoby! Sprobuj ponownie.\n");
        }
    }
}


struct Bohaterowie *usun_bohatera1(struct Bohaterowie *head) {
    char imie[101];

    printf("\nPodaj imie: ");
    while (1) {
        if (scanf("%100[^\n]", imie) != 1) {
            while (getchar() != '\n');
            continue;
        }else {
            while (getchar() != '\n');
            break;
        }
    }

    struct Bohaterowie *bohaterdousuniecia = head;
    struct Bohaterowie *poprzedni = NULL;

    while (bohaterdousuniecia != NULL) {
        if (strcmp(bohaterdousuniecia->imie, imie) == 0) {
            if (bohaterdousuniecia->status == NA_MISJI) {
                printf("Blad, Bohater jest na misji!\n");
                return head;
            }

            if (poprzedni == NULL) {
                head = bohaterdousuniecia->Next;
            }
            else {
                poprzedni->Next = bohaterdousuniecia->Next;
            }

            free(bohaterdousuniecia);
            printf("Usunieto.\n");
            return head;
        }
        poprzedni = bohaterdousuniecia;
        bohaterdousuniecia = bohaterdousuniecia->Next;
    }
    printf("Nie znaleziono.\n");
    return head;
}


struct Bohaterowie *usun_bohaterow2(struct Bohaterowie *head) {
    int poziom;

    printf("\nUsun wszystkich ponizej poziomu: ");

    printf("Podaj poziom (1-100): ");

    while (1) {
        if (scanf("%d", &poziom) != 1 || poziom < 0 || poziom > 100) {
            printf("\nBlad!\n ");
            while (getchar() != '\n');
            continue;
        }else {
            while (getchar() != '\n');
            break;
        }
    }

    struct Bohaterowie *bohaterdousuniecia = head;
    struct Bohaterowie *poprzedni = NULL;

    while (bohaterdousuniecia != NULL) {

        if (bohaterdousuniecia->poziom < poziom && bohaterdousuniecia->status != NA_MISJI) {
            struct Bohaterowie *temp = bohaterdousuniecia;

            if (poprzedni == NULL) {
                head = bohaterdousuniecia->Next;
                bohaterdousuniecia = head;
            } else {
                poprzedni->Next = bohaterdousuniecia->Next;
                bohaterdousuniecia = bohaterdousuniecia->Next;
            }
            free(temp);
            printf("Usunieto bohatera.\n");
        } else {
            poprzedni = bohaterdousuniecia;
            bohaterdousuniecia = bohaterdousuniecia->Next;
        }
    }
    return head;
}



struct Bohaterowie *usun_bohatera(struct Bohaterowie *head) {
    int wybor;

    if (!head) {
        printf("Lista pusta.\n");
        return NULL;
    }

    printf("\n1. Usun po imieniu"
           "\n2. Usun slabych (grupowo)"
           "\nWybor: ");

    while (1) {
        if (scanf("%d", &wybor) != 1) {
            while (getchar() != '\n');
            printf("\nBlad! Podaj liczbe: ");
            continue;
        } else {
            while (getchar() != '\n');
            break;
        }
    }

    if (wybor == 1) return usun_bohatera1(head);
    if (wybor == 2) return usun_bohaterow2(head);

    return head;
}
