#pragma once
#define dt App::GetInst()->DeltaTime
typedef struct D3DXVECTOR2 Vec2;
typedef struct D3DXMATRIX Matrix;

template<class T>
inline void SafeDelete(T*& x);

#include<d3d9.h>
#include<d3dx9.h>
#include<string>
#include<list>
#include<map>
#include<vector>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#include"Singleton.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"Texture.h"
#include"ResourceMgr.h"
#include"SceneDirector.h"
#include"Sprite.h"
#include"App.h"
#include"Animation.h"
#include"Input.h"
#include"Renderer.h"
#include"HpMgr.h"


template<class T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = static_cast<T*>(0);
}
