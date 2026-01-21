#ifndef MECHANIKA_H
#define MECHANIKA_H
#include "data.h"

void odpal_generator();

enum Planeta losowanie_planety();

struct Bohaterowie *nowy_bohater(struct Bohaterowie *ostatni);

void wyswietlenie_listy(struct Bohaterowie *bohaterowie);

#endif

