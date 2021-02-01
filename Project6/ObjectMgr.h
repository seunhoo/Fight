#pragma once
#define ObjMgr ObjectMgr::GetInst()
class ObjectMgr : public Singleton<ObjectMgr>
{
public:

	std::list<Object*>m_Objects;


	struct stLISTsort
	{
		bool operator()(const Object* pObject1, const Object* pObject2)const
		{
			if (pObject1->m_Layer < pObject2->m_Layer)
				return TRUE;

			return FALSE;
		}
	};


	void Update(float deltatime, float time);
	void Render();
	void Release();
	void DeleteCheck();
	void CollideCheck(Object* obj, std::string tag);
	void KeepObject(Object* obj, std::string tag);
	void RemoveObject(Object* obj);

	

};

