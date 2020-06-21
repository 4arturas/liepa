///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra�tija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas TextNormalization.h
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>

#ifndef __TEXTNORM_H__
#define __TEXTNORM_H__

typedef int(*PROCICC) (char *, char *);
typedef int(*PROCISSII)(char *, char*, int, int*);

extern PROCICC		initTextNorm;
extern PROCISSII	normalizeText;
extern PROCISSII	spellText;

HINSTANCE	hinstDllTN;
PROCICC		initTextNorm;
PROCISSII	normalizeText;
PROCISSII	spellText;

BOOL loadTextNorm(char* biblioteka)
{
	if (!(hinstDllTN = LoadLibrary(biblioteka))) //"TextNormalization.dll"
		return FALSE;
	initTextNorm = (PROCICC)GetProcAddress(hinstDllTN, "initTextNorm");
	normalizeText = (PROCISSII)GetProcAddress(hinstDllTN, "normalizeText");
	spellText = (PROCISSII)GetProcAddress(hinstDllTN, "spellText");

	if ((!initTextNorm) || (!normalizeText) || (!spellText))
	{
		FreeLibrary(hinstDllTN);
		hinstDllTN = NULL;
		return FALSE;
	}
	return TRUE;
}

void unloadTextNorm()
{
	if (hinstDllTN)
	{
		FreeLibrary(hinstDllTN);
		hinstDllTN = NULL;
	}
}

#endif