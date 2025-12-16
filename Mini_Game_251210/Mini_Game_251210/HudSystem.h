#pragma once
#include "Monster.h"
#include "Player.h"
#include "Global.h"

class HudSystem
{
public:
	HudSystem(const vector<Monster*>& monster, Player* const player);
	void UIPrint();

private:
	vector <Monster*> monster;
	Player* player;
};

