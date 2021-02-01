#pragma once
enum class Fast
{
	ONE,
	TWO,
	THREE,
	NONE
};
class SceneDirector : public Object, public Singleton<SceneDirector>
{
private:
	Object* m_CurrentScene;

public:



	Fast m_Fast;

	void Update(float deltatime, float time);
	void Render();
	void ChangeScene(Object* newScene);
};

