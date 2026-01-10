#include <stdio.h>
#include <stdlib.h>
#define N 6

void showIntro(void) {printf("Witam,\nPrzebywasz aktualnie na Orion One z systemem od Michala Michalczuka.\n\n");}
int showMenu();
void readSensors(double sensors[], int n);
void displaySensors(double sensors[], int n);
void calibrateSensors(double sensors[], int n, double offset);
int findFaultySensor(double sensors[], int n, double minAllowed, double maxAllowed);
void modifySensor(double sensors[], int n, int index);
int readValue(double *value, double min, double max);

int walidacja;

int main()
{
    int opcja=0,n=6; double czujniki [N],kalibracja=-20.0;
    showIntro();

    while(1){
        switch (opcja){

            case 1:
                readSensors(czujniki, n);
                opcja=-1;
                break;

            case 2:
                displaySensors(czujniki, n);
                opcja=-1;
                break;

            case 3:
                calibrateSensors(czujniki, n, kalibracja);
                opcja=-1;
                break;

            case 4:
                int x=findFaultySensor(czujniki, n, -200, 300);
                if(x==-1){printf("\nWszystkie ok\n");opcja=-1;break;}
                printf("Uszkodzony czujnik nr: %d",x+1);

                opcja=-1;
                break;

            case 5:
                printf("\n\nPodaj jaki czujnik chcesz zmienic: ");
                int index=0;

                while(1){
                    if(scanf("%d",&index) != 1 || index>6 || index<1){
                        printf("\nzla wartosc! Podaj poprawny nr: \n");
                        while (getchar() != '\n');
                        continue;
                    }else break;
                }

                modifySensor(czujniki, n, index);

                opcja=-1;
                break;

            case 6:
                return 0;

            default:
                opcja = showMenu();

        }

    }




    return 0;
}

int showMenu(){

    int opcja;
    printf("\nMenu: "
           "\n1.wczytanie danych z czujnikow."
           "\n2.wyswietlenia odczytow."
           "\n3.przeprowadzenia kalibracji."
           "\n4.naprawienia blednych odczytow."
           "\n5.modyfikacji pojedynczego odczytu."
           "\n6.zakonczenia dzialania programu.\n");


    if (scanf("%d",&opcja) !=1 || opcja<1 || opcja>6){
        printf("Zle dane!\n");
        return -1;
    }

    return opcja;
}


void readSensors(double sensors[], int n){
    printf("\nPobieranie danych: \n\n");

    for (int i=0;i<n;)
    {
        printf("Wartosc %d: \n",i+1);
        if(scanf("%lf", &sensors[i]) != 1){
            printf("zla wartosc!\n");
            while (getchar() != '\n');
            continue;
        }else {
            walidacja = readValue(&sensors[i], -100.0, 200.0);
            if (walidacja != 1) {
                printf("Zla wartosc przedial od -100 do 200!\n");
                continue;
            }else i++;
        }


    }
}


void displaySensors(double sensors[], int n){
    printf("\nDane Pomiarowe:\n");
    for(int i=0;i<n;i++){
        printf("%.1f\n",sensors[i]);
    }
    printf("________________________\n\n");
}


void calibrateSensors(double sensors[], int n, double offset){
    printf("\nKalibrowanie:\n");
    for(int i=0;i<n;){
        sensors[i]=sensors[i]-20;

        walidacja = readValue(&sensors[i], -100.0, 200.0);
        if (walidacja != 1) {
            sensors[i]+=20;
            printf("(maksymalny do skalibrowanmia) ");
        }
        printf("Sensor %d: %.1f\n",i,sensors[i]);
        i++;
    }
    printf(".............................\n\n");
}


int findFaultySensor(double sensors[], int n, double minAllowed, double maxAllowed){

    for(int i=0;i<n;i++){

        if(sensors[i]>maxAllowed || sensors[i]<minAllowed ) return i;
    }
    return -1;
}


void modifySensor(double sensors[], int n, int index) {
    printf("\nNumer czujnika: %d\n\nAktualny poziom: %f",index,sensors[index-1]);
    printf("\nPodaj nowa wartosc: ");

    double p;

    while(1) {
        if(scanf("%lf", &p) != 1 ){
            printf("\nZle dane: \n");
            while (getchar() != '\n');
            continue;
        }else {
            walidacja = readValue(&p, -100.0, 200.0);
            if (walidacja != 1) {
                printf("Zla wartosc przedial od -100 do 200!\n");
                continue;
            }
            break;
        }
    }
        sensors[index-1]=p;

}


int readValue(double *value, double min, double max){

    if (*value < -100.0 || 200 < *value ) {
        return 0;
    }return 1;

}
