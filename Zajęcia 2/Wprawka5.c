//Mario i Luigi założyli się, kto szybciej uzbiera na pizzę. Ustalili, że przez 30 dni będą odkładać pieniądze na zmianę: pierwszego dnia Mario odkłada 5 zł, drugiego Luigi, i tak dalej. Każdego dnia kwota odkładana rośnie o 5%. Napisz program, który policzy, ile pieniędzy odłoży każde z nich po 30 dniach i kto szybciej zamówi dużą neapolitanę.

#include <stdio.h>

int main() {
    int czas=1;
    float Mario=0.0, Luigi=0.0,kwota=5.0;

    while (czas<31)
    {
        if (czas%2==0) {
            Luigi+=kwota;
        }else Mario+=kwota;

        czas+=1;
        kwota*=1.05;
    }

    printf("mario ma %.2f, a Luigi ma %.2f",Mario,Luigi);
    if (Mario>Luigi) {
        printf("\nMario pierwszy kupi pizze");
    }else printf("\nLuigi pierwszy kupi pizze");

    return 0;
}