#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT unos_osoba(char *putanja);
int DLL_EXPORT brojKarakteraUFajlu(int tipBrojanja, char *putanja);
int DLL_EXPORT brojKarakteraUReci(int tipBrojanja, char *rec, int duzinaReci);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
