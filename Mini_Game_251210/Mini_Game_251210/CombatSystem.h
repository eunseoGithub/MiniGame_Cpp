#pragma once
#include "Global.h"
#include "Player.h"
#include "Monster.h"
#include "PtrUtil.h"
class CombatSystem
{
public:
	CombatSystem(const vector<shared_ptr<Monster>>& monsters , const shared_ptr<Player>& players);
	 
	void MonsterAttackPlayer();
	void PlayerAttackMonster();
private:
	vector<weak_ptr<Monster>> monster;
	weak_ptr<Player> player;
	AttackRange gAttackRange;
};

