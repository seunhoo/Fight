#include"stdafx.h"
#include"SceneMain.h"
#include"Map.h"
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream ,"CONOUT$", "wt", stdout);
#endif // _DEBUG
	App::GetInst()->Init(1920, 1080, 1);
	SceneDirector::GetInst()->ChangeScene(new Map());
	App::GetInst()->Run();

	return 0;

}