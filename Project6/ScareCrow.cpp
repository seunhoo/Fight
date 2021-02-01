#include "stdafx.h"
#include "ScareCrow.h"

ScareCrow::ScareCrow()
	:m_Returntime(0)
{
	m_ScareCrow = Sprite::Create(L"Painting/ScareCrow.png");
	m_ScareCrow->SetParent(this);
	SetPosition(300, 900);
}

void ScareCrow::Update(float deltatime, float time)
{
	//ObjMgr->CollideCheck(this, "Kyo");

	m_Collision.top = m_Position.y - m_Size.y / 2;
	m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
	m_Collision.left = m_Position.x - m_Size.x / 2 + 70;
	m_Collision.right = m_Position.x + m_Size.x / 2 - 50;



	m_Returntime += dt;

	if (m_Returntime >= 0.08f)
	{
		m_ScareCrow->R = 255;
		m_ScareCrow->G = 255;
		m_ScareCrow->B = 255;
	}


	if (HpMgr::GetInst()->m_PlayerTwoHp <= 0)
	{
		ObjMgr->RemoveObject(this);
	}

}

void ScareCrow::Render()
{
	m_ScareCrow->Render();
}

void ScareCrow::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Kyo")
	{
		HpMgr::GetInst()->MinusHp(3, 0);

		m_ScareCrow->R = 255;
		m_ScareCrow->G = 0;
		m_ScareCrow->B = 0;
	}
}
