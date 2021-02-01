#pragma once
class User
{
public:
	TCHAR m_Name[16];
	int m_Score;
};
class RankMgr : public Singleton<RankMgr>
{

public:

	std::list<User*>m_Users;

	struct stLISTsort
	{
		bool operator()(const User* pUser1, const User* pUser2)
			const
		{
			if (pUser1->m_Score > pUser2->m_Score)
				return TRUE;

			return FALSE;
		}
	};

	int m_Score;


	void AddScore(int score) { m_Score += score; }
	void AddUser(User* user) { m_Users.push_back(user); }
	void SortUser() { m_Users.sort(stLISTsort()); }
	void ResetScore() { m_Score = 0; }
	int GetScore() { return m_Score; }
	void MinusScore(int minus) { m_Score -= minus; }
};

