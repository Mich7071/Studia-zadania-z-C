//Na pierwszym semestrze student uzyskuje oceny z kilku przedmiot�w, kt�re mo�na zapisa� w postaci tablicy liczbowej. Napisz program, kt�ry wczyta wszystkie oceny studenta i zapisze je w tablicy (do uzyskania jest maksymalnie 14 ocen). Przyjmujemy, �e oceny s� wystawiane w skali od 2 do 5, gdzie 2 oznacza ocen� niedostateczn�, a 5 bardzo dobr�. Ka�d� ocen� nale�y wczytywa� do skutku, dop�ki u�ytkownik nie poda poprawnej warto�ci z tego zakresu. Po wczytaniu wszystkich danych program powinien obliczy� i wy�wietli� �redni� ocen, najwy�sz� i najni�sz� ocen� oraz policzy�, ile razy wyst�pi�a ocena niedostateczna (2) i bardzo dobra (5). Wyniki nale�y wypisa� w czytelnej formie, z odpowiednimi opisami poszczeg�lnych warto�ci.

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
    printf("�redni� ocen: %.2f\n",p);

    printf("ile dwujek: %d\n",ile_d);
    printf("ile piatek: %d\n",ile_p);
    printf("maksymalna ocena %d\n",max);
    printf("minimalna ocena %d\n",min);

    return 0;
}
