#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"

class Map
{
public:
	Map(int size, const vector<Monster*>& monster, Player* const player);
	~Map();
	void Render();
	bool RenderPlayer(int x,int y);
	bool RenderMonster(int x,int y);
private:
	int size;
	vector <Monster*> monster;
	Player* player;
};

