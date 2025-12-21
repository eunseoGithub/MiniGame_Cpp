#pragma once
#include "Monster.h"
#include "Player.h"
#include<queue>
class CollisionSystem
{
public:
	CollisionSystem(const vector<Monster*>& monster, Player* const player);
	void ResolvePosition();

private:
	void RandomFreePosition() const;

private:
	vector <Monster*> monster;
	Player* player;

};

