#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"

class Map
{
public:
	Map(int size, const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player);
	~Map();
	void Render();
	bool RenderPlayer(int x,int y);
	bool RenderMonster(int x,int y);
private:
	int size;
	vector <shared_ptr<Monster>> monster;
	shared_ptr<Player> player;
};

