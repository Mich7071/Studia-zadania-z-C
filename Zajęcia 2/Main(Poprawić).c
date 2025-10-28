/*Zadanie główne - System Sterowania Statkiem „Orion One”
Napisz program symulujący terminal sterowania energią statku kosmicznego „Orion One”. System pozwala kapitanowi zarządzać poziomem energii rdzenia napędu, przechowywanym w jednej zmiennej.
Po uruchomieniu systemu należy wprowadzić liczbowy kod kapitana. Tylko jeden kod jest poprawny.
Po błędnym kodzie wyświetlany jest komunikat o nieudanej próbie logowania wraz z informacją, ile prób (z trzech możliwych) jeszcze pozostało.
Po trzech nieudanych próbach wyświetlany jest odpowiedni komunikat i program kończy działanie.
Po poprawnym logowaniu system wyświetla menu:
1 – Charge the reactor core: wczytaj dodatnią wartość i dodaj ją do poziomu energii.
2 – Discharge the reactor core: wczytaj wartość i odejmij od poziomu energii (jeśli wystarczająca).
3 – Check energy level: wyświetl aktualny poziom energii.
0 – Log out: powrót do logowania (poziom energii jest zapamiętywany przez cały czas działania programu).
Jeśli użytkownik wybierze niedostępną opcję (np. 4), program powinien o tym poinformować i ponownie wyświetlić menu.
Każdorazowo system wyświetla informację, czy operacja została wykonana prawidłowo czy też nie (ujemna wartość energii, lub zbyt duża wartość zużycia)
Dodatkowo system jest zabezpieczony przed podaniem wartości energii innej niż liczbowa - w takiej sytuacji wyświetla komunikat i ponawia wczytanie wartości (do skutku).*/

#include <stdio.h>

int moc=100;

int main() {
    while (1) {
        int i=0,haslo=1234,proba=0;//dane Logowanie
        int l=1;//menu

        //Logowanie
        while (1) {
            i+=1;
            printf("Podaj Haslo: ");

            //Sprawdzanie poprawności danych
            scanf("%d",&proba);
            if (getchar()!='\n') {
                while (getchar() != '\n');
                printf("\nZle haslo, pozostalo prob %d\n",3-i);
                if(i==3) {
                    printf("\nKoniec prob");
                    return 0;
                }
                continue;
            }


            //Sprawdzanie
            if (proba==haslo) {
                printf("\nHaslo Poprawne.\n");
                break;
            }else if(i==3) {
                printf("\nKoniec prob");
                return 0;
            }else {
                printf("\nZle haslo, pozostalo prob %d\n",3-i);
            }
        }

        //--------------------------------------------------------------------------------------
        //                                     Menu
        //--------------------------------------------------------------------------------------

        int x,wartosc;

        do {
            printf("\n1 - Charge the reactor core:\n"
                   "2 - Discharge the reactor core:\n"
                   "3 - Check energy level:\n"
                   "0 - Log out:\n");

            //wybor
            if (scanf("%d",&x) !=1) {
                printf("\n Nie ma takiej opcji\n");
                while (getchar() != '\n');
                continue;
            }

            switch (x) {

                case 1:
                    printf("Podaj wartosc mocy jaka dodac: ");

                    if (scanf("%d",&wartosc) !=1 || wartosc<0) {
                        printf("\n wartosc nie prawidlowa\n");
                        while (getchar() != '\n');
                        break;
                    }
                    moc+=wartosc;
                    printf("\nOperacja udana\n");
                    break;

                case 2:
                    printf("Podaj wartosc mocy jaka odjac: ");

                    if (scanf("%d",&wartosc) !=1 ||moc<wartosc || wartosc<0) {
                        printf("\n zbyt duża wartość zużycia lub zle dane!\n");
                        while (getchar() != '\n');
                        break;
                    }
                    moc-=wartosc;
                    printf("\nOperacja udana\n");
                    break;

                case 3:
                    printf("Aktualna wartosc energi to: %d\n",moc);
                    break;

                case 0:
                    l=0;
                    break;

                default:
                    printf("\n Nie ma takiej opcji\n");
                    break;
            }

        }while (l==1);
    }
}
