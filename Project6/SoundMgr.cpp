#include "stdafx.h"
#include "SoundMgr.h"

void SoundMgr::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szPlaye[256] = L"../Sound/";

	lstrcatW(szPlaye, pFileName);

	if (!loop)
	{
		sndPlaySoundW(szPlaye, SND_ASYNC | SND_NOSTOP);
	}
	else if (loop)
	{
		sndPlaySoundW(szPlaye, SND_ASYNC | SND_LOOP | SND_NOSTOP);
	}
}

void SoundMgr::Stop()
{
	sndPlaySoundW(nullptr, SND_ASYNC);
}

