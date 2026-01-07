/* W analizie tekstów często potrzebne jest określenie, jak często występują poszczególne znaki lub litery. Napisz program, który wczyta z klawiatury dowolny tekst (maksymalnie 200 znaków) i policzy, ile razy pojawia się w nim każda litera alfabetu łacińskiego. Wielkość liter należy ignorować – małe i wielkie litery traktujemy tak samo. Do zliczania można wykorzystać tablicę 26 liczb całkowitych, w której każdemu elementowi odpowiada jedna litera alfabetu (0 dla a, 1 dla b, itd.). Po zakończeniu analizy program powinien wypisać zestawienie w formacie:
a: 12
b: 3
c: 0
...
Na końcu program również wypisuje, ile wszystkich liter wystąpiło w tekście oraz która litera pojawiła się najczęściej. Wszystkie wyniki należy zaprezentować w czytelnej formie, z odpowiednimi opisami. */
#include <stdio.h>

int main() {
    char tekst[201]={'\0'}, taba[27]={'a'};
    int ile=0, zliczanie[26]={0},naj,p=0;

    scanf("%200[^\n]s",&tekst);

    for (int i=1; i<26;i++) {
        taba[i]=(int)taba[0]+i;
    }

    for (int i=0;i<200;i++) {
        if (tekst[i]>='a' && tekst[i]<='z' || tekst[i]>='A' && tekst[i]<='Z') {
            ile++;
            for (int j=0;j<26;j++) {
                if (tekst[i]==taba[j] || tekst[i]==taba[j]-32){
                    zliczanie[j]+=1;
                }
            }
        }
    }

    naj=zliczanie[0];
    for (int i=0; i<26;i++) {
        printf("%c: %d\n",taba[i], zliczanie[i]);
        if (naj<zliczanie[i]) {
            p=i;
            naj=zliczanie[i];
        }
    }

    printf("\nWszystkich liter wystapilo w tekscie: %d\n",ile);
    printf("\n*Najcześciej od początku alfabetu wystepuje %c\n",taba[p]);

    return 0;
}
