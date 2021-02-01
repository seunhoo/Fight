#pragma once
class SceneMain : public Object
{
private:

	Animation* m_Sprite;




public:



	SceneMain();

	void Update(float deltatime, float time);
	void Render();

};

