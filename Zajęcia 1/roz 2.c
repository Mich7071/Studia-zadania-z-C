//Napisz program, który sprawdzi, czy dwie liczby podane przez użytkownika są parzyste, nieparzyste, czy też jedna z nich jest parzysta, a druga nie. Komputer powinien na końcu wyświetlić odpowiedni komunikat, np. „Obie liczby są parzyste” albo „Jedna parzysta, druga nie”.

#include <stdio.h>

int main()
{
    //podanie i wczytanie danych
    int x,y;
    printf("Podaj dwie liczby: ");
    if(scanf("%d %d",&x,&y) != 2 ){
        printf("bledna wartosc !");
        return 1;
    }

    int a=x%2;
    int b=y%2;

    //sprawdzanie
    if (a+b==0) printf("Obie liczby sa parzyste");
    else if (a+b==1) printf("Jedna parzysta, druga nie");
    else if (a+b==2) printf("nie ma parzystch liczb");


    return 0;
}


