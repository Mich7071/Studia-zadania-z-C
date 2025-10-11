/*Zadanie główne
Na wzgórzu, gdzie od wieków spotykają się mistrzowie magii, dochodzi do pojedynku. Dwóch czarodziejów staje naprzeciw siebie: jeden kierowany przez Ciebie, drugi sterowany przez moc tajemniczej maszynerii. Każdy z nich ma w zanadrzu trzy potężne zaklęcia: Ognistą Kulę, która spala wszystko na swojej drodze, Lodową Strzałę, zdolną zatrzymać nawet najszybszy ruch, oraz Błyskawicę, przecinającą powietrze z hukiem i siłą burzy.

Tylko jedno zaklęcie może zwyciężyć w tej krótkiej walce — ogień topi lód, lód zatrzymuje błyskawicę, a błyskawica rozprasza ogień. Jeśli obaj czarodzieje wybiorą tę samą moc, energia zderzy się i pojedynek zakończy się remisem.

Twoim zadaniem jest napisać program w języku C, który przeprowadzi taki pojedynek. Gracz powinien wprowadzić swój wybór, a komputer wylosować zaklęcie. Program powinien następnie wyświetlić oba wybory i ogłosić wynik starcia.

Aby rozwiązać to zadanie, przydadzą się:

instrukcje printf i scanf do obsługi wejścia/wyjścia,
funkcje losujące rand() i srand(time(NULL)) z biblioteki <stdlib.h> i <time.h>,
instrukcja warunkowa if do sprawdzenia, kto wygrał.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //losowanie
    srand(time(NULL));
    int los=rand()%3 +1;


    //wybor uzytkowanika
    int w;
    printf("Wybierz swoj czar: \n"
           "1.Ognista Kula\n"
           "2.Lodowa Strzala\n"
           "3.Blyskawica\n");

    if (scanf("%d",&w)!=1 || (w<1 || w>3)){
        printf("Zle dane!");
        return 1;
    }

    printf("\n");

    //co wybral mag
    if(w==2) printf("mag wybral Lodowa Strzala a ");
    else if(w==1) printf("mag wybral Ognista Kula a ");
    else if(w==3) printf("mag wybral Blyskawica a ");

    //co wybrala maszyna
    if(los==2) printf("maszyneria wybral Lodowa Strzala.\n\n");
    else if(los==1) printf("maszyneria wybral Ognista Kula.\n\n");
    else if(los==3) printf("maszyneria wybral Blyskawica.\n\n");

    //kto wygral
    if(los==w) printf("remis!\n");
    else if(los==2 && w==3 || los==1 && w==2 || los==3 && w==1) printf("maszyneria wygrala!\n");
    else printf("mag wygral!\n");

    return 0;
}

