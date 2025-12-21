#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"

class CombatSystem
{
public:
	CombatSystem(const vector<Monster*>& monster, Player* const player);
	 
	void MonsterAttackPlayer();
	void PlayerAttackMonster();
private:
	vector <Monster*> monster;
	Player* player;
	AttackRange gAttackRange;
};

