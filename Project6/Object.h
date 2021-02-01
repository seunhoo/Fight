#pragma once
class Object
{
public:

	std::string m_Tag;

	Object();

	Matrix GetMatrix();
	
	Matrix m_wMat;
	RECT m_Collision;

	Object* m_Parent;

	Vec2 m_Size, m_Scale, m_Position;


	bool m_Visible, m_Destroy;

	int m_Layer, A, R, G, B;

	float m_Rotation;


public:

	virtual void Update(float deltatime, float time);
	virtual void Render();
	virtual void OnCollision(Object* obj, std::string tag);


public:


	void Translate(float x, float y);
	void Rotate(float r);
	void SetPosition(float x, float y);
	void SetParent(Object* parent);
	void SetScale(float x, float y);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	bool GetDestroy() { return m_Destroy; }

	
};

