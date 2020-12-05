#include "main.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


void DLL_EXPORT unos_osoba(char *putanja)
{
    // ucitaj fajl na putanji, u write modu
    FILE *f = fopen(putanja, "w");
    // varijabla za unos sa konzole
    char imeIPrezime[40];
    // sve dok unos nije jednak reci kraj
    while(true)
    {
        // unesi kroz konzolu
        gets(imeIPrezime);
        // ako je sa konzole uneto kraj, prekini loop
        if(strcmp(imeIPrezime, "kraj") == 0)
        {
            break;
        }
        // unosi u fajl
        fprintf(f, "%s\n", imeIPrezime);
    }
    // zatvori fajl
    fclose(f);
}

int DLL_EXPORT brojKarakteraUFajlu(int tipBrojanja, char *putanja)
{
     // ucitaj fajl na putanji, u write modu
    FILE *f = fopen(putanja, "r");
    char text[100];
    int rezultat = 0;
    while(fscanf(f, "%s", text) != EOF)
    {
        rezultat += brojKarakteraUReci(tipBrojanja, text, strlen(text));
    }
    fclose(f);

    return rezultat;
}

int brojKarakteraUReci(int tipBrojanja, char *rec, int duzinaReci)
{
        int i = 0, rezultat = 0;
        for(i = 0; i < duzinaReci; i++)
        {
            if(tipBrojanja == 1 && (tolower(rec[i]) == 'a' || tolower(rec[i]) == 'e' || tolower(rec[i]) == 'i' || tolower(rec[i]) == 'o' || tolower(rec[i]) == 'u'))
            {
                rezultat++;
            } else if(tipBrojanja == 2)
            {
                rezultat++;
            }
        }

        return rezultat;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
