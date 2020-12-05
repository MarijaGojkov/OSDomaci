#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    // ocekujemo da je broj argumenata 2
    // uvek postoji 1 argument koji je prvi i predstavlja putanju do fajla aplikacije
    // drugi argument ce biti putanja do fajla za upis podataka
    if(argc < 2)
    {
        // ispisi gresku
        printf("Broj parametara nije odgovarajuci\n");
        // izadji iz aplikacije sa kodom greske
        exit(EXIT_FAILURE);
    }
    // pozovi funkciju iz DLL-a sa parametrom koji je prosledjen iz konzole
    unos_osoba(argv[1]);
    int tipBrojanja;
    printf("Izaberite tip broj:\n1 - Samoglasnici\n2 - Svi karakteri\nVas izbor je:");
    scanf("%d", &tipBrojanja);
    if(tipBrojanja < 1 || tipBrojanja > 2)
    {
        printf("Nepostojeci tip brojanja");
        exit(EXIT_FAILURE);
    }

    int rezultat = brojKarakteraUFajlu(tipBrojanja, argv[1]);
    // TODO pozovi fajl u notepad
    //system("notepad");
    if(tipBrojanja == 1)
    {
        printf("Broj samoglasnika je %d", rezultat);
    }
    else
    {
        printf("Broj svih karaktera je %d", rezultat);
    }
    return 0;
}
