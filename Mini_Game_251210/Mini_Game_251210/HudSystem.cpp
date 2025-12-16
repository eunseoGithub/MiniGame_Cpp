#include "HudSystem.h"

HudSystem::HudSystem(const vector<Monster*>& monster, Player* const player)
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