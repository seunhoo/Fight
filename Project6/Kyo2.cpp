#include "stdafx.h"
#include "Kyo2.h"

Kyo2::Kyo2()
	:m_State(TState::NONE)
	, m_MoveState(TMoveState::Right)
	, m_Way(true)
{



	m_LStand = new Animation();
	m_LStand->SetParent(this);
	m_LStand->Init(10, true);
	m_LStand->AddContinueFrame(L"Painting/Kyo/Stand/", 11, 15);

	m_RStand = new Animation();
	m_RStand->SetParent(this);
	m_RStand->Init(10, true);
	m_RStand->AddContinueFrame(L"Painting/Kyo/Stand/", 21, 25);

	m_LPunch = new Animation();
	m_LPunch->SetParent(this);
	m_LPunch->Init(5, true);
	m_LPunch->AddContinueFrame(L"Painting/Kyo/Punch/", 21, 25);

	m_RPunch = new Animation();
	m_RPunch->SetParent(this);
	m_RPunch->Init(5, true);
	m_RPunch->AddContinueFrame(L"Painting/Kyo/Punch/", 31, 35);

	m_LKick = new Animation();
	m_LKick->SetParent(this);
	m_LKick->Init(5, true);
	m_LKick->AddContinueFrame(L"Painting/Kyo/Kick/", 11, 17);

	m_RKick = new Animation();
	m_RKick->SetParent(this);
	m_RKick->Init(5, true);
	m_RKick->AddContinueFrame(L"Painting/Kyo/Kick/", 21, 27);

	m_LJump = new Animation();
	m_LJump->SetParent(this);
	m_LJump->Init(7, true);
	m_LJump->AddContinueFrame(L"Painting/Kyo/Jump/", 11, 17);

	m_RJump = new Animation();
	m_RJump->SetParent(this);
	m_RJump->Init(7, true);
	m_RJump->AddContinueFrame(L"Painting/Kyo/Jump/", 21, 27);

	m_RMove = new Animation();
	m_RMove->SetParent(this);
	m_RMove->Init(10, true);
	m_RMove->AddContinueFrame(L"Painting/Kyo/RunRight/", 11, 16);

	m_LMove = new Animation();
	m_LMove->SetParent(this);
	m_LMove->Init(10, true);
	m_LMove->AddContinueFrame(L"Painting/Kyo/RunLeft/", 11, 16);


	m_Player = m_RStand;
	m_Player->SetParent(this);
	m_State = TState::NONE;

	SetPosition(200, 900);





}

void Kyo2::Update(float deltatime, float time)
{
	if (HpMgr::GetInst()->m_PlayerTwoHp == 0)
	{
		ObjMgr->RemoveObject(this);
	}

	m_Player->Update(deltatime, time);
	Attack();
	Move();
	Jump();


	m_ReturnTime += dt;

	if (m_ReturnTime >= 0.08f)
	{
		m_Player->R = 255;
		m_Player->G = 255;
		m_Player->B = 255;
	}

	//printf(" Top %d Bot %d  Left %d  Right %d \n", m_Collision.top, m_Collision.bottom, m_Collision.left, m_Collision.right);

	if ((m_State == TState::Punch || m_State == TState::Kick) && HpMgr::GetInst()->m_OneAtkCheck == true)
	{
		ObjMgr->CollideCheck(this, "Kyo");
	}




	if (INPUT->GetKey('A') == KeyState::NONE && INPUT->GetKey('D') == KeyState::NONE)
	{
	
		if (m_State != TState::Jump && m_State != TState::Punch && m_State != TState::Kick)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
			m_Collision.left = m_Position.x - m_Size.x / 2 + 70;
			m_Collision.right = m_Position.x + m_Size.x / 2 - 50;

			m_Player = m_RStand;
			m_State = TState::NONE;
			if (m_Way == true)
			{
				m_Player = m_LStand;
			}
			else
			{
				m_Player = m_RStand;
			}
		}
	}


}

