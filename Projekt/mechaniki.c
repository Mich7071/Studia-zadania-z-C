#include <time.h>
#include <stdlib.h>
#include "mechaniki.h"

void odpal_generator() {

    srand(time(NULL));
}


enum Planeta losowanie_planety(){
    odpal_generator();

    int dzien = rand() % 7;
    return dzien;
}