#include "stdafx.h"
#include "GameEngine.h"

GameEngine* GameEngine::m_Instance = nullptr;
GameEngine& GameEngine::Instance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new GameEngine();
	}
	return *m_Instance;
}
GameEngine::GameEngine()
{
	//m_State = EGameEngine::MAIN;
}
GameEngine::~GameEngine()
{
}
void GameEngine::PrintTest()
{
	printf("test\n");
}
void GameEngine::Run()
{
	EGameUIMain::Mode mode = EGameUIMain::VS_AI;
	while (mode != EGameUIMain::QUIT)
	{
		GameUIMain::Instance().PrintMain();
		mode = GameUIMain::Instance().SelectMode();
		switch (mode)
		{
		case EGameUIMain::VS_AI:
			GameManager::Instance().Run();
			break;
		case EGameUIMain::VS_HUMAN:
			break;
		case EGameUIMain::QUIT:
			break;
		default:
			break;
		}
		ConsoleControl::Instance().Clear();
	}
	GameUIMain::Instance().PrintBye();
}