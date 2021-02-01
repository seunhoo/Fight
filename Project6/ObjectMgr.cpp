#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "ObjectMgr.h"


void ObjectMgr::Release()
{
	for (auto& iter : m_Objects)
	{
		SafeDelete(iter);
	}
	m_Objects.clear();

}

void ObjectMgr::DeleteCheck()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Objects.erase(iter);
			SafeDelete(temp);
		}
		else
		{
			++iter;
		}
	}


}

void ObjectMgr::Update(float deltatime, float time)
{
	DeleteCheck();


	for (auto& iter : m_Objects)
	{
		(iter)->Update(deltatime, time);
	}

}



void ObjectMgr::CollideCheck(Object* obj, std::string tag)
{
	for (auto& iter : m_Objects)
	{
		if ((iter)->m_Tag == tag)
		{


			RECT rect;
			if (IntersectRect(&rect, &obj->m_Collision, &(iter)->m_Collision))
			{
				(iter)->OnCollision(obj, obj->m_Tag);
				obj->OnCollision(iter, iter->m_Tag);
			}
		}
	}


}


void ObjectMgr::Render()
{
	m_Objects.sort(stLISTsort());

	for (const auto& iter : m_Objects)
	{
		(iter)->Render();
	}


}

void ObjectMgr::KeepObject(Object* obj, std::string tag)
{
	if (obj)
	{
		m_Objects.push_back(obj);
		obj->m_Tag = tag;
	}
}


void ObjectMgr::RemoveObject(Object* obj)
{
	if (obj)
	{
		obj->SetDestroy(true);
	}

}


