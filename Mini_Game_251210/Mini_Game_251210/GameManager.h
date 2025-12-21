#pragma once
#include "windows.h"
#include "Global.h"
#include "Map.h"
#include "Monster.h"
#include "Player.h"
#include "HudSystem.h"
#include "CombatSystem.h"
#include "CollisionSystem.h"

class GameManager
{
private:
	static GameManager* Instance;
	
	//shared_ptr<Map> map;
	//vector<shared_ptr<Monster>> monster;
	//shared_ptr<Player> player;

	//shared_ptr<HudSystem> hudSystem;
	//shared_ptr<CombatSystem> combatSystem;
	//shared_ptr<CollisionSystem> collisionSystem;

	Map* map;
	vector<Monster*> monster;
	Player* player;

	HudSystem* hudSystem;
	CombatSystem* combatSystem;
	CollisionSystem* collisionSystem;

	char currentCommand;
	AttackRange gAttackRange;
	
public:
	static void Initialize();
	static GameManager* GetInstance() { return Instance; }
	
	void Input();
	void Update();
	void Render();
	void DeleteMember();
	bool CheckWin();
	bool CheckLose();
};

