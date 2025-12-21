#include "CombatSystem.h"

CombatSystem::CombatSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player)
{
	this->monster = monster;
	this->player = player;
}
void CombatSystem::PlayerAttackMonster()
{
	if (!player->GetAttack())
		return;
	int px = player->GetX();
	int py = player->GetY();
	for (const auto& m : monster)
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
	int px = player->GetX();
	int py = player->GetY();
	player->Evade();
	for (const auto& m : monster)
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
				if (!player->GetEvade())
					player->Damage();
				break;
			}
		}
	}
}