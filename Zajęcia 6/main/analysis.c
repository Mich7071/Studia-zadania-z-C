#include "analysis.h"
#include <stdio.h>

void srednia(int zadowolenie [A][A], float wartosci[A]) {
    float srednia;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            srednia+=(float) zadowolenie[i][j];
        }
        wartosci[i]=srednia/5;
        srednia=0;
    }
}

enum DiplomacyStatus assessStatus(const int srednia) {

    if (srednia>=60){
        printf("  STABLE");
    }else if (srednia<40) {
        printf("  CRITICAL   ! Interwencja zalecana");
    }else printf("  TENSE");

}
