#pragma once
#include "Map.h"
#include "Ship.h"
#include "ConsoleControl.h"
#include "Messages.h"

#define BLANK_FIVE "     "
#define BLANK_TEN "          "
#define BLANK_TWENTY "                    "

#define WINDOW_SIZE_WIDTH 100
#define WINDOW_SIZE_HEIGHT 50

//#define POS_MSG_NEW_X 10
//#define POS_MSG_NEW_Y 22
//#define POS_MY_SHIPS_X 2
//#define POS_MY_SHIPS_Y 3
//#define POS_MY_MAP_X 14
//#define POS_MY_MAP_Y 3
//#define POS_ENEMY_SHIPS_X 70
//#define POS_ENEMY_SHIPS_Y 3
//#define POS_ENEMY_MAP_X 45
//#define POS_ENEMY_MAP_Y 3
//#define POS_INPUT_X 30
//#define POS_INPUT_Y 15
//#define POS_PRESS_ENTER_X 30
//#define POS_PRESS_ENTER_Y 24

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
#define POS_PRESS_ENTER_X 30
#define POS_PRESS_ENTER_Y 24

#define SYSTEM_MSG_MAX 5

#define MSG_SETUP_SHIP_MAKING_FAIL	"Incorrect Ship Setting"
#define MSG_SETUP_SHIP_ON_MAP_FAIL	"Incorrect. Ship Collision"
#define MSG_INPUT_HEAD_POS			"Input head Point"
#define MSG_INPUT_TAIL_POS			"Input tail Point"
#define MSG_ATTACK					"Attack!"
#define MSG_WRONG_ATTACK			"You already did."
#define MSG_WRONG_INPUT				"Wrong Input"
#define MSG_UPDATE_ENEMY_SHIP_1		"Enemy's "
#define MSG_UPDATE_ENEMY_SHIP_2		" has destroyed."
#define MSG_UPDATE_MY_SHIP_1		"Your "
#define MSG_UPDATE_MY_SHIP_2		" has damaged."

#define NAME_GAME_TITLE "Deok's BattleShip"

struct Frame
{
	std::string upLeft;
	std::string upRight;
	std::string downLeft;
	std::string downRight;
	std::string horizontal;
	std::string vertical;
};
struct ShipShape
{
	std::string head;
	std::string body;
	std::string tail;
};
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
	void DrawMyMap(Map* myMap);
	void DrawEnemyMap(Map* enemyMap);

	void DrawSystemMsgs(Messages* msgs);
	void DrawSystemMsgs(Messages* msgs, std::string msg);
	void DrawInput();
	void DrawInput(std::string msg);
	void DrawPressEnter();
	void DrawGameEnd();

	void ClearLineWith(Point& pos, std::string blank);

private:
	void Init();

	ColorSet GenerateColorShipStateGood(EShip::Type type);
	ColorSet GenerateColorShipStateBad(EShip::Type type);
	ColorSet GenerateColorMap(const Tile& tile);
	ColorSet GenerateColorMapBackground(const Tile& tile);
	ShipShape GenerateShapeShip(EShip::Type type);
	std::string GenerateShapeMap(const Tile& tile);
	std::string GenerateShapeMapBackground(const Tile& tile);

	void DrawFrame(int width, int height, const Point& pos, const Frame& frame);
	void DrawShip(Ship *ship);
	void DrawShips(std::vector<Ship*>& ships, Point pos); 
	void DrawMap(Map* map, const Point& stdPos);
	void DrawTile(const Tile& tile);

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

	static const ColorSet m_ColorMapAircraft;
	static const ColorSet m_ColorMapAircraftDamaged;
	static const ColorSet m_ColorMapBattleship;
	static const ColorSet m_ColorMapBattleshipDamaged;
	static const ColorSet m_ColorMapCruiser;
	static const ColorSet m_ColorMapCruiserDamaged;
	static const ColorSet m_ColorMapDestroyer;
	static const ColorSet m_ColorMapDestroyerDamaged;
	static const ColorSet m_ColorMapStateNone;
	static const ColorSet m_ColorMapStateMiss;
	static const ColorSet m_ColorMapStateHit;
	static const ColorSet m_ColorMapStateDestroyed;

	static const Point m_PosNewMessage;
	static const Point m_PosMyShips;
	static const Point m_PosMyMap;
	static const Point m_PosEnemyShips;
	static const Point m_PosEnemyMap;
	static const Point m_PosInput;
	static const Point m_PosPressEnter;

	//static const std::string m_MsgUpdateMyShip1;
	//static const std::string m_MsgUpdateMyShip2;
	//static const std::string m_MsgUpdateEnemyShip1;
	//static const std::string m_MsgUpdateEnemyShip2;

	static const ShipShape m_ShapeShipNone;
	//static const ShipShape m_ShapeShipAircraft;
	//static const ShipShape m_ShapeShipBattleship;
	//static const ShipShape m_ShapeShipCruiser;
	//static const ShipShape m_ShapeShipDestroyer;

	static const std::string m_ShapeMapNone;
	static const std::string m_ShapeMapAircraft;
	static const std::string m_ShapeMapBattleship;
	static const std::string m_ShapeMapCruiser;
	static const std::string m_ShapeMapDestroyer;

	static const Frame m_FrameMain;

};

