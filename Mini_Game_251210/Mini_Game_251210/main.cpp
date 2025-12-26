#include "Global.h"
#include "GameManager.h"


shared_ptr<GameManager> GameManager::Instance = nullptr;

int main()
{
	shared_ptr<int> i = make_shared<int>(1);
	weak_ptr<int> k = i;

	GameManager::Initialize();

	if (auto gameManager = GameManager::GetInstance().lock())
	{
		while (1)
		{
			gameManager->Input();
			gameManager->Update();
			if (gameManager->CheckWin())
				break;
			if (gameManager->CheckLose())
				break;
			gameManager->Render();
		}
		gameManager->DeleteMember();
	}
	return 0;
}