#pragma once
enum class KeyState
{
	DOWN,
	PRESS,
	UP,
	NONE
};
#define INPUT Input::GetInst()
class Input : public Singleton<Input>
{
private:

	int m_CurrentState[256];
	int m_PrevState[256];
	bool m_bCurrentState;
	bool m_bPrevState;
	bool m_ButtonDown;
	Vec2 m_MousePosition;


public:


	Input();

	void Update();
	void ButtonDown(bool down);
	KeyState GetKey(int key);
	Vec2 GetMousePos() { return m_MousePosition; }
	bool GetButtonDown() { return m_ButtonDown; }
	
	void KeyBoardaUpate();
	void MouseUpdate();

};

