#include "stdafx.h"
#include "SceneDirector.h"

void SceneDirector::Update(float deltatime, float time)
{
	INPUT->Update();
	ObjectMgr::GetInst()->Update(deltatime, time);

	if (m_CurrentScene)
		m_CurrentScene->Update(deltatime, time);
}

void SceneDirector::Render()
{
	ObjectMgr::GetInst()->Render();
	if (m_CurrentScene)
		m_CurrentScene->Render();
}

void SceneDirector::ChangeScene(Object* newScene)
{
	if (m_CurrentScene)
		SafeDelete(m_CurrentScene);

	m_CurrentScene = newScene;
}
