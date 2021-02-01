#include "stdafx.h"
#include "Hp2.h"

Hp2::Hp2()
{
	m_Hp2 = Sprite::Create(L"Painting/Bar3.png");
	m_Hp2->SetParent(this);

	m_Bar = Sprite::Create(L"Painting/HpBar.png");
	m_Bar->SetParent(this);


	SetPosition(420, 65);


}

void Hp2::Update(float deltatime, float time)
{
	m_Hp2->m_Position.x = 89;
	m_Hp2->m_Position.y = -1;
}

void Hp2::Render()
{
	m_Hp2->Render();
	m_Bar->Render();




	SetRect(
		&m_Hp2->m_Collision,
		m_Hp2->m_Position.x - m_Hp2->m_Size.x / 2,
		m_Hp2->m_Position.y - m_Hp2->m_Size.y / 2,
		m_Hp2->m_Position.x + m_Hp2->m_Size.x / 2,
		m_Hp2->m_Position.y + m_Hp2->m_Size.y / 2
	);

	m_Hp2->m_Rect.right = m_Hp2->m_Size.x  - 700 + (HpMgr::GetInst()->m_PlayerTwoHp );

	if (m_Hp2->m_Rect.right <= 0)
	{
		HpMgr::GetInst()->DieHpBar(0);
	}

}
