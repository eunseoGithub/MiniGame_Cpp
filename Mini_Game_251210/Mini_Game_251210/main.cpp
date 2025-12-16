#include "Global.h"
#include "GameManager.h"


GameManager* GameManager::Instance = nullptr;

int main()
{
	
	GameManager::Initialize();

	while (1)
	{
		GameManager::GetInstance()->Input();
		GameManager::GetInstance()->Update();
		if (GameManager::GetInstance()->CheckWin())
			break;
		if (GameManager::GetInstance()->CheckLose())
			break;
		GameManager::GetInstance()->Render();
	}
	GameManager::GetInstance()->DeleteMember();
	return 0;
}