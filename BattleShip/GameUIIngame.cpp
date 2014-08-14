#include "stdafx.h"
#include "GameUIIngame.h"

//const ColorSet m_SystemMsg = { GREEN, BLACK };
//const ColorSet m_SystemMsgs = { DARKGREEN, BLACK };

GameUIIngame* GameUIIngame::m_Instance = nullptr;
GameUIIngame& GameUIIngame::Instance(){
	if (m_Instance == nullptr)
	{
		m_Instance = new GameUIIngame();
	}
	return *m_Instance;
}
GameUIIngame::GameUIIngame()
{
}

GameUIIngame::~GameUIIngame()
{
}
void GameUIIngame::DrawMyMap(Map myMap)
{

}
void GameUIIngame::DrawMyShips(std::vector<Ship*>& ships)
{

}
void GameUIIngame::DrawEnemyMap(Map enemyMap)
{

}
void GameUIIngame::DrawEnemyShips(std::vector<Ship*>& ships)
{

}
void GameUIIngame::DrawSystemMsgs()
{
//	ConsoleControl::Instance().Setcolor(m_SystemMsgs);
	ConsoleControl::Instance().Setcolor(DARKGREEN, BLACK);
	int yBottom = POS_MSG_NEW_Y;
	int i = 0;
	for (std::vector<std::string>::reverse_iterator msg = (m_Msgs.rbegin() + 1);  msg != m_Msgs.rend() ; ++msg)
	{
		ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, --yBottom);
		printf("%s", msg->c_str());
	}
	ConsoleControl::Instance().Setcolor(WHITE, BLACK);
}
void GameUIIngame::DrawSystemMsg(const std::string& msg)
{

	ConsoleControl::Instance().Setcolor(GREEN, BLACK);
	//	ConsoleControl::Instance().Setcolor(m_SystemMsg.m_FontColor, m_SystemMsg.m_BackColor);
	ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, POS_MSG_NEW_Y);
	printf("%s", msg.c_str());
	m_Msgs.push_back(msg);
	ConsoleControl::Instance().Setcolor(WHITE, BLACK);
}
