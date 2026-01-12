#include "data.h"
#include <stdlib.h>


void generator_dnia5(int zadowolenie[A][A]) {

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A-1; j++) {
            zadowolenie[i][j] = zadowolenie[i][j+1];
        }
    }

    int szansa;

    for (int i=0;i<A;i++) {
        szansa = rand()%8+1;
        zadowolenie[i][A-1]=zadowolenie[i][3]+rand()%7-3;

        if (szansa==1) {
            zadowolenie[i][A-1]+=rand()%61-30;
        }
        if (zadowolenie[i][A-1]<0) {
            zadowolenie[i][A-1]=0;
        }else if (zadowolenie[i][A-1]>100) {
            zadowolenie[i][A-1]=100;
        }
    }
}