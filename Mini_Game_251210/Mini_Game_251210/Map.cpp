#include "Map.h"

Map::Map(int size, const vector<Monster*>& monster, Player* const player)
{
	this->size = size;
	this->monster = monster;
	this->player = player;
}

Map::~Map()
{

}

bool Map::RenderPlayer(int x, int y)
{
	if (player->GetDead())
		return false;
	if (player->GetX() == y && player->GetY() == x)
	{
		return true;
	}
	return false;
}

bool Map::RenderMonster(int x, int y)
{
	for (int i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetX() == y && monster[i]->GetY() == x)
		{
			return monster[i]->GetDead() == false;
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