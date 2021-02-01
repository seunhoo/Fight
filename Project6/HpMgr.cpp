#include "stdafx.h"
#include "HpMgr.h"

void HpMgr::Update(float deltatime, float time)
{
	m_AtkCheckTime += dt;
	
	if (m_AtkCheckTime >= 0.1f)
	{
		m_OneAtkCheck = false;
		m_TwoAtkCheck = false;
		m_AtkCheckTime = 0;
	}

}

void HpMgr::ResetHp()
{
	m_PlayerOneHp = 0;
	m_PlayerTwoHp = 700;
}

void HpMgr::MinusHp(float hp, bool player)
{
	if (player)
	{
		m_PlayerOneHp += hp;
	}
	else
	{
		m_PlayerTwoHp -= hp;
	}
}

void HpMgr::PlusHp(float hp, bool player)
{
	if (player)
	{
		m_PlayerOneHp += hp;
	}
	else
	{
		m_PlayerTwoHp += hp;
	}
}

void HpMgr::DieHpBar(bool player)
{
	if (player)
	{
		m_PlayerOneHp = 650;
	}
	else
	{
		m_PlayerTwoHp = 0;
	}
}

void HpMgr::AtkCheck(bool player)
{

	if (!player)
	{
		m_OneAtkCheck = true;
	}
	else if (player)
	{
		m_TwoAtkCheck = true;
	}

}
