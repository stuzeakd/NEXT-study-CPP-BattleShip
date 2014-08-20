#include "stdafx.h"
#include "GameUIIngame.h"

const ColorSet GameUIIngame::m_ColorNormal = { WHITE, BLACK };
const ColorSet GameUIIngame::m_ColorSystemMsg = { GREEN, BLACK };
const ColorSet GameUIIngame::m_ColorSystemMsgs = { DARKGREEN, BLACK };
const ColorSet GameUIIngame::m_ColorShipAircraft = { RED, BLACK };
const ColorSet GameUIIngame::m_ColorShipAircraftDamaged = { DARKRED, BLACK };
const ColorSet GameUIIngame::m_ColorShipBattleship = { BLUE, BLACK };
const ColorSet GameUIIngame::m_ColorShipBattleshipDamaged = { DARKBLUE, BLACK };
const ColorSet GameUIIngame::m_ColorShipCruiser = { YELLOW, BLACK };
const ColorSet GameUIIngame::m_ColorShipCruiserDamaged = { DARKYELLOW, BLACK };
const ColorSet GameUIIngame::m_ColorShipDestroyer = { PURPLE, BLACK };
const ColorSet GameUIIngame::m_ColorShipDestroyerDamaged = { DARKPURPLE, BLACK };
const ColorSet GameUIIngame::m_ColorShipStateDamaged = { GREY, BLACK };
const ColorSet GameUIIngame::m_ColorShipStateDestroyed = { DARKGREY, BLACK };

const ColorSet GameUIIngame::m_ColorTileStateMiss = { WHITE, GREY };


const Point GameUIIngame::m_PosNewMessage = { POS_MSG_NEW_X, POS_MSG_NEW_Y };
const Point GameUIIngame::m_PosMyShips = { POS_MY_SHIPS_X, POS_MY_SHIPS_Y };
const Point GameUIIngame::m_PosMyMap = { POS_MY_MAP_X, POS_MY_MAP_Y };
const Point GameUIIngame::m_PosEnemyShips = { POS_ENEMY_SHIPS_X, POS_ENEMY_SHIPS_Y };
const Point GameUIIngame::m_PosEnemyMap = { POS_ENEMY_MAP_X, POS_ENEMY_MAP_Y };
const Point GameUIIngame::m_PosInput = { POS_INPUT_X, POS_INPUT_Y };
const Point GameUIIngame::m_PosPressEnter = { POS_PRESS_ENTER_X, POS_PRESS_ENTER_Y };

const Point GameUIIngame::m_PosNewMessageP2 = { POS_MSG_NEW_X, POS_MSG_NEW_Y + 30 };
const Point GameUIIngame::m_PosMyShipsP2 = { POS_MY_SHIPS_X, POS_MY_SHIPS_Y +30 };
const Point GameUIIngame::m_PosMyMapP2 = { POS_MY_MAP_X, POS_MY_MAP_Y +30 };
const Point GameUIIngame::m_PosEnemyShipsP2 = { POS_ENEMY_SHIPS_X, POS_ENEMY_SHIPS_Y +30 };
const Point GameUIIngame::m_PosEnemyMapP2 = { POS_ENEMY_MAP_X, POS_ENEMY_MAP_Y +30 };
const Point GameUIIngame::m_PosInputP2 = { POS_INPUT_X, POS_INPUT_Y +30 };
const Point GameUIIngame::m_PosPressEnterP2 = { POS_PRESS_ENTER_X, POS_PRESS_ENTER_Y +30 };

const std::string GameUIIngame::m_ShapeShipNone = " ";
const std::string GameUIIngame::m_ShapeShipAircraft = "A";
const std::string GameUIIngame::m_ShapeShipBattleship = "B";
const std::string GameUIIngame::m_ShapeShipCruiser = "C";
const std::string GameUIIngame::m_ShapeShipDestroyer = "D";

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
	Init();
}

