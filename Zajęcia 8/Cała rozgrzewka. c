/*W Wielkiej Bibliotece przechowywane są bezcenne tomy magii, kroniki dawnych bitew i traktaty alchemiczne. Mistrz Bibliotekarz prowadzi rejestr wszystkich ksiąg znajdujących się w zbiorach.

Dana jest struktura opisująca pojedynczą księgę:


struct book {
char author[32], title[64];
int copies;
float price;
};

Napisz zestaw funkcji zarządzających katalogiem bibliotecznym:

Funkcja pobierająca i zwracająca dane jednej księgi
Napisz funkcję, która wczytuje od użytkownika dane pojedynczej księgi przechowywanej w Wielkiej Bibliotece:
imię i nazwisko autora (np. "Aelindor Białe Pióro"),
tytuł księgi (np. "Kroniki Płonącego Smoka"),
liczbę egzemplarzy dostępnych w archiwum,
cenę jednego egzemplarza (w złotych koronach).
Funkcja powinna zwracać strukturę typu struct book.
Funkcja wypisująca dane księgi
Napisz funkcję, która wyświetla informacje o księdze w czytelnej formie, np.:
Author:                Aelindor Białe Pióro
Title:                 Kroniki Płonącego Smoka
No of copies:          12
Price:                 47.50 zk
Funkcja tworząca katalog zawierający część zbiorów Wielkiej Biblioteki
Napisz funkcję, która:
przyjmuje w parametrze liczbę ksiąg n,
tworzy tablicę o rozmiarze n,
wypełnia ją danymi pobranymi od użytkownika (korzystając z funkcji z punktu 1),
zwraca całą tablicę.
Funkcja wyświetlająca zawartość tablicy
Napisz funkcję, która wyświetli wszystkie księgi z tablicy w kolejności ich występowania, każdą z osobna, w formacie znanym z punktu 2.
Funkcja obliczająca sumaryczną wartość zbiorów
Napisz funkcję, która obliczy łączną wartość wszystkich ksiąg w katalogu, zgodnie ze wzorem:
total_value = Σ (copies * price)
Wypisana wartość odpowiada temu, ile złotych koron wart jest fragment zbiorów przechowywany w bibliotece.*/

#include <stdlib.h>
#include <stdio.h>

struct book {
    char author[32], title[64];
    int copies;
    float price;
};

struct book tworzenie();
void print(struct book *sc);
struct book* katalog(int ilosc);
void print2(int ilsoc, struct book *sc);
void sredia(struct book *sc, int ilosc);


int main() {
    int ilosc;

    struct book ksiega1 = tworzenie();

    print(&ksiega1);

    printf("\nPodaj ile bedzie tych ksiag: ");
    scanf("%d", &ilosc);
    struct book *nowa_ksiega = katalog(ilosc);

    print2(ilosc, nowa_ksiega);

    sredia(nowa_ksiega,ilosc);
    return 0;
}

struct book tworzenie(){
    char imie[32];

    struct book ksiega;
    printf("\nPdaj imie i nazwisko autora: ");
    scanf(" %31[^\n]s",&ksiega.author);


    printf("\nPdaj tytul ksiegi: ");
    scanf(" %63[^\n]s",&ksiega.title);

    printf("\nPdaj liczbe egzemplarzy dostępnych w archiwum: ");
    scanf(" %d",&ksiega.copies);

    printf("\nPdaj cene jednego egzemplarza (w zlotych koronach): ");
    scanf(" %f",&ksiega.price);

    return ksiega;
}


void print(struct book *sc) {

    printf("\nAuthor: %s",sc -> author);
    printf("\nTitle: %s",sc -> title);
    printf("\nNo of copies: %d",sc -> copies);
    printf("\nPrice:  %.2fzk",sc -> price);

}


struct book* katalog(int ilosc) {
    struct book *tymczasowa = malloc(ilosc * sizeof(struct book) );

    for (int i = 0; i < ilosc; i++) {
        tymczasowa[i] = tworzenie();
    }
    return tymczasowa;
}


void print2(int ilsoc, struct book *sc) {

    for (int i = 0; i < ilsoc; i++) {
        printf("\n\n");
        print(sc+i);

    }


}


void sredia(struct book *sc, int ilosc) {
    double srednia=0.0; int ilosc2=0;

    for (int i = 0; i < ilosc; i++) {
        srednia += (double)((sc+i)->copies * (sc+i)->price);
        ilosc2 += (sc+i)->copies;
    }
    printf("\n\nSrednmia cena: %.2lf",srednia/(double)ilosc2);

}
