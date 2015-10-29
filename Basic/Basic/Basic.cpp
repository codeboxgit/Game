// Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <fmod.h>

int g_nFrameCount;
FMOD_SYSTEM *g_System;
FMOD_SOUND *g_Sound;

void Init()
{
	g_nFrameCount = 0;

	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(g_System, "run.wav", FMOD_DEFAULT, 0, &g_Sound);
}

void Update()
{
}

void Render()
{
}

void Release()
{
	FMOD_Sound_Release(g_Sound);
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t CurTime, OldTime;
	int nKey;
	FMOD_CHANNEL *channel;
	float volumn = 0.5;

	Init();

	OldTime = clock();

	while(1)
	{
		if (_kbhit())
		{
			nKey = _getch();

			if (nKey == 'q')
				break;

			switch (nKey)
			{
				case 'p':
					FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound, 0, &channel);
					break;
				case 's':
					FMOD_Channel_Stop(channel);
					break;
				case 'u':
					volumn += 0.1;

					if (volumn > 1.0)
						volumn = 1.0;

					FMOD_Channel_SetVolume(channel, volumn);
					break;
				case 'd':
					volumn -= 0.1;

					if (volumn < 0.0)
						volumn = 0.0;

					FMOD_Channel_SetVolume(channel, volumn);
					break;
			}
		}

		Update();
		Render();
		FMOD_System_Update(g_System);

		while(1)
		{

			CurTime = clock();

			if (CurTime - OldTime > 33) 
			{
				OldTime = CurTime;
				break;
			}

		}

		g_nFrameCount++;
	}

	Release();

	return 0;
}

