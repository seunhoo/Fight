#pragma once
#define GT App::GetInst()->Time
#define DT App::GetInst()->DeltaTime
class App : public Singleton<App>
{
public:

	int m_Width;
	int m_Height;
	bool m_WindowMode;
	HWND m_Hwnd;

public:

	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

	float Time, DeltaTime;



	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	HWND GetHwnd() { return m_Hwnd; }

	bool _CreateWindow();
	bool _CreatRenderer();
};

