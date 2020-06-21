///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra�tija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas UnitSel.h
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>

#ifndef __UNITSEL_H__
#define __UNITSEL_H__

typedef int (*PROCBIC)(char *);
typedef int (*PROCBISSSIII)(unsigned short[],unsigned short[],unsigned short[],int,unsigned int[],unsigned int*);

extern PROCBIC initUnitSel;
extern PROCBISSSIII selectUnits;

HMODULE dll_handle;
PROCBIC initUnitSel;
PROCBISSSIII selectUnits;

BOOL loadUnitSel(char* biblioteka)
{
	if (!(dll_handle = LoadLibrary(biblioteka))) //"UnitSelection.dll"
		return FALSE;
	initUnitSel = (PROCBIC)GetProcAddress(dll_handle, "initUnitSel");
	selectUnits = (PROCBISSSIII)GetProcAddress(dll_handle, "selectUnits");

	if ((!initUnitSel) || (!selectUnits))
	{
		FreeLibrary(dll_handle);
		dll_handle = NULL;
		return FALSE;
	}
	return TRUE;
}

void unloadUnitSel()
{
	if (dll_handle)
	{
		FreeLibrary(dll_handle);
		dll_handle = NULL;
	}
}

#endif