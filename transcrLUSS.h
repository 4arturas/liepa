///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.raðtija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas transcrLUSS.h
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>

#ifndef __TRANSCRLUSS_H__
#define __TRANSCRLUSS_H__

typedef int  (*PROCICCISSIII) (char*, char*, int, unsigned short*, unsigned short*, int*, int*, int);
typedef int  (*PROCAIC) (char*);

extern PROCICCISSIII	KircTranskr;
extern PROCAIC			initTranscrLUSS;

HINSTANCE		hinstDlltranscrLUSS;
PROCICCISSIII	KircTranskr;
PROCAIC			initTranscrLUSS;

BOOL loadTranscrLUSS(char* biblioteka)
{
	if (!(hinstDlltranscrLUSS = LoadLibrary(biblioteka))) //"transcrLUSS.dll"
		return FALSE;
	KircTranskr = (PROCICCISSIII)GetProcAddress(hinstDlltranscrLUSS, "KircTranskr");
	initTranscrLUSS = (PROCAIC)GetProcAddress(hinstDlltranscrLUSS, "initTranscrLUSS");

	if ((!KircTranskr) || (!initTranscrLUSS))
	{
		FreeLibrary(hinstDlltranscrLUSS);
		hinstDlltranscrLUSS = NULL;
		return FALSE;
	}
	return TRUE;
}

void unloadTranscrLUSS()
{
	if (hinstDlltranscrLUSS)
	{
		FreeLibrary(hinstDlltranscrLUSS);
		hinstDlltranscrLUSS = NULL;
	}
}

#endif
