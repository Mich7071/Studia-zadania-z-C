//Na pierwszym semestrze student uzyskuje oceny z kilku przedmiotów, które mo¿na zapisaæ w postaci tablicy liczbowej. Napisz program, który wczyta wszystkie oceny studenta i zapisze je w tablicy (do uzyskania jest maksymalnie 14 ocen). Przyjmujemy, ¿e oceny s¹ wystawiane w skali od 2 do 5, gdzie 2 oznacza ocenê niedostateczn¹, a 5 bardzo dobr¹. Ka¿d¹ ocenê nale¿y wczytywaæ do skutku, dopóki u¿ytkownik nie poda poprawnej wartoœci z tego zakresu. Po wczytaniu wszystkich danych program powinien obliczyæ i wyœwietliæ œredni¹ ocen, najwy¿sz¹ i najni¿sz¹ ocenê oraz policzyæ, ile razy wyst¹pi³a ocena niedostateczna (2) i bardzo dobra (5). Wyniki nale¿y wypisaæ w czytelnej formie, z odpowiednimi opisami poszczególnych wartoœci.

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
    printf("œredni¹ ocen: %.2f\n",p);

    printf("ile dwujek: %d\n",ile_d);
    printf("ile piatek: %d\n",ile_p);
    printf("maksymalna ocena %d\n",max);
    printf("minimalna ocena %d\n",min);

    return 0;
}
