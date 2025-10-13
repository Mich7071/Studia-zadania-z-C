/*Napisz program, który sprawdzi, czy trzy podane przez użytkownika liczby całkowite mogą być długościami boków trójkąta prostokątnego. Liczby wprowadzane są w dowolnej kolejności. Program powinien najpierw ustalić, która z nich jest największa i potraktować ją jako przeciwprostokątną, a następnie sprawdzić, czy suma kwadratów dwóch pozostałych boków jest równa kwadratowi tej największej liczby. Jeśli warunek Pitagorasa jest spełniony, program wyświetla komunikat, że z podanych długości można zbudować trójkąt prostokątny. W przeciwnym przypadku należy poinformować, że liczby nie tworzą trójki pitagorejskiej.*/

#include <stdio.h>

int main()
{
    //wpisywanie danych
    int x,y,z;

    printf("Podaj 3 wartosci: ");

    if(scanf("%d %d %d", &x, &y, &z) !=3 || x<1 || y<1 || z<1 ){
        printf("zle dane");
        return 1;
    }

    //ustalanie wartosci
    int high, mid, low;
    if(x>y) {mid=x; low=y;}
    else {mid=y; low=x;}

    if(mid>z){high=mid; mid=z;}
    else high=z;

    //sprawdzenie
    if (high*high == mid*mid+low*low) printf("z podanych długości można zbudować trójkąt prostokątny.");
    else printf("liczby nie tworzą trójki pitagorejskiej.");

    return 0;
}

