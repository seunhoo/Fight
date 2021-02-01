#include "stdafx.h"
#include "Object.h"

Object::Object()
	:m_Position(0.f,0.f)
	,m_Scale(1.f,1.f)
	,m_Rotation(0)
	,m_Layer(0)
	,m_Parent(nullptr)
{
	D3DXMatrixIdentity(&m_wMat);
}

Matrix Object::GetMatrix()
{
	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, 0, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Update(float deltatime, float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* obj, std::string tag)
{
}

void Object::Translate(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::Rotate(float r)
{
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetParent(Object* parent)
{
	m_Parent = parent;
}

void Object::SetScale(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}
