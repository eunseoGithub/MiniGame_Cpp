#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& player)
{
	monster.reserve(monsters.size());
	for (const auto& m : monsters)
	{
		monster.push_back(m);
	}

	this->player = player;
}

void CollisionSystem::ResolvePosition()
{
	//플레이어와 몬스터가 같은 위치일 경우
	//모든 몬스터를 서로 겹치지 않는 랜덤 값으로 변경
	bool isSame = false;

	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr)
		return;

	vector<shared_ptr<Monster>> alive = LockAlive(monster);
	if (alive.empty())
		return;
	
	const int px = wPlayer->GetX();
	const int py = wPlayer->GetY();
	
	for (auto& m : alive)
	{
		if (m->GetX() == px && m->GetY() == py)
		{
			if(!m->GetDead())
				RandomFreePosition();
		}
	}

	for (int i = 0; i < alive.size() - 1; i++)
	{
		for (int j = i + 1; j < alive.size(); j++)
		{
			if (alive[i]->GetX() == alive[j]->GetX() && alive[i]->GetY() == alive[j]->GetY())
			{
				if (!alive[i]->GetDead() && !alive[j]->GetDead())
					RandomFreePosition();
			}
		}
	}
}

void CollisionSystem::RandomFreePosition() const
{
	//Queue로 randomShuffleing으로 수정 예정
	vector<pair<int, int>> pos;
	queue<pair<int, int>> randomPos;
	
	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr)
		return;

	vector<shared_ptr<Monster>> alive = LockAlive(monster);
	if (alive.empty())
		return;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			pos.push_back({ i,j });
		}
	}
	random_shuffle(pos.begin(), pos.end());
	for (int i = 0; i < pos.size(); i++)
	{
		randomPos.push(pos[i]);
	}
	for (int i = 0; i < alive.size(); i++)
	{
		if (wPlayer->GetX() != randomPos.front().first && wPlayer->GetY() != randomPos.front().second)
		{
			alive[i]->SetX(randomPos.front().first);
			alive[i]->SetY(randomPos.front().second);
		}
		randomPos.pop();
	}

}