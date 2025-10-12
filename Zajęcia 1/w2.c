/*1.2
Napisz program, który symuluje kontrolê baga¿u rejestrowanego na lotnisku. Program powinien wczytaæ wagê walizki pasa¿era i na tej podstawie wyœwietliæ odpowiedni komunikat. Jeœli podana wartoœæ jest mniejsza od zera lub wiêksza ni¿ 200 kilogramów, program powinien poinformowaæ, ¿e wprowadzono niepoprawn¹ wagê. Walizki mieszcz¹ce siê w zakresie od 0 do 23 kilogramów s¹ akceptowane bez dodatkowych op³at. Je¿eli waga przekracza 23 kilogramy, ale nie jest wiêksza ni¿ 32 kilogramy, program powinien zg³osiæ koniecznoœæ dop³aty za nadbaga¿. W przypadku walizek ciê¿szych ni¿ 32 kilogramy nale¿y wypisaæ komunikat, ¿e nie mog¹ zostaæ przyjête do odprawy.*/

#include <stdio.h>


int main()
{
    //dane
    int waga;
    printf("Podaj wage walizki(kg): ");

    if (scanf("%d",&waga) != 1  || waga<0 || waga>200)
    {
        printf("Wprowadzono niepoprawn¹ wagê");
        return 1;
    }
    //komunikat
    if(waga<=23) printf("Zaakceptowane bez dodatkowych op³at");
    else if (waga<=32) printf("koniecznoœæ dop³aty za nadbaga¿");
    else printf(" nie mog¹ zostaæ przyjête do odprawy");



    return 0;
}
