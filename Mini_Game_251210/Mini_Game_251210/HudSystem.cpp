#include "HudSystem.h"

HudSystem::HudSystem(const vector<shared_ptr<Monster>>& monsters, const shared_ptr<Player>& players)
{
	monster.reserve(monster.size());
	for (const auto& m : monsters)
	{
		monster.push_back(m);
	}
	this->player = players;
}

void HudSystem::UIPrint()
{
	auto wPlayer = LockOrNull(player);
	if (wPlayer == nullptr)
		return;

	auto wMonster = LockAlive(monster);
	if (wMonster.empty())
		return;

	cout << "Player HP : " << wPlayer->GetHp() << endl;
	for (const auto& m : wMonster)
	{
		cout << "Monster : " << m->GetHp() << endl;
	}

}