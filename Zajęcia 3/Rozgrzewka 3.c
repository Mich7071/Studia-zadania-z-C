/* W wielu systemach informatycznych numery identyfikacyjne (takie jak numery kont bankowych, PESEL czy NIP) zapisywane są jako ciągi znaków. Napisz program, który wczytuje numer konta bankowego i weryfikuje jego poprawność.
Program powinien wypisać odpowiedni komunikat: „Numer konta wygląda poprawnie.” lub informację, który warunek został naruszony. Warunki poprawności numeru konta bankowego:
1. Ciąg składa się dokładnie z 26 znaków.
2. Każdy znak jest cyfrą (od '0' do '9').
3. Pierwsze dwie cyfry (cyfry kontrolne) nie są zerami — czyli nie tworzą liczby „00”. */
#include <stdio.h>

int main() {
    char nr[30]={'\0'};
    int p=0;

    scanf("%[^\n]s",nr);

    //zliczenie długości numeru
    for (int i=0;i<30;i++) {
        if (nr[i] != '\0') {
            p+=1;
        }else break;
    }

    //Sprawdzenie warunków
    if (p != 26) {
        printf("Ciag musi sie skladac z dokladnie z 26 znakow!");
        return 1;
    }

    for (int i=0;i<=25;i++) {
        if (nr[i] < '0' || nr[i] > '9') {
            printf("Kazdy znak musi byc cyfra !");
            return 1;
        }
    }

    if (nr[0] == '0' && nr[1] == '0') {
        printf("Pierwsze dwie cyfry (cyfry kontrolne) nie moga byc zerami — czyli nie tworza liczby „00” !");
        return 1;
    }

    printf("Numer konta wyglada poprawnie");

    return 0;
}