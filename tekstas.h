//
// Created by artk on 4/22/2019.
//

#ifndef LIEPA_TEKSTAS_H
#define LIEPA_TEKSTAS_H

#define MAXLEN 1024

#define Regina 0
#define Aiste 1
#define Edvardas 2
#define Vladas 3
void write_Balabolka()
{
    greicio_koeficientas = 200;
    SetConsoleOutputCP(1257);

    sound_Init( Regina );sound_Save( "D:/AAA/syllogism/Fresison/0101.wav", "visi kompetetingi þmonës" );sound_Destroy();sound_Init( Aiste );sound_Save( "D:/AAA/syllogism/Fresison/0102.wav", "nepriklauso klystantiems" );sound_Destroy();sound_Init( Edvardas );sound_Save( "D:/AAA/syllogism/Fresison/0103.wav", "keletas klystanèiø þmoniø" );sound_Destroy();sound_Init( Vladas );sound_Save( "D:/AAA/syllogism/Fresison/0104.wav", "priklauso èia dirbantiems" );sound_Destroy();sound_Init( Edvardas );sound_Save( "D:/AAA/syllogism/Fresison/0105.wav", "keletas èia dirbanèiø þmoniø" );sound_Destroy();sound_Init( Aiste );sound_Save( "D:/AAA/syllogism/Fresison/0106.wav", "nepriklauso kompetetingiems" );sound_Destroy();

    printf( "\nPADARYTA\n");
}

#endif //LIEPA_TEKSTAS_H