GameUIIngame::~GameUIIngame()
{
}
void GameUIIngame::Init()
{
	system("mode con:cols=100 lines=50");
	ConsoleControl::Instance().SetWindowSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
}
ColorSet GameUIIngame::GenerateColorStateGood(EShip::Type type)
{
	switch (type)
	{
	case EShip::AIRCRAFT:
		return m_ColorShipAircraft;
		break;
	case EShip::BATTLESHIP:
		return m_ColorShipBattleship;
		break;
	case EShip::CRUISER:
		return m_ColorShipCruiser;
		break;
	case EShip::DESTROYER:
		return m_ColorShipDestroyer;
		break;
	default:
		return m_ColorNormal;
		break;
	}
}
ColorSet GameUIIngame::GenerateColorStateBad(EShip::Type type)
{
	switch (type)
	{
	case EShip::AIRCRAFT:
		return m_ColorShipAircraftDamaged;
		break;
	case EShip::BATTLESHIP:
		return m_ColorShipBattleshipDamaged;
		break;
	case EShip::CRUISER:
		return m_ColorShipCruiserDamaged;
		break;
	case EShip::DESTROYER:
		return m_ColorShipDestroyerDamaged;
		break;
	default:
		return m_ColorNormal;
		break;
	}
}
std::string GameUIIngame::GenerateShipShape(EShip::Type type)
{
	switch (type)
	{
	case EShip::NONE:
		return m_ShapeShipNone;
		break;
	case EShip::AIRCRAFT:
		return m_ShapeShipAircraft;
		break;
	case EShip::BATTLESHIP:
		return m_ShapeShipBattleship;
		break;
	case EShip::CRUISER:
		return m_ShapeShipCruiser;
		break;
	case EShip::DESTROYER:
		return m_ShapeShipDestroyer;
		break;
	default:
		break;
	}
}
void GameUIIngame::DrawShip(Ship *ship)
{
	std::string shipShape = GenerateShipShape(ship->GetType());
	int i;
	if (ship->GetHP() != 0)
	{
		ConsoleControl::Instance().SetColor(GenerateColorStateGood(ship->GetType()));
		for (i = 0; i < ship->GetHP(); ++i)
		{
			printf("%s", shipShape.c_str());
		}
		ConsoleControl::Instance().SetColor(GenerateColorStateBad(ship->GetType()));
		for (; i < ship->GetLength(); ++i)
		{
			printf("%s", shipShape.c_str());
		}
	}
	else
	{
		ConsoleControl::Instance().SetColor(m_ColorShipStateDestroyed);
		for (i = 0; i < ship->GetLength(); i++)
		{
			printf("%s", shipShape.c_str());
		}
	}
	ConsoleControl::Instance().SetColor(m_ColorNormal);
}
void GameUIIngame::DrawShips(std::vector<Ship*>& ships, Point pos)
{
	int addPosY = 0;
	for (auto ship : ships){
		ConsoleControl::Instance().SetColor(m_ColorNormal);
		ConsoleControl::Instance().Gotoxy(pos.GetX(), pos.GetY() + addPosY);
		printf("%s", ship->GetName().c_str()); ++addPosY;
		ConsoleControl::Instance().Gotoxy(pos.GetX(), pos.GetY() + addPosY);
		DrawShip(ship); addPosY += 2;
	}
}
void GameUIIngame::DrawMyShips(std::vector<Ship*>& ships)
{
	DrawShips(ships, m_PosMyShips);
}
void GameUIIngame::DrawEnemyShips(std::vector<Ship*>& ships)
{
	DrawShips(ships, m_PosEnemyShips);
}
void GameUIIngame::DrawMyShipsP2(std::vector<Ship*>& ships)
{
	DrawShips(ships, m_PosMyShipsP2);
}
void GameUIIngame::DrawEnemyShipsP2(std::vector<Ship*>& ships)
{
	DrawShips(ships, m_PosEnemyShipsP2);
}
void GameUIIngame::DrawMap(Map& map, const Point& stdPos)
{
	Point pos;
	char c;
	//col
	pos = stdPos; pos.MoveX(4);
	c = 1;
	for (int i = 0; i < MAP_COL; ++i)
	{
		ConsoleControl::Instance().Gotoxy(pos);
		printf("%d", c++);
		pos.MoveX(2);
	}
	//row
	pos = stdPos; pos.MoveY(2);
	c = 'a';
	for (int i = 0; i < MAP_ROW; ++i)
	{
		ConsoleControl::Instance().Gotoxy(pos);
		printf("%c", c++);
		pos.MoveY(1);
	}
	//map;
	pos = stdPos;
	pos.MoveX(4);
	pos.MoveY(2);
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			ConsoleControl::Instance().Gotoxy(pos.GetX() + j * 2, pos.GetY() + i);
			DrawTile(map.GetTile(i, j));
		}
	}
}
void GameUIIngame::DrawTile(Tile& tile)
{
	switch (tile.GetTileState())
	{
	case ETile::NONE:
		ConsoleControl::Instance().SetColor(GenerateColorStateGood(tile.GetShipType()));
		printf("%s", GenerateShipShape(tile.GetShipType()).c_str());
		ConsoleControl::Instance().SetColor(m_ColorNormal);
		printf("N");
		break;
	case ETile::HIT:
		ConsoleControl::Instance().SetColor(GenerateColorStateBad(tile.GetShipType()));
		printf("%s", GenerateShipShape(tile.GetShipType()).c_str());
		ConsoleControl::Instance().SetColor(m_ColorNormal);
		printf_s("H");
		break;
	case ETile::MISS:
		printf("%s", GenerateShipShape(tile.GetShipType()).c_str());
		ConsoleControl::Instance().SetColor(m_ColorTileStateMiss);
		printf_s("M");
		break; 
	case ETile::DESTROY:
		ConsoleControl::Instance().SetColor(m_ColorShipStateDestroyed);
		printf("%s", GenerateShipShape(tile.GetShipType()).c_str());
		ConsoleControl::Instance().SetColor(m_ColorNormal);
		printf_s("D");
		break;
	default:
		break;
	}
	ConsoleControl::Instance().SetColor(m_ColorNormal);
}

