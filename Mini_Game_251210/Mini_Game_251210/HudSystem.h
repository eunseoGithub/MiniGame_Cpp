#pragma once
#include "Monster.h"
#include "Player.h"
#include "Global.h"

class HudSystem
{
public:
	HudSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player);
	void UIPrint();

private:
	vector <shared_ptr<Monster>> monster;
	shared_ptr<Player> player;
};

