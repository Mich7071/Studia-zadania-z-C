/*1.2
Napisz program, kt�ry symuluje kontrol� baga�u rejestrowanego na lotnisku. Program powinien wczyta� wag� walizki pasa�era i na tej podstawie wy�wietli� odpowiedni komunikat. Je�li podana warto�� jest mniejsza od zera lub wi�ksza ni� 200 kilogram�w, program powinien poinformowa�, �e wprowadzono niepoprawn� wag�. Walizki mieszcz�ce si� w zakresie od 0 do 23 kilogram�w s� akceptowane bez dodatkowych op�at. Je�eli waga przekracza 23 kilogramy, ale nie jest wi�ksza ni� 32 kilogramy, program powinien zg�osi� konieczno�� dop�aty za nadbaga�. W przypadku walizek ci�szych ni� 32 kilogramy nale�y wypisa� komunikat, �e nie mog� zosta� przyj�te do odprawy.*/

#include <stdio.h>


int main()
{
    //dane
    int waga;
    printf("Podaj wage walizki(kg): ");

    if (scanf("%d",&waga) != 1  || waga<0 || waga>200)
    {
        printf("Wprowadzono niepoprawn� wag�");
        return 1;
    }
    //komunikat
    if(waga<=23) printf("Zaakceptowane bez dodatkowych op�at");
    else if (waga<=32) printf("konieczno�� dop�aty za nadbaga�");
    else printf(" nie mog� zosta� przyj�te do odprawy");



    return 0;
}
