#pragma once
class Sprite : public Object
{
private:
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;

public:
	RECT m_Rect;


public:

	Sprite();

	bool Init(std::wstring fileName);

	static Sprite* Create(std::wstring fileName);

	void Render();
};

