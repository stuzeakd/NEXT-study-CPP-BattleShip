#include "stdafx.h"
#include "GameUIMain.h"
const std::string GameUIMain::m_Cursor = "¢º";
GameUIMain* GameUIMain::m_Instance = nullptr;
GameUIMain& GameUIMain::Instance(){
	if (m_Instance == nullptr)
	{
		m_Instance = new GameUIMain();
	}
	return *m_Instance;
}

GameUIMain::GameUIMain()
{
}


GameUIMain::~GameUIMain()
{
}

void GameUIMain::PrintMain()
{
	ConsoleControl::Instance().Gotoxy(20, 10);
	printf("AI");
	ConsoleControl::Instance().Gotoxy(20, 12);
	printf("Human");
	ConsoleControl::Instance().Gotoxy(20, 14);
	printf("Quit");
}
EGameUIMain::Mode GameUIMain::SelectMode()
{
	return (EGameUIMain::Mode)ConsoleControl::Instance().CursorPosVerti(m_Cursor, Point(18, 10), 3, 2, 0);
}
void GameUIMain::PrintBye()
{
	ConsoleControl::Instance().Gotoxy(20, 20);
	printf("Bye");
}