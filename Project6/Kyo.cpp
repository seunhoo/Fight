#include "stdafx.h"
#include "Kyo.h"

Kyo::Kyo()
	:m_State(State::NONE)
	,m_MoveState(MoveState::Left)
	,m_Way(true)
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
	m_LKick->AddContinueFrame(L"Painting/Kyo/Kick/",11,17);

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


	m_Player = m_LStand;
	m_Player->SetParent(this);
	m_State = State::NONE;


	m_P = Sprite::Create(L"Painting/Kyo/Sit/1.png");
	m_P->SetPosition(1920 / 2, 1080 / 2);

	SetPosition(1700, 900);





}

void Kyo::Update(float deltatime, float time)
{
	if (HpMgr::GetInst()->m_PlayerOneHp == 650)
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



	if (m_State == State::Punch || m_State == State::Kick)
	{
		ObjMgr->CollideCheck(this, "ScareCrow");
		ObjMgr->CollideCheck(this, "Kyo2");
	}




	if (INPUT->GetKey(VK_RIGHT) == KeyState::NONE && INPUT->GetKey(VK_LEFT) == KeyState::NONE)
	{
		if (m_State != State::Jump && m_State != State::Punch && m_State != State::Kick)
		{
			//m_Collision.top = m_Position.y - m_Size.y/2;
			//m_Collision.bottom = m_Position.y + m_Size.y/2;
			//m_Collision.left = m_Position.x - m_Size.x/2;
			//m_Collision.right = m_Position.x + m_Size.x/2;

			m_Player = m_LStand;
			m_State = State::NONE;
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

void Kyo::Attack()
{
	if (INPUT->GetKey(VK_NUMPAD1) == KeyState::DOWN && m_State != State::Punch && m_State != State::Jump)
	{
		m_State = State::Punch;
	}
	if (m_State == State::Punch)
	{
		HpMgr::GetInst()->AtkCheck(1);
		if (m_MoveState == MoveState::Left)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 50;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
			m_Collision.left = m_Position.x - m_Size.x / 2-10;
			m_Collision.right = m_Position.x + m_Size.x / 2 - 200;

			m_Player = m_LPunch;
		}
		if (m_MoveState == MoveState::Right)
		{

			m_Collision.top = m_Position.y - m_Size.y / 2 + 50;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 - 200;
			m_Collision.left = m_Position.x - m_Size.x / 2 + 200;
			m_Collision.right = m_Position.x + m_Size.x / 2 +10;

			m_Player = m_RPunch;
		}
		if (m_Player->m_CurrentFrame >= 4) 
		{

			m_State = State::NONE;
			m_Player->m_CurrentFrame = 0;
		}
	}

	if (INPUT->GetKey(VK_NUMPAD3) == KeyState::DOWN && m_State != State::Kick && m_State != State::Jump)
	{
		m_State = State::Kick;
	}
	if (m_State == State::Kick)
	{
		HpMgr::GetInst()->AtkCheck(1);

		if (m_MoveState == MoveState::Left)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 200;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 -15;
			m_Collision.left = m_Position.x - m_Size.x / 2 - 50;
			m_Collision.right = m_Position.x + m_Size.x / 2 - 260;

			m_Player = m_LKick;
		}
		else if (m_MoveState == MoveState::Right)
		{
			m_Collision.top = m_Position.y - m_Size.y / 2 + 200;
			m_Collision.bottom = m_Position.y + m_Size.y / 2 -15;
			m_Collision.left = m_Position.x - m_Size.x / 2 + 260;
			m_Collision.right = m_Position.x + m_Size.x / 2 + 50;

			m_Player = m_RKick;
		}

		if (m_Player->m_CurrentFrame >= 6)
		{
			m_State = State::NONE;
			m_Player->m_CurrentFrame = 0;
		}
	}

}

void Kyo::Move()
{

	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_State != State::Jump && m_State != State::Punch && m_State != State::Kick)
	{
		m_Way = false;
		m_State = State::RightMove;
		m_MoveState = MoveState::Right;
	}	
	if (m_State == State::RightMove)
	{
		m_Player = m_RMove;
		m_Position.x += 8.f;
	}

	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_State != State::Jump && m_State != State::Punch && m_State != State::Kick)
	{
		m_Way = true;
		m_State = State::LeftMove;
		m_MoveState = MoveState::Left;
	}
	if (m_State == State::LeftMove)
	{
		m_Player = m_LMove;
		m_Position.x -= 8.f;
	}

	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_State == State::Jump)
	{
		m_Player = m_RJump;
		m_Position.x += 8.f;
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_State == State::Jump)
	{

		m_Player = m_LJump;
		m_Position.x -= 8.f;
	}
	


}

void Kyo::Jump()
{
	if (INPUT->GetKey(VK_UP) == KeyState::DOWN && m_State != State::Jump && m_State != State::Punch)
	{
		m_State = State::Jump;
	}
	if (m_State == State::Jump)
	{
		m_Player = m_LJump;

		if (m_Player->m_CurrentFrame <= 2)
		{
			for (float i = 0; i < 3.8; i+=0.83f)
			{
				m_Position.y -= i;
			}
		}
		else if(m_Player->m_CurrentFrame >=3)
		{
			for (float i = 0; i < 4.4; i+=0.8f)
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
			m_State = State::NONE;
			m_Player->m_CurrentFrame = 0;

		}
	}
}



void Kyo::Render()
{

	m_Player->Render();
	m_P->Render();

}

void Kyo::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Kyo2" && HpMgr::GetInst()->m_OneAtkCheck == true)
	{
		HpMgr::GetInst()->MinusHp(3, 1);

		m_Player->R = 255;
		m_Player->G = 0;
		m_Player->B = 0;
	}
}
