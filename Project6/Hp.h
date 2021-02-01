#pragma once
class Hp : public Object
{
private:

	Sprite* m_Hp2;
	Sprite* m_Bar;


public:

	float yiro;


public:



	Hp();



	void Update(float deltatime, float time);
	void Render();
};

