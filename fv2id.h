///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Projektas LIEPA (https://liepa.ra�tija.lt)
// Sintezatoriaus komponentas LithUSS.dll
// Failas fv�id.h
// Autorius dr. Pijus Kasparaitis (pkasparaitis@yahoo.com)
// 2015 08 11
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#define FonSk 92

#include "stdafx.h"
#include "fv2id.h"
#include <string.h>
#include "strtokf.cpp"

static struct FonVardai{char *fv; unsigned short id;} FonV[FonSk] = {
{"_", 0},
{"i", 1},
{"e", 2},
{"a", 3},
{"o", 4},
{"u", 5},
{"I", 6},
{"E", 7},
{"A", 8},
{"O", 9},
{"U", 10},
{"ii", 11},
{"Ii", 12},
{"iI", 13},
{"ie", 14},
{"Ie", 15},
{"iE", 16},
{"ee", 17},
{"Ee", 18},
{"eE", 19},
{"ea", 20},
{"Ea", 21},
{"eA", 22},
{"aa", 23},
{"Aa", 24},
{"aA", 25},
{"oo", 26},
{"Oo", 27},
{"oO", 28},
{"uo", 29},
{"Uo", 30},
{"uO", 31},
{"uu", 32},
{"Uu", 33},
{"uU", 34},
{"p",   35},
{"p\'", 36},
{"b",   37},
{"b\'", 38},
{"t",   39},
{"t\'", 40},
{"d",   41},
{"d\'", 42},
{"k",   43},
{"k\'", 44},
{"g",   45},
{"g\'", 46},
{"ts",  47},
{"ts\'",48},
{"dz",  49},
{"dz\'",50},
{"tS",  51},
{"tS\'",52},
{"dZ",  53},
{"dZ\'",54},
{"s",   55},
{"s\'", 56},
{"z",   57},
{"z\'", 58},
{"S",   59},
{"S\'", 60},
{"Z",   61},
{"Z\'", 62},
{"x",   63},
{"x\'", 64},
{"h",   65},
{"h\'", 66},
{"f",   67},
{"f\'", 68},
{"j\'", 69},
{"j",   70},
{"J",   71},
{"v",   72},
{"v\'", 73},
{"w",   74},
{"W",   75},
{"l",   76},
{"l\'", 77},
{"L",   78},
{"L\'", 79},
{"r",   80},
{"r\'", 81},
{"R",   82},
{"R\'", 83},
{"m",   84},
{"m\'", 85},
{"M",   86},
{"M\'", 87},
{"n",   88},
{"n\'", 89},
{"N",   90},
{"N\'", 91}};

char* strtokf(char*, const char*, char**);

unsigned short fv2id(char *fpav)
{
    for(int i=0; i<FonSk; i++)
        if(strcmp(fpav, FonV[i].fv)==0)
            return FonV[i].id;

    return FonV[0].id; //pauze "_"
}

char* id2fv(unsigned short id)
{
    for(int i=0; i<FonSk; i++)
        if(id == FonV[i].id)
            return FonV[i].fv;

    return FonV[0].fv; //pauze "_"
}

int trText2UnitList(char *TrSakinys, unsigned short *units, unsigned short *unitseparators)
{
    char temp[500], *pos, *newpos; //turetu pakakti 480
    strcpy(temp, TrSakinys);

    int i=0;
    pos=strtokf(temp, "+- ", &newpos);
    while(pos!=NULL)
    {
        units[i] = fv2id(pos);
        pos=strtokf(NULL, "+- ", &newpos);
        if(pos==NULL) unitseparators[i]='+';
        else unitseparators[i]=TrSakinys[pos-temp-1];
        i++;
    }

    return i;
}


