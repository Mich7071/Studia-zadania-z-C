//Napisz program, który sprawdzi, czy dwie liczby podane przez u¿ytkownika s¹ parzyste, nieparzyste, czy te¿ jedna z nich jest parzysta, a druga nie. Komputer powinien na koñcu wyœwietliæ odpowiedni komunikat, np. „Obie liczby s¹ parzyste” albo „Jedna parzysta, druga nie”.

#include <stdio.h>

int main()
{
    //podanie i wczytanie danych
    int x,y;
    printf("Podaj dwie liczby: ");
    if(scanf("%d %d",&x,&y) != 2 ){
        printf("bledna wartosc !");
    }

    int a=x%2;
    int b=y%2;

    //sprawdzanie
    if (a+b==0) printf("Obie liczby sa parzyste");
    else if (a+b==1) printf("Jedna parzysta, druga nie");
    else printf("nie ma parzystch liczb");


    return 0;
}

