#pragma once
#include "Map.h"
#include "Ship.h"
#include "ConsoleControl.h"
#include "Messages.h"

//color
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKMINT 3
#define DARKRED 4
#define DARKPURPLE 5
#define DARKYELLOW 6
#define GOLD 6
#define GREY 7
#define DARKGREY 8
#define BLUE 9
#define GREEN 10
#define MINT 11
#define RED 12
#define PURPLE 13
#define PINK 13
#define YELLOW 14
#define WHITE 15

#define BLANK_FIVE "     "
#define BLANK_TEN "          "
#define BLANK_TWENTY "                    "

#define WINDOW_SIZE_WIDTH 100
#define WINDOW_SIZE_HEIGHT 50

#define POS_MSG_NEW_X 10
#define POS_MSG_NEW_Y 22
#define POS_MY_SHIPS_X 2
#define POS_MY_SHIPS_Y 3
#define POS_MY_MAP_X 14
#define POS_MY_MAP_Y 3
#define POS_ENEMY_SHIPS_X 70
#define POS_ENEMY_SHIPS_Y 3
#define POS_ENEMY_MAP_X 45
#define POS_ENEMY_MAP_Y 3
#define POS_INPUT_X 30
#define POS_INPUT_Y 15

#define SYSTEM_MSG_MAX 5

#define MSG_SETUP_SHIP_MAKING_FAIL	"Incorrect Ship Setting"
#define MSG_SETUP_SHIP_ON_MAP_FAIL	"Incorrect. Ship Collision"
#define MSG_INPUT_HEAD_POS	"Input head Point"
#define MSG_INPUT_TAIL_POS	"Input tail Point"
#define MSG_ATTACK			"Attack!"
#define MSG_WRONG_ATTACK	"You already did."
#define MSG_WRONG_INPUT		"Wrong Input"
class GameUIIngame
{
public:
	static GameUIIngame& Instance();
	~GameUIIngame();
private:
	GameUIIngame();
	static GameUIIngame* m_Instance;

public:
	void DrawMyShips(std::vector<Ship*> &ships);
	void DrawEnemyShips(std::vector<Ship*> &ships);
	void DrawMyMap(Map& myMap);
	void DrawEnemyMap(Map& enemyMap);
	void DrawSystemMsgs(Messages* msgs);
	void DrawSystemMsgs(Messages* msgs, std::string msg);
	void DrawInput();
	void DrawInput(std::string msg);
private:
	void Init();
	ColorSet GenerateColorStateGood(EShip::Type type);
	ColorSet GenerateColorStateBad(EShip::Type type);
	std::string GenerateShipShape(EShip::Type type);
	void DrawShip(Ship *ship);
	void DrawShips(std::vector<Ship*>& ships, Point pos); 
	void DrawMap(Map& map, const Point& stdPos);
	void DrawTile(Tile& tile);

private:
	static const ColorSet m_ColorNormal;
	static const ColorSet m_ColorSystemMsg;
	static const ColorSet m_ColorSystemMsgs;
	static const ColorSet m_ColorShipAircraft;
	static const ColorSet m_ColorShipAircraftDamaged;
	static const ColorSet m_ColorShipBattleship;
	static const ColorSet m_ColorShipBattleshipDamaged;
	static const ColorSet m_ColorShipCruiser;
	static const ColorSet m_ColorShipCruiserDamaged;
	static const ColorSet m_ColorShipDestroyer;
	static const ColorSet m_ColorShipDestroyerDamaged;
	static const ColorSet m_ColorShipStateDamaged;
	static const ColorSet m_ColorShipStateDestroyed;

	static const ColorSet m_ColorTileStateMiss;

	static const Point m_PosNewMessage;
	static const Point m_PosMyShips;
	static const Point m_PosMyMap;
	static const Point m_PosEnemyShips;
	static const Point m_PosEnemyMap;
	static const Point m_PosInput;

	static const std::string m_ShapeShipNone;
	static const std::string m_ShapeShipAircraft;
	static const std::string m_ShapeShipBattleship;
	static const std::string m_ShapeShipCruiser;
	static const std::string m_ShapeShipDestroyer;

};

