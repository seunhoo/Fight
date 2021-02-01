#pragma once
class Animation : public Object
{
private:
	std::vector<Sprite*> m_Anim;

	float m_Delay;
	bool m_AutoPlay;
	float m_FrameCount;

public:
	float m_CurrentFrame;

	int A, R, G, B;

public:

	Animation();

	void SetFrame(float frame) { m_CurrentFrame = frame; }
	void AddFrame(std::wstring fileName);
	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame);

	void Init(float delay, bool play);
	void Update(float deltatime, float time);
	void Render();
};

