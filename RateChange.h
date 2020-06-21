///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.raðtija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas RateChange.h
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#pragma once


typedef int (*PROCICICILS)(char *, int, char[][4], int *, long *, short **);
typedef int (*PROCICCILS)(char *, char[][4], int *, long *, short **);
typedef int (*PROCIIIISI)(int, int, unsigned int, short *, unsigned int);

/*extern*/ PROCICICILS change_DB_rate;
/*extern*/ PROCICCILS initRateChange;
/*extern*/ PROCIIIISI change_phoneme_rate;

HINSTANCE hinstDllRC;
BOOL loadRateChange(char* biblioteka)
{
	if (!(hinstDllRC = LoadLibrary(biblioteka))) //"RateChange.dll"
		return FALSE;

	change_DB_rate = (PROCICICILS)GetProcAddress(hinstDllRC, "change_DB_rate");
	initRateChange = (PROCICCILS)GetProcAddress(hinstDllRC, "initRateChange");
	change_phoneme_rate = (PROCIIIISI)GetProcAddress(hinstDllRC, "change_phoneme_rate");

	if ((!change_DB_rate) || (!initRateChange) || (!change_phoneme_rate))
	{
		FreeLibrary(hinstDllRC);
		hinstDllRC = NULL;
		return FALSE;
	}
	return TRUE;
}

void unloadRateChange()
{
	if (hinstDllRC)
	{
		FreeLibrary(hinstDllRC);
		hinstDllRC = NULL;
	}
}