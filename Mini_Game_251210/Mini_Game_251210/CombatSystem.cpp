#include "CombatSystem.h"

CombatSystem::CombatSystem(const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& players)
{
	monster.reserve(monster.size());
	for (const auto& m : monsters)
	{
		monster.push_back(m);
	}
	this->player = players;
}

void CombatSystem::PlayerAttackMonster()
{
	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr || !wPlayer->GetAttack())
		return;
	
	auto wMonster = LockAlive(monster);
	if (wMonster.empty())
		return;
	
	int px = wPlayer->GetX();
	int py = wPlayer->GetY();
		
	for (const auto& m : wMonster)
	{
		int mx = m->GetX();
		int my = m->GetY();

		for (int i = 0; i < 8; i++)
		{
			int tx = px + gAttackRange.range[i][0];
			int ty = py + gAttackRange.range[i][1];

			if (mx == tx && my == ty)
			{
				m->Damage();
				break;
			}
		}
	}
}

void CombatSystem::MonsterAttackPlayer()
{
	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr || !wPlayer->GetAttack())
		return;
	auto wMonster = LockAlive(monster);
	if (wMonster.empty())
		return;
	int px = wPlayer->GetX();
	int py = wPlayer->GetY();
	wPlayer->Evade();
	for (const auto& m : wMonster)
	{
		if (!m->GetAttack())
			continue;

		int mx = m->GetX();
		int my = m->GetY();

		for (int i = 0; i < 8; i++)
		{
			int tx = mx + gAttackRange.range[i][0];
			int ty = my + gAttackRange.range[i][1];

			if (px == tx && py == ty)
			{
				if (!wPlayer->GetEvade())
					wPlayer->Damage();
				break;
			}
		}
	}
}