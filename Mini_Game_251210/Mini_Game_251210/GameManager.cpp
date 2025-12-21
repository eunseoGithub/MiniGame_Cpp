#include "GameManager.h"
 
void GameManager::Initialize()
{
	if (Instance == nullptr)
	{
		Instance = new GameManager();
	}
	Instance->monster.push_back(make_shared<Monster>(1,3));
	Instance->monster.push_back(make_shared<Monster>(4,5));
	Instance->player = make_shared<Player>(10,10);
	Instance->map = make_shared<Map>(20, Instance->monster, Instance->player);
	Instance->currentCommand = NULL;
	Instance->combatSystem = make_shared<CombatSystem>(Instance->monster, Instance->player);
	Instance->collisionSystem = make_shared<CollisionSystem>(Instance->monster, Instance->player);
	Instance->hudSystem = make_shared<HudSystem>(Instance->monster, Instance->player);
	srand(time(0));
}

void GameManager::Input()
{
	char command;
	bool endFlag = false;
	while (1)
	{
		cout << "커맨드를 입력해주세요.(이동 : WASD, 공격 : F) : ";
		cin >> command;
		if (command != 'W' && command != 'w' &&
			command != 'A' && command != 'a' &&
			command != 'S' && command != 's' &&
			command != 'D' && command != 'd' &&
			command != 'F' && command != 'f')
		{
			cout << " W, A, S, D, F 중에서 다시 입력해주세요!" << endl;
		}
		else
		{
			endFlag = true;
		}
		if (endFlag)
		{
			break;
		}
	}
	currentCommand = command;
}

void GameManager::Update()
{
	system("cls");
	
	player->BeginUpdate();
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i]->BeginUpdate();
	}

	player->Update(currentCommand);
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i]->Update();
	}

	collisionSystem->ResolvePosition();

	combatSystem->PlayerAttackMonster();
	combatSystem->MonsterAttackPlayer();
	
	player->EndUpdate();
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i]->EndUpdate();
	}
}

void GameManager::Render()
{
	hudSystem->UIPrint();
	map->Render();
}

void GameManager::DeleteMember()
{
	/*delete(player);
	for (int i = 0; i < monster.size(); i++)
	{
		delete(monster[i]);
	}
	delete(map);
	delete(combatSystem);
	delete(collisionSystem);
	delete(hudSystem);*/

};

bool GameManager::CheckWin()
{
	int check = 0;
	for (int i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetDead())
			check++;
	}
	if (monster.size() == check)
	{
		if (player->GetDead() == false)
		{
			cout << "플레이어가 게임에서 승리하였습니다!!" << endl;
			return true;
		}
	}
	return false;
}
bool GameManager::CheckLose()
{
	if (player->GetDead())
	{
		cout << "플레이어가 죽었습니다!!" << endl;
		return true;
	}
	else
		return false;
}