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


char g_Tekstas[] = { "Pirminës kokybës nuo kûnø." };


char *_02_08_07[/*8*/] = {
        {"Idëja yr objektas nuo màstymo."},
        {"Kiekvienas þmogus bûdamas sàmoningas sau paèiam kad jis màsto ir tas kuris jo siela yra pritaikoma apie tarpu màstant bûsianèios idëjos kad yra tenais"},
        {"tai yra praeita abjoti kad þmonës turi viduje jø sielø keleta idëjø,"},
        {"tokios kaip yra tos iðreikðtos per þodþius baltumas, kietumas, girtumas ir kitos"},
        {"tai yra viduje pirmos vietos tada bûti iðtirta, kaip jis ateina per jas?"},
        {"Að þinau tai yra priimta doktrina, kad þmonës turi ágimtas idëjas, ir originalius þenklus áspaustus link jø sielø viduje jø labai pirmo buvimo."},
        {"Ðià nuomonæ að turiu didumoje iðyræs jau,"},
        {"að spëju kà að turiu pasakæs viduje aknstesnës knygos bus labiau daugiau lengvai pripaþinta"},
        {"kada að turiu parodæs ið kur supratimas gali gauti visas idëjas jis turi"},
        {"ir per kokius kelius ir laipsnius jie gali ateiti á sielà"},
        {"dël kurio að apeliuoju á kiekvieno vieno stebëjimà ir patirtá"},
};


char *_02_08_07__[/*8*/] = {
        {"Savæs prieþastimi laikau tai, kieno esmëje glûdi egzistavimas; kitaip tariant, tai, kieno prigimtis gali bûti suvokiama tik kaip egzistuojanti."}
};


char *_02_08_07_[/*8*/] = {
        {"Idëjos viduje sielos, kokybës viduje kûnø."},
        {"Atskleisti prigimtá nuo mûsø idëjø geriau, ir kalbëti nuo jø suprantamai."},
        {"tai bus patogu atskirti jas kaip jos yra idëjos arba suvokimai viduje mûsø sielø."},
        {"ir kaip jos yra modifikacijos nuo materijos viduje kûnø kad prieþastis tokiø suvokimø viduje mûsø."},
        {"kad taip mes galëtume ne galvoti kad jos yra tikslûs atvaizdai ir atspindþiai nuo kaþko bûdingo viduje subjekto."},
        {"dauguma nuo tø nuo jutimo esanèiø viduje sielos ne daugiau panaðumas nuo kaþko egzistuojanèio iðorëje mûsø."},
        {"negu vardai kad stovi dël jø yra panaðumas nuo mûsø idëjø."},
        {"kurios dar link girdëjimo jos yra linkusios suþadinti viduje mûsø."}
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