void GameUIIngame::DrawMyMap(Map& map)
{
	DrawMap(map, m_PosMyMap);
}
void GameUIIngame::DrawEnemyMap(Map& map)
{
	DrawMap(map, m_PosEnemyMap);
}
void GameUIIngame::DrawMyMapP2(Map& map)
{
	DrawMap(map, m_PosMyMapP2);
}
void GameUIIngame::DrawEnemyMapP2(Map& map)
{
	DrawMap(map, m_PosEnemyMapP2);
}
void GameUIIngame::DrawSystemMsgs(Messages *msgs)
{
	int yBottom = POS_MSG_NEW_Y;
	int count = 0;
	
	//New Message line
	if (msgs->GetMessageVector().size() == 0) return;
	std::vector<std::string>::reverse_iterator msg = (msgs->GetMessageVector()).rbegin();
	//if (msg == msgs.GetMessageVector().rend()) return;
	ConsoleControl::Instance().SetColor(m_ColorSystemMsg);
	ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, yBottom);
	printf(BLANK_TWENTY); printf(BLANK_TWENTY);
	ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, yBottom--);
	printf("%s", msg->c_str());
	++count;

	//Old Messages line
	ConsoleControl::Instance().SetColor(m_ColorSystemMsgs);
	for (++msg ; (msg != msgs->GetMessageVector().rend() && count < SYSTEM_MSG_MAX); ++msg, ++count)
	{
		ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, yBottom);
		printf(BLANK_TWENTY); printf(BLANK_TWENTY);
		ConsoleControl::Instance().Gotoxy(POS_MSG_NEW_X, yBottom--);
		printf("%s", msg->c_str());
	}
	ConsoleControl::Instance().SetColor(WHITE, BLACK);
}
void GameUIIngame::DrawSystemMsgs(Messages *msgs, std::string msg)
{
	msgs->SetNewMessage(msg);
	DrawSystemMsgs(msgs);
}
void GameUIIngame::DrawInput()
{
	ConsoleControl::Instance().Gotoxy(m_PosInput);
}
void GameUIIngame::DrawInput(std::string msg)
{
	ConsoleControl::Instance().Gotoxy(m_PosInput.GetX() - msg.size() , m_PosInput.GetY());
	printf("%s", msg.c_str());
	DrawInput();
}
void GameUIIngame::DrawPressEnter()
{
	ConsoleControl::Instance().Gotoxy(m_PosPressEnter);
	printf("<Press Enter>");
	getchar();
	ConsoleControl::Instance().Gotoxy(m_PosPressEnter);
	printf(BLANK_TWENTY);
}
void GameUIIngame::ClearLineWith(Point& pos, std::string blank)
{

}