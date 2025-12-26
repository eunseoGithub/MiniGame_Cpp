#include "Map.h"

Map::Map(int size, const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& players)
{
	this->size = size;
	monster.reserve(monsters.size());
	for (const auto& m : monsters)
	{
		monster.push_back(m);
	}
	this->player = players;
}

Map::~Map()
{
	
}

bool Map::RenderPlayer(int x, int y)
{
	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr || wPlayer->GetDead())
		return false;

	if (wPlayer->GetX() == y && wPlayer->GetY() == x)
	{
		return true;
	}
	return false;
}

bool Map::RenderMonster(int y, int x)
{
	auto wMonster = LockAlive(monster);
	
	for (auto& m : wMonster)
	{
		if (m->GetX() == x && m->GetY() == y)
		{
			return m->GetDead() == false;
		}
	}

	return false;
}

void Map::Render()
{
	for (int i = 0; i < size; i++)//y
	{
		for (int j = 0; j < size; j++)//x
		{
			if (RenderPlayer(i, j))
			{
				cout << "P ";
			}
			else if (RenderMonster(i, j))
			{
				cout << "M ";
			}
			// 몬스터와 캐릭터가 동일한 위치일때 예외처리
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
}