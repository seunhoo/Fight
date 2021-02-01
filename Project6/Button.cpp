#include "stdafx.h"
#include "Button.h"
#include"RankMgr.h"
#include"State.h"
Button::Button(Vec2 Pos,int type)
{
	m_Button = new Animation();
	m_Button->Init(0.3f, true);
	m_Button->AddContinueFrame(L"Painting/Button/", 0, 73);
	m_Button->SetParent(this);
	SetPosition(Pos.x,Pos.y);

	SceneDirector::GetInst()->m_Fast = Fast::ONE;

	m_Type = type;
}

void Button::Update(float deltatime, float time)
{

	m_Button->Update(deltatime, time);


	if (BtMgr->m_ButtonOne == true && BtMgr->m_ButtonTwo == false && BtMgr->m_ButtonThree == false && BtMgr->m_ButtonFour == false && BtMgr->m_ButtonFive == false)
	{
		if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
		{
			if (m_Button->m_CurrentFrame < 72 && m_Button->m_CurrentFrame > 59)
			{
				if (m_Button->m_CurrentFrame > 59 && m_Button->m_CurrentFrame < 64)
				{
					RankMgr::GetInst()->AddScore(50);
					ObjMgr->KeepObject(new State(m_Position, 2), "State");
				}
				else
				{
					RankMgr::GetInst()->AddScore(100);
					ObjMgr->KeepObject(new State(m_Position, 3), "State");
				}


				if (m_Type == 0)
				{
					ObjMgr->RemoveObject(this);
				}
				else if (m_Type == 1)
				{
					BtMgr->OneFalse();
					BtMgr->TwoTrue();
					ObjMgr->RemoveObject(this);
				}

			}
			//else
			//{
			//	if (m_Type == 0)
			//	{
			//		ObjMgr->RemoveObject(this);
			//	}
			//	if (m_Type == 1)
			//	{
			//		BtMgr->OneFalse();
			//		BtMgr->TwoTrue();
			//		ObjMgr->RemoveObject(this);
			//	}
			//	ObjMgr->KeepObject(new State(m_Position, 1), "State");
			//	RankMgr::GetInst()->MinusScore(20);
			//	ObjMgr->RemoveObject(this);
			//}
		}
	}


	
	
	if (m_Button->m_CurrentFrame >= 72)
	{
		if (m_Type == 1)
		{
			BtMgr->OneFalse();
			BtMgr->TwoTrue();
		}
		ObjMgr->KeepObject(new State(m_Position, 1), "State");
		RankMgr::GetInst()->MinusScore(20);
		ObjMgr->RemoveObject(this);
	}
	
}

void Button::Render()
{
	m_Button->Render();

}
