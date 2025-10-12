#include <stdio.h>

int main()
{
    //wybor
    int rodzaj,ile;
    printf("Podaj jaki bilet chcesz wybrac oraz iloœæ sztuk:\n"
           "1.bilet normalny za 4 z³\n"
           "2.bilet ulgowy za 2 z³\n");

    if(scanf("%d %d", &rodzaj, &ile) !=2 || rodzaj>2 || rodzaj<1 || 0>ile){
        printf("zle dane");
        return 1;
    }

    int cena;
    if (rodzaj==1)  cena= 4*ile;
    else  cena=2*ile;

    //wplata
    printf("kwota do zaplaty to %d, ile wplacisz: ", cena);

    int wpl;
    if(scanf("%d", &wpl) !=1 || wpl<0){
        printf("zle dane");
        return 1;
    }

    //oplata
    if(cena==wpl) printf("wydanie biletow");
    else if(cena<wpl){
        int r=wpl-cena;
        printf("wydanie biletow, twoja reszta to %d zl",r);
    }
    else printf("zbyt niska kwota");



    return 0;
}
