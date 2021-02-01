#pragma once
class ScareCrow  :public Object
{
private:

	Sprite* m_ScareCrow;

public:

	float m_Returntime;


public:

	ScareCrow();



	void Update(float deltatime, float  time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

