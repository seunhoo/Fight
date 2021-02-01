#pragma once
class Hp2 : public Object
{
private:
	Sprite* m_Hp2;

	Sprite* m_Bar;

public:

	Hp2();

	void Update(float deltatime, float time);
	void Render();

};

