#include <stdio.h>
#include "redakView.h"
#include "tekstas.h"
#include "logic.h"


#define Regina 0
#define Aiste 1
#define Edvardas 2
#define Vladas 3

// https://www.xn--ratija-ckb.lt/liepa/infrastrukt%C5%ABrin%C4%97s-paslaugos/elektroninio-teksto-skaitytuvas/7563
// http://liepaatnaujinimai.rastija.lt/sintezatorius/SintezesVariklis_LIEPAprojektas.zip

//char g_filePath[] = { "D:\\PROJECTS\\Liepa\\sound\\" };
char g_filePath[] = { "C:\\Users\\4artu\\Liepa\\sound\\" };


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
        {"Id�ja yr objektas nuo m�stymo."},
        {"Kiekvienas �mogus b�damas s�moningas sau pa�iam kad jis m�sto ir tas kuris jo siela yra pritaikoma apie tarpu m�stant b�sian�ios id�jos kad yra tenais"},
        {"tai yra praeita abjoti kad �mon�s turi viduje j� siel� keleta id�j�,"},
        {"tokios kaip yra tos i�reik�tos per �od�ius baltumas, kietumas, girtumas ir kitos"},
        {"tai yra viduje pirmos vietos tada b�ti i�tirta, kaip jis ateina per jas?"},
        {"A� �inau tai yra priimta doktrina, kad �mon�s turi �gimtas id�jas, ir originalius �enklus �spaustus link j� siel� viduje j� labai pirmo buvimo."},
        {"�i� nuomon� a� turiu didumoje i�yr�s jau,"},
        {"a� sp�ju k� a� turiu pasak�s viduje aknstesn�s knygos bus labiau daugiau lengvai pripa�inta"},
        {"kada a� turiu parod�s i� kur supratimas gali gauti visas id�jas jis turi"},
        {"ir per kokius kelius ir laipsnius jie gali ateiti � siel�"},
        {"d�l kurio a� apeliuoju � kiekvieno vieno steb�jim� ir patirt�"},
};


char *_02_08_07__[/*8*/] = {
        {"Sav�s prie�astimi laikau tai, kieno esm�je gl�di egzistavimas; kitaip tariant, tai, kieno prigimtis gali b�ti suvokiama tik kaip egzistuojanti."}
};


char *_02_08_07_[/*8*/] = {
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

    greicio_koeficientas = 200;
    SetConsoleOutputCP(1257);

    for ( int sentenceIndex = 0; sentenceIndex < 56; sentenceIndex++ )
    {
//        char *ptr = _02_08_07[sentenceIndex];
        char *ptr = logic[sentenceIndex];
//        sound_Init( Regina );
//        sound_Init( Vladas );
        sound_Init( Aiste );
//        sound_Init( Edvardas );
        /*if ( sentenceIndex == 0 )
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
        }*/
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
    write_Block();

//    write_Balabolka();
    return 0;
}