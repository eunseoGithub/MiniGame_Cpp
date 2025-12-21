#include "HudSystem.h"

HudSystem::HudSystem(const vector<shared_ptr<Monster>>& monster, const shared_ptr<Player>& player)
{
	this->monster = monster;
	this->player = player;
}
void HudSystem::UIPrint()
{
	cout << "Player HP : " << player->GetHp() << endl;
	for (int i = 0; i < monster.size(); i++)
	{
		cout << "Monster" << i + 1 << " : " << monster[i]->GetHp() << endl;
	}
}