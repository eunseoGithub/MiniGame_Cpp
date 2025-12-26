#pragma once
#include "Monster.h"
#include "Player.h"
#include "Global.h"
#include "PtrUtil.h"

class HudSystem
{
public:
	HudSystem(const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& players);
	void UIPrint();

private:
	vector <weak_ptr<Monster>> monster;
	weak_ptr<Player> player;
};

