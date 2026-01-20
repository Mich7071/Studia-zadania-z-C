#include "plik.h"
#include <stdio.h>
#include <stdlib.h>

struct Bohaterowie *lista() {

    FILE *f = fopen("bohaterowie.txt","r");

    if (!f) {
        fprintf(stderr, "Error pobranie pliku.log\n");
        exit(1);
    }

}