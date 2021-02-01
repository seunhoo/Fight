#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "Animation.h"  //�ִϸ��̼� �Է�


Animation::Animation()
{
	A = 255;
	R = 255;
	G = 255;
	B = 255;
}

void Animation::AddFrame(std::wstring fileName) //�ִϸ��̼� �̹����� ����°� ����.
{
	auto sprite = Sprite::Create(fileName);
	sprite->SetParent(this);   //this �� ���� ���� ���� �ƴϰ� ��ü�� �ּҸ� �����Ϸ����� ������ �ʰ�(����) �����ϴ� �ּҶ�� �� �� �֤���.
	m_Anim.push_back(sprite);
}

void Animation::AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame) //�ִϸ��̼� ������ ����?
{
	if (firstFrame > lastFrame)  //ù �������� ������ ������ ���� ������ ����!!
	{
		for (int i = firstFrame; i >= lastFrame; i--)  // ù �������� ������ ������ ���� ������ �ϳ��� ����
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png"); //auto Ű���带 ����ϸ� �ʱ갪�� ���Ŀ� ���� �����ϴ� �ν��Ͻ�(����)�� ������ '�ڵ�'���� �����ȴ�. 

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite); //�ڷ� �б�?
		}
	}
	else
	{
		for (int i = firstFrame; i <= lastFrame; i++) //ù �������� ������ ������ ���� ������ �ϳ��� �ø�
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png");//auto Ű���带 ����ϸ� �ʱ갪�� ���Ŀ� ���� �����ϴ� �ν��Ͻ�(����)�� ������ '�ڵ�'���� �����ȴ�. 

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);
		}
	}

}
void Animation::Init(float delay, bool play)
{
	m_Delay = delay;
	m_AutoPlay = play;
}

void Animation::Update(float deltatime, float time)
{
	m_FrameCount++;

	if (m_AutoPlay == true)
	{
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0;
		}
	}
	if (m_CurrentFrame > m_Anim.size() - 1)
	{
		m_CurrentFrame = 0;
	}

	m_Anim.at(m_CurrentFrame)->A = A;
	m_Anim.at(m_CurrentFrame)->R = R;
	m_Anim.at(m_CurrentFrame)->G = G;
	m_Anim.at(m_CurrentFrame)->B = B;
	m_Anim.at(m_CurrentFrame)->Update(deltatime, time);
}

void Animation::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);

		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);

	}


	m_Anim.at(m_CurrentFrame)->Render();
}