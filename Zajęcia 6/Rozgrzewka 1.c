/*W automacie do kawy występuje kilka stanów pracy, które opisujemy za pomocą typu wyliczeniowego:

enum MachineState {
IDLE,        // automat oczekuje na klienta
ACCEPTING,   // przyjmuje monety
BREWING,     // parzy kawę
ERROR        // błąd (np. brak wody)
};

Napisz program, który będzie symulował działanie automatu. Program ma używać zmiennej typu enum MachineState i sterować logiką za pomocą instrukcji switch.

Wymagania:

Program rozpoczyna pracę w stanie IDLE.
Użytkownik może wybierać akcje z menu:
=== AUTOMAT DO KAWY ===
1. Włóż monetę
2. Wybierz kawę
3. Uzupełnij wodę
4. Reset błędu
0. Zakończ program
Zmiana stanów automatu:
Aktualny stan	Działanie użytkownika	Nowy stan
IDLE	włóż monetę	ACCEPTING
ACCEPTING	wybierz kawę	BREWING (automat zaczyna parzyć kawę)
BREWING	po zakończeniu parzenia	IDLE
dowolny	brak wody / awaria	ERROR (symulacja opisana poniżej)
ERROR	reset błędu	IDLE
W automacie znajduje się ograniczona ilość wody. Za każdym razem, gdy automat parzy kawę, jej poziom zmniejsza się o 1. Jeżeli spadnie do 0, automat przechodzi w stan ERROR.
W stanie ERROR żadne akcje nie działają oprócz opcji „Reset błędu”, która przywraca poziom wody do wartości początkowej oraz ustawia stan na IDLE.
Po każdej akcji automat powinien wyświetlać aktualny stan w czytelnej formie, np.: Stan: BREWING (parzenie kawy...)
*/

#include <stdio.h>



enum MachineState {
    IDLE,
    ACCEPTING,
    BREWING,
    ERROR
};

void info (enum MachineState s);
void menu();

int main() {

    int wybor, woda=3,moneta=0;
    enum MachineState status = IDLE;

    while (1) {
        info (status);
        menu();



        scanf("%d",&wybor);

        if (status == ERROR && wybor != 4) {
            printf("Opcja nie dostepna, brak wody, zresetuj!\n");
            continue;
        }

        switch (wybor) {

            case 1:
                if (status == ERROR) {
                    printf("\nERROR");
                    break;
                }else if (status == ACCEPTING) {
                    printf("konto zasilone");
                    break;
                }
                printf("Wloz monete (2): ");
                if (scanf("%d",&moneta) != 1 || moneta != 2) {
                    printf("\nZla wartosc!");
                    while (getchar() != '\n');
                    break;
                }

                status=ACCEPTING;
                break;


            case 2:
                if (status == IDLE) {
                    printf("\nZasil konto!\n");
                    break;
                }else if (status == ERROR) {
                    printf("Brak wody!\n");
                    break;
                }

                printf("Przygotowuje kawe\n");
                woda--;
                status=BREWING;

                for (double i = 0; i<500000000; i++);

                printf("\nKawa gotowa\n");
                status=IDLE;

                if (woda == 0) {
                    status=ERROR;
                }
                break;

            case 3:
                printf("Uzupelniam wode...\n");
                woda=3;
                break;

            case 4:
                if (status != ERROR) {
                    printf("Brak bledu\n");
                    break;
                }
                printf("Reset bledu....!");

                for (double i = 0; i<500000000; i++);

                status = IDLE;
                woda=3;

                break;

            case 0:
                return 0;
        }
    }
}

void menu() {
    printf("\n=== AUTOMAT DO KAWY ===\n"
           "1. Wloz monete\n"
           "2. Wybierz kawe\n"
           "3. Uzupelnij wode\n"
           "4. Reset bledu\n"
           "0. Zakoncz program\n");
}

void info (enum MachineState s) {

    switch (s) {
        case IDLE: printf("automat oczekuje na klienta\n");break;
        case ACCEPTING: printf("przyjmuje monety\n");break;
        case BREWING: printf("par zy kawę\n");break;
        case ERROR: printf("błąd (np. brak wody)\n");break;
    }
}
