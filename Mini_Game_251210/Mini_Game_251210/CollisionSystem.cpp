#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player)
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
	vector<pair<int, int>> pos;
	queue<pair<int, int>> randomPos;
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
	for (int i = 0; i < monster.size(); i++)
	{
		if (player->GetX() != randomPos.front().first && player->GetY() != randomPos.front().second)
		{
			monster[i]->SetX(randomPos.front().first);
			monster[i]->SetY(randomPos.front().second);
		}
		randomPos.pop();
	}
	
}