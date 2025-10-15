#include <stdio.h>

int main()
{
    int i=0,x=0,koniec=1,ilosc1=0,ilosc2=0,p1,p2,u=0; char w1[128],w2[128];

    //pierwsza wiadomosc
    printf("Podaj wiadomosc pierwsza: ");

    for(i=0;i<127;i=i+1){
        scanf("%c",&w1[i]);
        ilosc1=ilosc1+1;

        if(w1[i]=='\n'){
            w1[i]='\0';
            ilosc1=ilosc1-1;
            i=0;
            break;
        }
    }


    //druga wiadomosc
    printf("Podaj wiadomosc druga: ");

    for(i=0;i<127;i=i+1){
        scanf("%c",&w2[i]);
        ilosc2=ilosc2+1;

        if(w2[i]=='\n'){
            w2[i]='\0';
            ilosc2=ilosc2-1;
            i=0;
            break;
        }
    }




    do{
        printf("\n=== TERMINAL ORION ONE ===\n"
               "1. Wyswietl dlugosc obu wiadomosci\n"
               "2. Porownaj wiadomosci\n"
               "3. Polacz wiadomosci\n"
               "4. Szyfruj wiadomosc 1 (ROT13)\n"
               "5. Odwroc wiadomosc 1\n"
               "0. Zakoncz transmisje\n"
               "Wybierz opcje: ");

        if(scanf("%d",&x) !=1){
            printf("\nzle dane\n");
            while (getchar() != '\n');
            continue;
        }

        switch(x){

            case 1:
                printf("\ndlugosc pierwszej wiadomosci to %d znakow\n", ilosc1);
                printf("\ndlugosc drugiej wiadomosci to %d znakow\n\n", ilosc2);
                break;


            case 2:
                if(ilosc1 != ilosc2){
                    printf("\nWiadmomosci nie sa identyczne!\n");
                    break;
                    }
                else{
                    while(i<ilosc1){
                        p1=(int)w1[i];
                        p2=(int)w2[i];

                        if(p1 != p2 && p1+32 != p2){ //błąd
                            printf("\nWiadmomosci nie sa identyczne!\n");
                            u=1;
                            break;
                            }
                        i=i+1;
                        }
                    if(u==0){
                        printf("\nwiadmosci sa identyczne\n");
                        }

                    break;
                    }


            //case 3:






            default: printf("\nPodaj poprawna wartosc: ");
        }
    u=0;

    }while(1);

    return 0;
}

