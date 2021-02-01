#include "stdafx.h"
#include "SceneMain.h"
#include"SoundMgr.h"
#include"RankMgr.h"
#include"Kyo.h"
SceneMain::SceneMain()
{
	m_Sprite = new Animation();
	m_Sprite->Init(20, true);
	m_Sprite->AddContinueFrame(L"Painting/Bg", 0, 7);
	m_Sprite->SetParent(this);

	SetPosition(1920 / 2, 1080 / 2);


}

void SceneMain::Update(float deltatime, float time)
{
	m_Sprite->Update(deltatime, time);
	HpMgr::GetInst()->Update(deltatime, time);
}
 
void SceneMain::Render()
{
	m_Sprite->Render(); 


}
