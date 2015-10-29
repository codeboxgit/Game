// Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <fmod.h>

int g_nFrameCount;

void Init()
{
	g_nFrameCount = 0;
}

void Update()
{
}

void Render()
{
}

void Release()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t CurTime, OldTime;
	int nKey;

	FMOD_SYSTEM *g_System;
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

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
				case 'j':
					break;
				case 'l':
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

