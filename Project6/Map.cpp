#include "stdafx.h"
#include "Map.h"
#include"SceneMain.h"
#include"Kyo.h"
#include"ScareCrow.h"
#include"Hp.h"
#include"Hp2.h"
#include"Kyo2.h"
Map::Map()
{

	
	HpMgr::GetInst()->ResetHp();

	ObjMgr->KeepObject(new SceneMain(), "Scene");
	//ObjMgr->KeepObject(new ScareCrow(), "ScareCrow");
	ObjMgr->KeepObject(new Kyo(), "Kyo");
	ObjMgr->KeepObject(new Kyo2(), "Kyo2");
	ObjMgr->KeepObject(new Hp(), "Hp");
	ObjMgr->KeepObject(new Hp2(), "Hp2");

}
