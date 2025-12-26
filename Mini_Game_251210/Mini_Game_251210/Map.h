#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"
#include "PtrUtil.h"

class Map
{
public:
	Map(int size, const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& players);
	~Map();
	void Render();
	bool RenderPlayer(int x,int y);
	bool RenderMonster(int x,int y);
private:
	int size;
	vector <weak_ptr<Monster>> monster;
	weak_ptr<Player> player;
};

