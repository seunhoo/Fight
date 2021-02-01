#pragma once
enum class State
{
	Punch,
	Kick,
	Jump,
	RightMove,
	LeftMove,
	NONE
};
enum class MoveState
{
	Right,
	Left,
	NONE
};
class Kyo : public Object
{
private:

	Animation* m_LStand;
	Animation* m_RStand;

	Animation* m_RPunch;
	Animation* m_LPunch;

	Animation* m_RKick;
	Animation* m_LKick;

	Animation* m_LJump;
	Animation* m_RJump;

	Animation* m_RMove;
	Animation* m_LMove;

	Animation* m_Player;

private:

	Sprite* m_Hpbar;
	Sprite* m_P;


public:

	bool m_Way;
	float m_ReturnTime;


public:


	Kyo();

	State m_State;
	MoveState m_MoveState;

	void Update(float deltatime, float time);
	
	void Attack();
	
	void Move();
	void Jump();
	


	void Render();
	void OnCollision(Object* obj, std::string tag);
};

