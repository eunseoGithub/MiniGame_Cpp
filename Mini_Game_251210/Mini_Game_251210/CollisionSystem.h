#pragma once
#include "Monster.h"
#include "Player.h"
#include "PtrUtil.h"
#include<queue>
class CollisionSystem
{
public:
	CollisionSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player);
	void ResolvePosition();

private:
	void RandomFreePosition() const;
private:
	vector <weak_ptr<Monster>> monster;
	weak_ptr<Player> player;

};

