//Na pierwszym semestrze student uzyskuje oceny z kilku przedmiotów, które można zapisać w postaci tablicy liczbowej. Napisz program, który wczyta wszystkie oceny studenta i zapisze je w tablicy (do uzyskania jest maksymalnie 14 ocen). Przyjmujemy, że oceny są wystawiane w skali od 2 do 5, gdzie 2 oznacza ocenę niedostateczną, a 5 bardzo dobrą. Każdą ocenę należy wczytywać do skutku, dopóki użytkownik nie poda poprawnej wartości z tego zakresu. Po wczytaniu wszystkich danych program powinien obliczyć i wyświetlić średnią ocen, najwyższą i najniższą ocenę oraz policzyć, ile razy wystąpiła ocena niedostateczna (2) i bardzo dobra (5). Wyniki należy wypisać w czytelnej formie, z odpowiednimi opisami poszczególnych wartości.

#include <stdio.h>

int main()
{
    int oceny[14];
    int i=0,max=2,min=5;
    int ile_p=0,ile_d=0;
    float p=0.0;

    //Zapisywanie liczb
    printf("Podaj 14 ocen: \n");

    while (i<14){
        if(scanf("%d",&oceny[i]) !=1){
            printf("zle dane \n");
            while (getchar() != '\n');
            continue;
        }

        if(oceny[i]<2 || oceny[i]>5){
            printf("zla wartosc");
            continue;
        }
        else{
            p=p+(float)oceny[i];
            if(oceny[i]==5) ile_p=ile_p+1;
            if(oceny[i]==2) ile_d=ile_d+1;
            if(max<oceny[i]) max=oceny[i];
            if(min>oceny[i]) min=oceny[i];
            i=i+1;
        }
    }

    //wypisywanie wynikow
    p=p/14.0;
    printf("Srednia ocen: %.2f\n",p);

    printf("ile dwojek: %d\n",ile_d);
    printf("ile piatek: %d\n",ile_p);
    printf("maksymalna ocena %d\n",max);
    printf("minimalna ocena %d\n",min);

    return 0;
}

