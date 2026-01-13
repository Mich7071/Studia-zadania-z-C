/*W komnacie znajduje się rząd kryształów energii, z których każdy emituje określony poziom mocy. Napisz program, który pozwoli użytkownikowi odczytywać i modyfikować energię wybranego kryształu - wyłącznie za pomocą wskaźników.
Wyświetl zawartość tablicy przy użyciu notacji wskaźnikowej.
Program ma uruchomić pętlę, która:
Pyta użytkownika, który kryształ chce wybrać (numer od 0 do 4). Wpisanie -1 kończy pętlę.
Po wybraniu numeru kryształu ustaw wskaźnik tak, by wskazywał na odpowiedni element tablicy (bez użycia indeksowania),
wypisz aktualny poziom energii poprzez dereferencję,
pozwól użytkownikowi wpisać nową wartość energii,
zapisz nową wartość przez wskaźnik.
Ponownie wyświetl zawartość tablicy.*/

#include <stdio.h>
#define N 5

void tablica (int *wskaznik);

int main() {
    int moc_krysztaly[N]={15,43,1,87,99}, wybor,nowa_energia;

    int *tmp = moc_krysztaly;

    while (1) {
        tablica(tmp);

        printf("\nKtory krysztal wybierasz (0-4): ");
        if (scanf("%d",&wybor) != 1 || (wybor<0 || wybor>4) && wybor != -1) {
            printf("\nZle dane!\n");
            while (getchar() != '\n');
            continue;
        }else if ((-1) == wybor) return 1;

        while (getchar() != '\n');

        tmp +=wybor;
        printf("\nAktualna moc: %d",*tmp);
        printf("\nJaka ma byc energia: ");
        scanf("%d",&nowa_energia);
        *tmp = nowa_energia;

        tmp=moc_krysztaly;
    }
    return 0;
}

void tablica (int *wskaznik) {
    for (int i = 0; i < N; i++) {
        printf("%d. Moc: %d\n", i, (int) *(wskaznik + i));
    }
}