void Kyo2::Attack()
{
	if (INPUT->GetKey('G') == KeyState::DOWN && m_State != TState::Punch && m_State != TState::Jump)
	{
		m_State = TState::Punch;
	}
	if (m_State == TState::Punch)
	{
		HpMgr::GetInst()->AtkCheck(0);
		if (m_MoveState == TMoveState::Left)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 50;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
			m_Collision.left = m_Position.x - m_Size.x / 2 - 10;
			m_Collision.right = m_Position.x + m_Size.x / 2 - 200;

			m_Player = m_LPunch;
		}
		if (m_MoveState ==TMoveState::Right)
		{

			m_Collision.top = m_Position.y - m_Size.y / 2 + 50;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
			m_Collision.left = m_Position.x - m_Size.x / 2 + 200;
			m_Collision.right = m_Position.x + m_Size.x / 2 + 10;

			m_Player = m_RPunch;
		}
		if (m_Player->m_CurrentFrame >= 4)
		{

			m_State = TState::NONE;
			m_Player->m_CurrentFrame = 0;
		}
	}

	if (INPUT->GetKey('H') == KeyState::DOWN && m_State != TState::Kick && m_State != TState::Jump)
	{
		m_State = TState::Kick;
	}
	if (m_State == TState::Kick)
	{
		HpMgr::GetInst()->AtkCheck(0);
		if (m_MoveState == TMoveState::Left)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 200;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 15;
			m_Collision.left = m_Position.x - m_Size.x / 2 - 50;
			m_Collision.right = m_Position.x + m_Size.x / 2 - 260;

			m_Player = m_LKick;
		}
		else if (m_MoveState == TMoveState::Right)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 200;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 15;
			m_Collision.left = m_Position.x - m_Size.x / 2 + 260;
			m_Collision.right = m_Position.x + m_Size.x / 2 + 50;

			m_Player = m_RKick;
		}

		if (m_Player->m_CurrentFrame >= 6)
		{
			m_State = TState::NONE;
			m_Player->m_CurrentFrame = 0;
		}
	}

}

void Kyo2::Move()
{

	if (INPUT->GetKey('D') == KeyState::PRESS && m_State != TState::Jump && m_State !=TState::Punch && m_State != TState::Kick)
	{
		m_Way = false;
		m_State = TState::RightMove;
		m_MoveState = TMoveState::Right;
	}
	if (m_State == TState::RightMove)
	{
		m_Player = m_RMove;
		m_Position.x += 8.f;
	}

	if (INPUT->GetKey('A') == KeyState::PRESS && m_State != TState::Jump && m_State != TState::Punch && m_State != TState::Kick)
	{
		m_Way = true;
		m_State = TState::LeftMove;
		m_MoveState = TMoveState::Left;
	}
	if (m_State == TState::LeftMove)
	{
		m_Player = m_LMove;
		m_Position.x -= 8.f;
	}

	if (INPUT->GetKey('D') == KeyState::PRESS && m_State == TState::Jump)
	{
		m_Player = m_RJump;
		m_Position.x += 8.f;
	}
	if (INPUT->GetKey('A') == KeyState::PRESS && m_State == TState::Jump)
	{

		m_Player = m_LJump;
		m_Position.x -= 8.f;
	}



}

void Kyo2::Jump()
{
	if (INPUT->GetKey('W') == KeyState::DOWN && m_State != TState::Jump && m_State != TState::Punch)
	{
		m_State = TState::Jump;
	}
	if (m_State == TState::Jump)
	{
		m_Player = m_LJump;

		if (m_Player->m_CurrentFrame <= 2)
		{
			for (float i = 0; i < 3.8; i += 0.83f)
			{
				m_Position.y -= i;
			}
		}
		else if (m_Player->m_CurrentFrame >= 3)
		{
			for (float i = 0; i < 4.4; i += 0.8f)
			{
				m_Position.y += i;
			}
			if (m_Position.y >= 900)
			{
				m_Position.y = 900;
			}
		}
		if (m_Player->m_CurrentFrame >= 6)
		{
			m_State = TState::NONE;
			m_Player->m_CurrentFrame = 0;

		}
	}
}



void Kyo2::Render()
{

	m_Player->Render();

}

void Kyo2::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Kyo" && HpMgr::GetInst()->m_TwoAtkCheck == true)
	{
		HpMgr::GetInst()->MinusHp(3, 0);

		m_Player->R = 255;
		m_Player->G = 0;
		m_Player->B = 0;
	}
}
