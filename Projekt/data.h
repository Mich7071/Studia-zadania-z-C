#ifndef DATA_H
#define DATA_H


enum Planeta{
    TATOOINE,
    CORUSCANT,
    HOTH,
    ENDOR,
    NABOO,
    MUSTAFAR,
    DAGOBAH,
    KAMINO
};

typedef enum {
    AKTYWNY,
    NA_MISJI,
    RANNY,
    ZAGINIONY,
    ZAWIESZONY,
    NIEZNANY
} StatusBohatera;

struct Bohaterowie {
    char imie[101];
    char rasa[15];
    int poziom;
    int reputacja;
    char klasa[15];
    StatusBohatera status;
    int dni;
    struct Bohaterowie *Next;
};


#endif