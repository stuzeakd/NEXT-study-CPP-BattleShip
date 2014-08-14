#include "stdafx.h"
#include "GameManager.h"

GameManager* GameManager::m_Instance = nullptr;
GameManager& GameManager::Instance(){
	if (m_Instance == nullptr){
		m_Instance = new GameManager();
	}
	return *m_Instance;
}
GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Run()
{
	ConsoleControl::Instance().Clear();
	//Gameinit();
	GameStart();

}
void GameManager::GameStart()
{
	GameUIIngame::Instance().DrawSystemMsg("SYSTEM1");
	GameUIIngame::Instance().DrawSystemMsgs();
	getchar();
	GameUIIngame::Instance().DrawSystemMsg("SYSTEM2");
	GameUIIngame::Instance().DrawSystemMsgs();
	getchar();
	GameUIIngame::Instance().DrawSystemMsg("SYSTEM3");
	GameUIIngame::Instance().DrawSystemMsgs();
	getchar();
	//Tile& m_TmpTile;
	//while (!IsTimeToQuit())
	//{
	//	AttDefSwap();
	//	Point pos = m_Attacker.Attack();
	//	m_TmpTile = HitCheck(pos);
	//	Update();
	//	Draw();
	//}
}
