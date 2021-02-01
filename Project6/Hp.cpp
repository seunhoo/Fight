#include "stdafx.h"
#include "Hp.h"

Hp::Hp()
{
	m_Hp2 = Sprite::Create(L"Painting/Bar3.png");
	m_Hp2->SetParent(this);

	m_Bar = Sprite::Create(L"Painting/HpBar2.png");
	m_Bar->SetParent(this);

	SetPosition(1500, 65);

}

void Hp::Update(float deltatime, float time)
{
	m_Hp2->m_Position.x = -98;
	m_Hp2->m_Position.y = -1;
}

void Hp::Render()
{

	m_Hp2->Render();
	m_Bar->Render();



	SetRect(&m_Hp2->m_Collision, m_Hp2->m_Position.x - m_Hp2->m_Size.x / 2, m_Hp2->m_Position.y - m_Hp2->m_Size.y / 2, m_Hp2->m_Position.x + m_Hp2->m_Size.x / 2, m_Hp2->m_Position.y + m_Hp2->m_Size.y / 2);

	m_Hp2->m_Rect.left = m_Hp2->m_Size.x -645 - (HpMgr::GetInst()->m_PlayerOneHp);

	printf("%d \n",  m_Hp2->m_Rect.left);
	if (m_Hp2->m_Rect.left >= 635)
	{
		HpMgr::GetInst()->DieHpBar(1);
	}

}
