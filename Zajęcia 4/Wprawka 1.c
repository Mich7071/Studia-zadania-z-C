#include <stdio.h>

double amplifiedSignal(double baseValue, double gain, int steps);

int main() {
    double baseValue,gain;
    int steps;
    printf("\nPodaj wartosc podstawowa: ");
    scanf("%lf",&baseValue);

    printf("\nPodaj wartosc wzrostu: ");
    scanf("%lf",&gain);

    printf("\nPodaj podaj ile czasu ma minac (liczba calkowita): ");
    scanf("%d",&steps);

    double wynik=amplifiedSignal(baseValue, gain, steps);

    printf("\nwynik: %lf", wynik);

    return 0;
}

double amplifiedSignal(double baseValue, double gain, int steps) {
    double sn=baseValue;

    for (int i=0; i < steps;i++)
        sn*=gain;
    return sn;
}
