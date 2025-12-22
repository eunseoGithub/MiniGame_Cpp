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
public:
	static void Initialize();
	static weak_ptr<GameManager> GetInstance() { return Instance; }
	
	void Input();
	void Update();
	void Render();
	void DeleteMember();
	bool CheckWin();
	bool CheckLose();

	~GameManager() = default;
private:
	GameManager() = default;
	
	
	GameManager(const GameManager&) = delete;//복사 금지
	GameManager& operator=(const GameManager&) = delete;//대입 금지

private:
	static shared_ptr<GameManager> Instance;

	shared_ptr<Map> map;
	vector<shared_ptr<Monster>> monster;
	shared_ptr<Player> player;

	shared_ptr<HudSystem> hudSystem;
	shared_ptr<CombatSystem> combatSystem;
	shared_ptr<CollisionSystem> collisionSystem;


	char currentCommand;
	AttackRange gAttackRange;
};

