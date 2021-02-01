#pragma once
class Renderer : public Singleton<Renderer>
{
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT m_pFont;


public:

	bool Init(int width, int height, bool windowMode);
	void Release();

	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	LPD3DXSPRITE GetSprite() { return m_pSprite; }
	LPD3DXFONT GetPlayerFont() { return m_pFont; }


	void Begin();
	void End();

};

