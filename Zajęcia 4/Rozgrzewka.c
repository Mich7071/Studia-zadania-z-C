/*W Akademii Magii im. Gedeona Szkarłatnego, gdzie od stuleci uczniowie uczą się sztuki przemiany pustki w złoto, trwa właśnie nocna sesja laboratoryjna. Twoim zadaniem jest stworzenie programu wspomagającego młodego adepta, który nadzoruje swoje mikstury - ich składniki, efekty i moc działania.
Program powinien zarządzać zestawem mikstur, przechowywanych w tablicy. Dla uproszczenia przyjmujemy, że:

maksymalna liczba mikstur to np. 10,
każda mikstura ma tylko jeden parametr - moc (liczbę typu double) przechowywane w tablicy jednowymiarowej,
do każdej mikstury przypisany jest stopień ewentualnych zanieczyszczeń (może wynosić 0) przechowywany jako tablica liczb całkowitych.
W funkcji main() powinna znaleźć się główna pętla programu obsługująca menu, które pozwala użytkownikowi:

dodać nową miksturę,
obliczyć średnią moc,
znaleźć najsilniejszą miksturę,
wzmocnić wszystkie mikstury,
ustabilizować wybraną miksturę,
oczyścić miksturę z zanieczyszczeń,
zakończyć działanie programu.
W main() powinny znajdować się tylko podstawowe wywołania - cała logika programu ma być realizowana w osobnych funkcjach opisanych poniżej.

void showIntro();
Wyświetla wprowadzenie do programu — tytuł, krótki opis, autora, itp.

int showMenu();
Wyświetla menu dostępnych opcji. Pobiera wybór użytkownika i zwraca numer wybranej opcji. Nie przyjmuje parametrów.
Powinna walidować dane wejściowe:

jeśli użytkownik poda coś, co nie jest liczbą, prosi o ponowne wprowadzenie,
jeśli wybór nie mieści się w zakresie dostępnych opcji, informuje o tym i pyta ponownie.
double brewPotion(double ingredientA, double ingredientB);
Symuluje proces tworzenia nowej mikstury z dwóch składników.
Zwraca "moc mikstury" - liczbę zmiennoprzecinkową obliczaną według prostego wzoru:
    moc = (ingredientA * 0.6 + ingredientB * 0.4) * randomValue
gdzie randomValue jest losową liczbą z przedziału (0; 1>

double averagePower(double potions[], int n);
Przyjmuje tablicę z mocami mikstur oraz ich liczbę, a następnie oblicza i zwraca średnią moc wszystkich zapisanych mikstur.

int findStrongest(double potions[], int n);
Zwraca indeks mikstury o największej mocy. Przyjmuje tablicę z mocami mikstur oraz ich liczbę.

void strengthenAll(double potions[], int n);
Przyjmuje tablicę mikstur i zwiększa ich moc, np. o 10% każdej z wartości.

void stabilizePotion(double *power);
Przyjmuje jako parametr wskaźnik na wartość mocy danej mikstury.
Stabilizuje ją wg schematu:

jeśli moc jest zbyt duża (np. > 100) - zmniejszao 20%,
jeśli zbyt niska (np. < 10) - zwiększa o 50%.
void purifyPotion(double *power, int *impurities);
Przyjmuje w parametrach wskaźniki na zmienne przechowujące moc i poziom zanieczyszczeń danej mikstury.
Oczyszcza moc z zanieczyszczeń poprzez:

zmniejszenie liczby zanieczyszczeń (*impurities) o 2,
zwiększenie mocy mikstury (*power) o 5%. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showIntro();
int showMenu();
double brewPotion(double ingredientA, double ingredientB);
double averagePower(double potions[], int n);
int findStrongest(double potions[], int n);
void strengthenAll(double potions[], int n);
void stabilizePotion(double *power);
void purifyPotion(double *power, int *impurities);

int main() {
    double mikstury [10]={13,27,84,31,71,54,14,42,79,10},srednia=0.0;
    int zanieczyszczenia[10]={15,26,36,15,37,15,11,9,5,1}, x,y=0, ile=10,naja,wybor;
    double wybor1,wybor2;
    srand(time(NULL));
    showIntro();

    while (1) {
        x=showMenu();

        switch (x) {
            case 1:
                printf("Jak mocne skladniki chcesz dodac (od 0 do 100 )");

                while (scanf("%lf %lf",&wybor1, &wybor2) != 2 || wybor1>100 || wybor2>100 || wybor1<0 || wybor2<0 ) {
                    printf("Blad!\n podaj poprawne wybory: ");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
                mikstury[y] = brewPotion(wybor1 , wybor2);
                zanieczyszczenia[y]=rand()%100;
                y++;

                if (y==10) {
                    y=0;
                }
                break;

            case 2:
                srednia=averagePower(mikstury,ile);
                printf("\nsrednia moc: %.2lf\n",srednia);
                break;

            case 3:
                naja=findStrongest(mikstury,ile);
                printf("\nMikstura z najwiksza moca ma indeks: %d\n",naja+1);
                break;

            case 4:
                strengthenAll(mikstury, ile);
                printf("\nZwiekszylem o 10%\n");
                break;

            case 5:
                printf("\nJaka miksture chcesz ustablilizowac (1-10): \n");
                if (scanf("%d",&wybor) !=1 || wybor>10 || wybor<1) {
                    printf ("zly wybor!");
                    while (getchar() != '\n');
                    break;
                }
                stabilizePotion(&mikstury[wybor-1]);
                printf("\nUstabilizowano\n");
                break;

            case 6:
                printf("\nKtora miksture chcesz oczyscic  (1-10): \n");
                if (scanf("%d",&wybor) !=1 || wybor>10 || wybor<1) {
                    printf ("zly wybor!");
                    while (getchar() != '\n');
                    break;
                }
                purifyPotion(&mikstury[wybor-1], &zanieczyszczenia[wybor-1]);
                printf("\nOczyszcono\n");
                break;

            case 7:
                return 0;
        }
    }
}


void showIntro() {
    printf("\nAkademii Magii\n\n(Program dla poczatkujacych magikow)\nAutor: Michał\n");
}

int showMenu() {

    printf("\n1.Dodaj nowa miksture\n"
                "2.oblicz srednia moc\n"
                "3.znajdz najsilniejsza miksture\n"
                "4.wzmocnij wszystkie mikstury\n"
                "5.ustabilizuj wybrana miksture\n"
                "6.oczysc miksture z zanieczyszczen\n"
                "7.zakoncz dzialanie programu\n");

    int wybor;
    printf("\nKtora opcje wybierasz: ");
    while (scanf("%d",&wybor) != 1 || wybor>7 || wybor<1 ) {
        printf("Blad!\n podaj poprawny wybor: ");
        while (getchar() != '\n');
    }

    return wybor;
}

double brewPotion(double ingredientA, double ingredientB) {

    double random=(rand()%100+1)/100.0;
    double moc = (ingredientA * 0.6 + ingredientB * 0.4) * random;
    return moc;

}

double averagePower(double potions[], int n) {
    double srednia=0.0;
    for(int i=0;i<n;i++) {
        srednia+=potions[i];
    }
    return srednia/n;
}

int findStrongest(double potions[], int n){
    double naj=potions[0];
    int index=0;

    for(int i=1;i<n;i++){
        if(potions[i]>naj){
            naj=potions[i];
            index=i;
        }
    }
    return index;
}

void strengthenAll(double potions[], int n) {

    for(int i=0;i<n;i++) {
        potions[i]*=1.10;
    }
}

void stabilizePotion(double *power) {
    if (*power>100) {
        *power*=0.80;
    }else if (10>*power) {
        *power*=1.5;
    }
}

void purifyPotion(double *power, int *impurities) {

    if (*impurities<=1) {
        printf("Mikstura jest juz czysta!");
        return;
    }else {
        *impurities-=2;
        *power*=1.05;
    }
}