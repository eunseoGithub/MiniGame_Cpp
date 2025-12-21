#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"

class CombatSystem
{
public:
	CombatSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player);
	 
	void MonsterAttackPlayer();
	void PlayerAttackMonster();
private:
	vector<shared_ptr<Monster>> monster;
	shared_ptr<Player> player;
	AttackRange gAttackRange;
};

