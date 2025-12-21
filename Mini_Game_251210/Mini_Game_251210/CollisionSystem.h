#pragma once
#include "Monster.h"
#include "Player.h"
#include<queue>
class CollisionSystem
{
public:
	CollisionSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player);
	void ResolvePosition();

private:
	void RandomFreePosition() const;

private:
	vector <shared_ptr<Monster>> monster;
	shared_ptr<Player> player;

};

