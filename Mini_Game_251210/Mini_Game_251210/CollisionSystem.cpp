#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(const vector<Monster*>& monster, Player* const player)
{
	this->monster = monster;
	this->player = player;
}

void CollisionSystem::ResolvePosition()
{
	//플레이어와 몬스터가 같은 위치일 경우
	//모든 몬스터를 서로 겹치지 않는 랜덤 값으로 변경
	bool isSame = false;
	for (int i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetDead())
			continue;
		if (monster[i]->GetX() == player->GetX())
		{
			if (monster[i]->GetY() == player->GetY())
				isSame = true;
		}
	}
	//몬스터끼리 겹치는 경우에도 겹치는 몬스터들의 위치를 랜덤 값으로 이동
	for (int i = 0; i < monster.size() - 1; i++)
	{
		if (monster[i]->GetDead() || monster[i + 1]->GetDead())
			continue;
		if (monster[i]->GetX() == monster[i + 1]->GetX())
		{
			if (monster[i]->GetY() == monster[i + 1]->GetY())
			{
				isSame = true;
			}
		}
	}
	if (isSame)
	{
		RandomFreePosition();
	}

}

void CollisionSystem::RandomFreePosition() const
{
	//Queue로 randomShuffleing으로 수정 예정
	vector<pair<int, int>> usedPositions;
	usedPositions.push_back({ player->GetX(),player->GetY() });
	for (auto* m : monster)
	{
		int newX, newY;

		while (1)
		{
			int rx = rand() % 20;
			int ry = rand() % 20;

			bool overlapped = false;
			for (auto& pos : usedPositions)
			{
				if (pos.first == rx && pos.second == ry)
				{
					overlapped = true;
					break;
				}
			}
			if (!overlapped)
			{
				newX = rx;
				newY = ry;
				break;
			}

		}
		m->SetX(newX);
		m->SetY(newY);

		usedPositions.push_back({ newX,newY });
	}
}