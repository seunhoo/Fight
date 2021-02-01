#pragma once
class HpMgr : public Singleton<HpMgr>
{ 
private:


public:

	float m_PlayerOneHp;
	float m_PlayerTwoHp;


	float m_AtkCheckTime;

	bool m_OneAtkCheck;
	bool m_TwoAtkCheck;


	void Update(float deltatime, float time);
	void ResetHp();
	void MinusHp(float hp, bool player);
	void PlusHp(float hp, bool player);
	void DieHpBar(bool player);
	void AtkCheck(bool player);

	
};

