#pragma once
#include "Map.h"
#include "Ship.h"
#include "ConsoleControl.h"

//color
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKMINT 3
#define DARKRED 4
#define DARKPURPLE 5
#define DARKYELLOW 6
#define GOLD 6
#define BRIGHTGREY 7
#define DARKGREY 8
#define BLUE 9
#define GREEN 10
#define MINT 11
#define RED 12
#define PURPLE 13
#define PINK 13
#define YELLOW 14
#define WHITE 15


#define POS_MSG_NEW_X 10
#define POS_MSG_NEW_Y 20
#define POS_MY_MAP_X 3
#define POS_MY_MAP_Y 3
#define POS_ENEMY_MAP_X 19
#define POS_ENEMY_MAP_Y 3

#define SYSTEM_MSG_MAX 5

class GameUIIngame
{
public:
	static GameUIIngame& Instance();
	~GameUIIngame();
private:
	GameUIIngame();
	static GameUIIngame* m_Instance;


public:
	void DrawMyMap(Map myMap);
	void DrawMyShips(std::vector<Ship*>& ships); 
	void DrawEnemyMap(Map enemyMap);
	void DrawEnemyShips(std::vector<Ship*> &ships);
	void DrawSystemMsgs();
	void DrawSystemMsg(const std::string &msg);

private:
	std::vector<std::string> m_Msgs;
	//static const ColorSet m_SystemMsg;
	//static const ColorSet m_SystemMsgs;

};

