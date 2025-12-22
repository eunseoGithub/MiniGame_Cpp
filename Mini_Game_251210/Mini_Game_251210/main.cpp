#include "Global.h"
#include "GameManager.h"


shared_ptr<GameManager> GameManager::Instance = nullptr;

int main()
{

	GameManager::Initialize();
	if (auto gameManager = GameManager::GetInstance().lock())
	{
		while (1)
		{
			gameManager->Input();
			gameManager->Update();

			if (GameManager::GetInstance()->CheckWin())
				break;
			if (GameManager::GetInstance()->CheckLose())
				break;
			GameManager::GetInstance()->Render();
		}
		GameManager::GetInstance()->DeleteMember();
	}
	return 0;
}