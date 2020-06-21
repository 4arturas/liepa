#include <stdio.h>
#include "redakView.h"
#include "tekstas.h"


#define Regina 0
#define Aiste 1
#define Edvardas 2
#define Vladas 3

//http://liepaatnaujinimai.rastija.lt/sintezatorius/SintezesVariklis_LIEPAprojektas.zip

char g_filePath[] = { "D:\\PROJECTS\\Liepa\\sound\\" };


void replace_Characters( char *txt, char from, char to )
{
    for ( int i = 0; i <= strlen(txt); i++ )
    {
        if ( txt[i] == from )
        {
            printf( "ba" );
            txt[i] = to;
        }
    }
}


char g_Tekstas[] = { "Pirmin�s kokyb�s nuo k�n�." };


char *_02_08_07[/*8*/] = {
        {"Id�jos viduje sielos, kokyb�s viduje k�n�."},
        {"Atskleisti prigimt� nuo m�s� id�j� geriau, ir kalb�ti nuo j� suprantamai."},
        {"tai bus patogu atskirti jas kaip jos yra id�jos arba suvokimai viduje m�s� siel�."},
        {"ir kaip jos yra modifikacijos nuo materijos viduje k�n� kad prie�astis toki� suvokim� viduje m�s�."},
        {"kad taip mes gal�tume ne galvoti kad jos yra tiksl�s atvaizdai ir atspind�iai nuo ka�ko b�dingo viduje subjekto."},
        {"dauguma nuo t� nuo jutimo esan�i� viduje sielos ne daugiau pana�umas nuo ka�ko egzistuojan�io i�or�je m�s�."},
        {"negu vardai kad stovi d�l j� yra pana�umas nuo m�s� id�j�."},
        {"kurios dar link gird�jimo jos yra linkusios su�adinti viduje m�s�."}
};


void write()
{
    char wavFile[200];

    greicio_koeficientas = 180;
    SetConsoleOutputCP(1257);

    sound_Init( Regina );

    sprintf( wavFile, "%s01.wav", g_filePath );
    replace_Characters( g_Tekstas, '\n', ' ' );
    replace_Characters( g_Tekstas, '\r', ' ' );
    sound_Save( wavFile, g_Tekstas );
    printf( "%s", g_Tekstas );

    sound_Destroy();
}

void file_NumberToChar( int fileNumber, char *fileName )
{
    if ( fileNumber < 10 )
    {
        sprintf( fileName, "0%d", fileNumber );
        return;
    }
    sprintf( fileName, "%d", fileNumber );
}
void write_Array()
{
    char wavFile[200];
    char fileNumber[200];

    greicio_koeficientas = 180;
    SetConsoleOutputCP(1257);

    sound_Init( Vladas );

    int arrayLength = 17;
    printf( "Array length: %d\n\n", arrayLength );
    char **txt = _02_08_07[0];
    for ( int sentenceIndex = 0; sentenceIndex < arrayLength; sentenceIndex++ )
    {
        char *ptr = txt[sentenceIndex];
        file_NumberToChar( sentenceIndex+1, fileNumber );
        sprintf( wavFile, "%s%s.wav", g_filePath, fileNumber );
        sound_Save( wavFile, ptr );
        printf( "\n%s\n", ptr );
    } // end for sentenceIndex



    sound_Destroy();
}

void write_Block()
{
    char wavFile[200];
    char fileNumber[200];

    greicio_koeficientas = 180;
    SetConsoleOutputCP(1257);

    for ( int sentenceIndex = 0; sentenceIndex < 56; sentenceIndex++ )
    {
        char *ptr = _02_08_07[sentenceIndex];
        if ( sentenceIndex == 0 )
        {
            sound_Init( Regina );

            sprintf( wavFile, "%s01.wav", g_filePath );
            sound_Save( wavFile, ptr );
            printf( "%s", ptr );

            sound_Destroy();
            continue;
        }
        if ( sentenceIndex == 1 )
        {
            sound_Init( Vladas );
        }
        file_NumberToChar( sentenceIndex+1, fileNumber );
        sprintf( wavFile, "%s%s.wav", g_filePath, fileNumber );
        sound_Save( wavFile, ptr );
        printf( "\n%s\n", ptr );
    } // end for sentenceIndex

    sound_Destroy();
}





int main()
{
//    write();
//    write_Array();
//    write_Block();

    write_Balabolka();
    return 0;
}