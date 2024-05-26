// redakView.cpp : implementation of the CRedakView class
//
#include "stdafx.h"

#include "LithUSS.h"
#include "raw2wav.h"
#include "getLUSSErrorMessages.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////
// CRedakView


char *katvardai[4] = { "C:\\Users\\4artu\\Liepa\\programos\\Regina\\", "C:\\Users\\4artu\\Liepa\\programos\\Edvardas\\", "C:\\Users\\4artu\\Liepa\\programos\\Aiste\\", "C:\\Users\\4artu\\Liepa\\programos\\Vladas\\" };
int greicio_koeficientas = 100;
int tono_koeficientas = 100;

char* getLUSSErrorMessages(int);

BOOL NeedWord;
struct event *evarr;
int balsas;
int dwBufLen;
int evsize;
unsigned int largebufsize;
short *largebuf;
HGLOBAL hData;

//////////////////////////////////////////////////////////////////
// CRedakView construction/destruction
void sound_Init( int balsoNumeris )
{
	NeedWord = FALSE;
	balsas = balsoNumeris; //0-Regina, 1-Aiste 2-Edvardas 3-Vladas
	dwBufLen = 5000000;
	evsize = 10000;
	evarr = (struct event*)malloc(evsize * sizeof(struct event));

	largebufsize = 50000000;
	largebuf = (short*)malloc(largebufsize * sizeof(short)); //sintezuotas signalas

	//----------------------------------------------------
	/*
	if (loadLUSS("LithUSS.dll") == FALSE)
	{
		printf("Klaida pakraunant LithUSS.dll"); exit(EXIT_FAILURE);
	}
	*/
	int res;
	if ((res = initLUSS("C:\\Users\\4artu\\Liepa\\programos\\", katvardai[balsas])) < 0)
	{
		printf(getLUSSErrorMessages(res)); exit(EXIT_FAILURE);
	}

	if ((hData = GlobalAlloc(GMEM_MOVEABLE | GMEM_SHARE, dwBufLen)) == NULL)
	{
		printf("Nepavyko isskirti atminties"); exit(EXIT_FAILURE);
	}
	
}

//-------------------------------------------------------------------------------------------
void sound_Save( char *wavName, char *tekstas)
{
	unsigned int ib = 0;
	int ie;
	int n, ilg;
	FILE *fr;
	int hr = 0;

	//tekstas[0] = 0;


	if (strlen(tekstas)>0)
	{

		ib = largebufsize;
		ie = evsize;
		for (int i2 = 0; i2<ib; i2++) largebuf[i2] = 0;
		hr = synthesizeWholeText(tekstas, largebuf, &ib, evarr, &ie, greicio_koeficientas, tono_koeficientas);

		if (hr<0)
		{
			printf("Klaida funkcijoje synthesizeWholeText");
			exit(EXIT_FAILURE);
		}
	}

	if ((hr == 0) && (ib>0))
	{
		if ((fr = fopen(wavName, "wb")) == 0)
		{
			printf("Nepavyko atidaryti wav failo");
			exit(EXIT_FAILURE);
		}

		n = raw2wav(ib, fr, largebuf);
		fclose(fr);
	}
}

//-----------------------------------------------------------------

void sound_Destroy()
{
	/*
	if (waveOutReset(hwo) != MMSYSERR_NOERROR)
	{
		printf("Nepavyko nutildyti wave audio irenginio"); exit(EXIT_FAILURE);
	}

	if (waveOutClose(hwo) != MMSYSERR_NOERROR)
	{
		printf("Nepavyko uzdaryti wave audio irenginio"); exit(EXIT_FAILURE);
	}
	*/
	if (GlobalFree(hData) != NULL)
	{
		printf("Nepavyko atlaisvinti atminties"); exit(EXIT_FAILURE);
	}

	free(evarr);
	free(largebuf);
	//unloadLUSS();
}

//-------------------------------------------------------------------
/*
void Skaityti(char *Zodis)
{
	char tekstas[10000];

	strcpy(tekstas, Zodis);

	if (strlen(tekstas) == 0)
	{
		NeedWord = FALSE;
	}
	else //if(strlen(tekstas)>0)
	{
		if (ikie >= evsizet - 1)
		{
			if (cff == NULL) cff = (CMainFrame*)GetActiveWindow();
			cff->OnGreitis();
			cff->OnTonas();
			largebufsizet = largebufsize;
			evsizet = evsize;
			for (int i1 = 0; i1<largebufsizet; i1++) largebuf[i1] = 0;
			int hr = synthesizeWholeText(tekstas, largebuf, &largebufsizet, evarr, &evsizet, greicio_koeficientas, tono_koeficientas);
			if (hr<0)
			{
				MessageBox("Klaida funkcijoje synthesizeWholeText"); exit(EXIT_FAILURE);
			}
			nuoe = 0;
		}
		else
		{
			nuoe = ikie;
		}

		whdr.lpData = (LPSTR)GlobalLock(hData);
		if (whdr.lpData == NULL)
		{
			MessageBox("Nepavyko apsaugoti atminties"); exit(EXIT_FAILURE);
		}
		whdr.dwFlags = 0;                 // papr. irasys WHDR_PREPARED ar WHDR_DONE

		ikie = nuoe + 1;
		if (evsizet>0)
		{
			while ((ikie < evsizet) && ((evarr[ikie].Id > 1) || (evarr[nuoe].charOffset == evarr[ikie].charOffset))) ikie++;
			if (ikie >= evsizet) ikie = evsizet - 1;
			GetEditCtrl().SetSel(nuo + evarr[nuoe].charOffset, nuo + evarr[ikie].charOffset);

			memcpy(whdr.lpData, &largebuf[evarr[nuoe].signOffset], (evarr[ikie].signOffset - evarr[nuoe].signOffset)*sizeof(short));
			whdr.dwBufferLength = (evarr[ikie].signOffset - evarr[nuoe].signOffset)*sizeof(short);
		}
		else
		{
			memcpy(whdr.lpData, largebuf, 2 * sizeof(short));
			whdr.dwBufferLength = 2 * sizeof(short);
		}

		if (waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR)) != MMSYSERR_NOERROR)
		{
			MessageBox("Nepavyko paruosti wave antrastes"); exit(EXIT_FAILURE);
		}

		if (waveOutWrite(hwo, &whdr, sizeof(WAVEHDR)) != MMSYSERR_NOERROR)
		{
			MessageBox("Nepavyko isvesti wave signalo"); exit(EXIT_FAILURE);
		}

		NeedWord = TRUE;
	}
}
*/
//----------------------------------------------------------------
/*
BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{

		WAVEFORMATEX wf;

		wf.wFormatTag = WAVE_FORMAT_PCM;     // ==1
		wf.nChannels = 1;                    // 1-mono, 2-stereo
		wf.nSamplesPerSec = 22050;			// diskretizavimo daznis
		wf.wBitsPerSample = 16;
		wf.nBlockAlign = wf.wBitsPerSample / 8 * wf.nChannels;
		wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
		wf.cbSize = 0;                       // papildomos inf. nereikia

		if (waveOutOpen(&hwo, WAVE_MAPPER, &wf, (DWORD)m_hWnd, 0,
			WAVE_ALLOWSYNC | CALLBACK_WINDOW) != MMSYSERR_NOERROR)
		{
			MessageBox("Nepavyko atidaryti wave audio irenginio"); exit(EXIT_FAILURE);
		}

		return RetVal;
	
}
*/


