/*Zadanie główne - Operacje kryptograficzne na pokładzie "Orion One"
Statek kosmiczny Orion One przemierza granice znanej galaktyki, prowadząc tajne operacje wywiadowcze. Na jego pokładzie agenci wymieniają między sobą zaszyfrowane wiadomości, jednak z powodu ograniczeń systemu łączności mogą przesyłać jednorazowo nie więcej niż 128 znaków. Napisz program wspomagający agentów w operacjach kryptograficznych i analizie ich komunikatów.

Program powinien umożliwiać wprowadzenie dwóch tajnych wiadomości i wykonanie na nich następujących operacji:

Odczyt długości transmisji
Każda wiadomość musi zostać dokładnie zmierzona — system powinien wyświetlić długość obu wprowadzonych komunikatów, aby agenci mogli oszacować wielkość szyfrowanych danych.

Sprawdzenie zgodności przekazu
Czasami różne sekcje Oriona przesyłają odmienne wersje tego samego komunikatu. System ma porównać dwie wiadomości i sprawdzić, czy są one identyczne, ignorując przy tym różnice w wielkości liter.

Scalenie transmisji
W razie potrzeby agenci mogą połączyć dwa komunikaty w jeden dłuższy. Program ma utworzyć nową wiadomość, powstałą przez połączenie obu tekstów, i wyświetlić wynikową transmisję.

Szyfrowanie metodą ROT13
W trosce o bezpieczeństwo danych agenci korzystają z klasycznego algorytmu ROT13. Program powinien zaszyfrować pierwszą wprowadzoną wiadomość, zastępując każdą literę alfabetu łacińskiego (a–z, A–Z) literą przesuniętą o 13 pozycji w alfabecie (cyklicznie).
Przykład:

Wejście:  Ala ma piłkę?
Wynik:    Nyn zn cvłxę?
Znaki spoza alfabetu pozostają bez zmian.
(Uwaga: ponowne zastosowanie ROT13 na wyniku przywraca oryginalny tekst).

Odczyt wsteczny
W pewnych sytuacjach agenci Oriona muszą odczytać wiadomość przesłaną od końca. Program powinien odwrócić pierwszą wprowadzoną wiadomość i wyświetlić ją w tej postaci.

Po wczytaniu dwóch wiadomości program powinien wyświetlić menu operacji, z którego użytkownik może wybierać odpowiednie polecenia, np.:

=== TERMINAL ORION ONE ===
1. Wyświetl długość obu wiadomości
2. Porównaj wiadomości
3. Połącz wiadomości
4. Szyfruj wiadomość 1 (ROT13)
5. Odwróć wiadomość 1
0. Zakończ transmisję
Wybierz opcję:
Menu powinno działać w pętli, umożliwiając agentowi wykonywanie wielu operacji bez ponownego uruchamiania programu.
Wybór opcji 0 kończy działanie systemu i wyświetla komunikat o zakończeniu sesji transmisyjnej.*/

#include <stdio.h>

int main()
{
    int i=0,x=0,koniec=1,ilosc1=0,ilosc2=0,p1,p2,u=0; char w1[128],w2[128];

    //pierwsza wiadomosc
    printf("Podaj wiadomosc pierwsza: ");

    for(i=0;i<127;i=i+1){
        scanf("%c",&w1[i]);
        ilosc1=ilosc1+1;

        if(w1[i]=='\n'){
            w1[i]='\0';
            ilosc1=ilosc1-1;
            i=0;
            break;
        }
    }


    //druga wiadomosc
    printf("Podaj wiadomosc druga: ");

    for(i=0;i<127;i=i+1){
        scanf("%c",&w2[i]);
        ilosc2=ilosc2+1;

        if(w2[i]=='\n'){
            w2[i]='\0';
            ilosc2=ilosc2-1;
            i=0;
            break;
        }
    }




    do{
        printf("\n=== TERMINAL ORION ONE ===\n"
               "1. Wyswietl dlugosc obu wiadomosci\n"
               "2. Porownaj wiadomosci\n"
               "3. Polacz wiadomosci\n"
               "4. Szyfruj wiadomosc 1 (ROT13)\n"
               "5. Odwroc wiadomosc 1\n"
               "0. Zakoncz transmisje\n"
               "Wybierz opcje: ");

        if(scanf("%d",&x) !=1){
            printf("\nzle dane\n");
            while (getchar() != '\n');
            continue;
        }

        switch(x) {
            case 1:
                printf("\ndlugosc pierwszej wiadomosci to %d znakow\n", ilosc1);
                printf("\ndlugosc drugiej wiadomosci to %d znakow\n\n", ilosc2);
                break;


            case 2:
                i=0;
                if(ilosc1 != ilosc2){
                    printf("\nWiadmomosci nie sa identyczne!\n");
                    break;
                }else{
                    while(i<ilosc1){
                        p1=(int)w1[i];
                        p2=(int)w2[i];

                        if(p1 != p2 && p1+32 != p2){ //błąd
                            printf("\nWiadmomosci nie sa identyczne!\n");
                            u=1;
                            break;
                        }
                        i=i+1;
                    }
                    if(u==0){
                        printf("\nwiadmosci sa identyczne\n");
                    }

                    break;
                }


            case 3:
                printf("%s %s",w1,w2);
                break;

            case 4:
                i=0;

                while(i<ilosc1) {
                    if (w1[i]>='A' && w1[i]<='Z' || w1[i]>='a' && w1[i]<='z') {
                        if (w1[i]>=78 && w1[i]<=90 || w1[i]>=110 && w1[i]<=122) {
                            w1[i]-=26;
                        }
                        w1[i]+=13;
                    }
                    i++;
                }
                break;

            case 5:
                i=0;
                while(i<ilosc1) {
                    printf("%c",w1[ilosc1-i-1]);
                    i++;
                }
                break;

            case 0:
                printf("zakonczenie sesji transmisyjne\n");
                return 0;

            default: printf("\nPodaj poprawna wartosc: ");
        }
    u=0;

    }while(1);
}
