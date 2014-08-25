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

const ColorSet GameUIIngame::m_ColorMapAircraft = { RED, BLACK };
const ColorSet GameUIIngame::m_ColorMapAircraftDamaged = { DARKRED, BLACK };
const ColorSet GameUIIngame::m_ColorMapBattleship = { BLUE, BLACK };
const ColorSet GameUIIngame::m_ColorMapBattleshipDamaged = { DARKBLUE, BLACK };
const ColorSet GameUIIngame::m_ColorMapCruiser = { YELLOW, BLACK };
const ColorSet GameUIIngame::m_ColorMapCruiserDamaged = { DARKYELLOW, BLACK };
const ColorSet GameUIIngame::m_ColorMapDestroyer = { PURPLE, BLACK };
const ColorSet GameUIIngame::m_ColorMapDestroyerDamaged = { DARKPURPLE, BLACK };

const ColorSet GameUIIngame::m_ColorMapStateMiss = { GREY, DARKBLUE };
const ColorSet GameUIIngame::m_ColorMapStateDestroyed = { DARKGREY, BLACK };
const ColorSet GameUIIngame::m_ColorMapStateHit = { GREY, BLACK };
const ColorSet GameUIIngame::m_ColorMapStateNone = { DARKGREY, BLACK };

//const ColorSet GameUIIngame::m_ColorTileStateMiss = { WHITE, GREY };

const Point GameUIIngame::m_PosNewMessage = { POS_MSG_NEW_X, POS_MSG_NEW_Y };
const Point GameUIIngame::m_PosMyShips = { POS_MY_SHIPS_X, POS_MY_SHIPS_Y };
const Point GameUIIngame::m_PosMyMap = { POS_MY_MAP_X, POS_MY_MAP_Y };
const Point GameUIIngame::m_PosEnemyShips = { POS_ENEMY_SHIPS_X, POS_ENEMY_SHIPS_Y };
const Point GameUIIngame::m_PosEnemyMap = { POS_ENEMY_MAP_X, POS_ENEMY_MAP_Y };
const Point GameUIIngame::m_PosInput = { POS_INPUT_X, POS_INPUT_Y };
const Point GameUIIngame::m_PosPressEnter = { POS_PRESS_ENTER_X, POS_PRESS_ENTER_Y };

const ShipShape GameUIIngame::m_ShapeShipNone = { "¢·", "¢Ã", "¢¹" }; //¢·¢¸¢º  ¢¹ 
//const ShipShape GameUIIngame::m_ShapeShipAircraft = "¡á";
//const ShipShape GameUIIngame::m_ShapeShipBattleship = "¡á";
//const ShipShape GameUIIngame::m_ShapeShipCruiser = "¡á";
//const ShipShape GameUIIngame::m_ShapeShipDestroyer = "¡á";

const std::string GameUIIngame::m_ShapeMapNone = "¢Æ";
const std::string GameUIIngame::m_ShapeMapAircraft = "¡á";
const std::string GameUIIngame::m_ShapeMapBattleship = "¡á";
const std::string GameUIIngame::m_ShapeMapCruiser = "¡á";
const std::string GameUIIngame::m_ShapeMapDestroyer = "¡á";

const Frame GameUIIngame::m_FrameMain = { "¦®", "¦¯", "¦±", "¦°", "¦¬", "¦­" };
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
	//system("mode con:cols=100 lines=50");
	ConsoleControl::Instance().SetWindowSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	ConsoleControl::Instance().SetTitle(NAME_GAME_TITLE);

}
ColorSet GameUIIngame::GenerateColorShipStateGood(EShip::Type type)
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
ColorSet GameUIIngame::GenerateColorShipStateBad(EShip::Type type)
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
ColorSet GameUIIngame::GenerateColorMap(const Tile& tile)
{
	EShip::Type shipType = tile.GetShipType();
	ETile::State tileState = tile.GetTileState();

	if (tileState == ETile::DESTROY) return m_ColorMapStateDestroyed;
	switch (shipType)
	{
	case EShip::NONE:
		if (tileState == ETile::NONE) return m_ColorMapStateNone;
		else if (tileState == ETile::MISS) return m_ColorMapStateMiss;
	case EShip::AIRCRAFT:
		if (tileState == ETile::NONE) return m_ColorMapAircraft;
		else if (tileState == ETile::HIT) return m_ColorMapAircraftDamaged;
		break;
	case EShip::BATTLESHIP:
		if (tileState == ETile::NONE) return m_ColorMapBattleship;
		else if (tileState == ETile::HIT) return m_ColorMapBattleshipDamaged;
		break;
	case EShip::CRUISER:
		if (tileState == ETile::NONE) return m_ColorMapCruiser;
		else if (tileState == ETile::HIT) return m_ColorMapCruiserDamaged;
		break;
	case EShip::DESTROYER:
		if (tileState == ETile::NONE) return m_ColorMapDestroyer;
		else if (tileState == ETile::HIT) return m_ColorMapDestroyerDamaged;
		break;
	default:
		return m_ColorNormal;
		break;
	}
}
ColorSet GameUIIngame::GenerateColorMapBackground(const Tile& tile)
{
	return m_ColorMapStateNone;
}
ShipShape GameUIIngame::GenerateShapeShip(EShip::Type type)
{
	return m_ShapeShipNone;
	//switch (type)
	//{
	//case EShip::NONE:
	//	return m_ShapeShipNone;
	//	break;
	//case EShip::AIRCRAFT:
	//	return m_ShapeShipAircraft;
	//	break;
	//case EShip::BATTLESHIP:
	//	return m_ShapeShipBattleship;
	//	break;
	//case EShip::CRUISER:
	//	return m_ShapeShipCruiser;
	//	break;
	//case EShip::DESTROYER:
	//	return m_ShapeShipDestroyer;
	//	break;
	//default:
	//	break;
	//}
}
std::string GameUIIngame::GenerateShapeMap(const Tile& tile)
{
	switch (tile.GetShipType())
	{
	case EShip::NONE:
		return m_ShapeMapNone;
		break;
	case EShip::AIRCRAFT:
		return m_ShapeMapAircraft;
		break;
	case EShip::BATTLESHIP:
		return m_ShapeMapBattleship;
		break;
	case EShip::CRUISER:
		return m_ShapeMapCruiser;
		break;
	case EShip::DESTROYER:
		return m_ShapeMapDestroyer;
		break;
	default:
		break;
	}
}
std::string GameUIIngame::GenerateShapeMapBackground(const Tile& tile)
{
	return m_ShapeMapNone;
}
void GameUIIngame::DrawShip(Ship *ship)
{
	ShipShape shipShape = GenerateShapeShip(ship->GetType());
	int shipHP = ship->GetHP();
	int shipLength = ship->GetLength();
	ColorSet stateGood;
	ColorSet stateBad;
	if (ship->GetHP() != 0)
	{
		stateGood = GenerateColorShipStateGood(ship->GetType());
		stateBad = GenerateColorShipStateBad(ship->GetType());
	}
	else
	{
		stateBad = stateGood = m_ColorShipStateDestroyed;	
	}
	//Draw
	ConsoleControl::Instance().SetColor(stateGood);
	for (int i =0; i < ship->GetLength(); ++i)
	{
		if ( i == shipHP) ConsoleControl::Instance().SetColor(stateBad);
		if (i == 0){
			printf("%s", shipShape.head.c_str());
		}
		else if (i == shipLength - 1){
			printf("%s", shipShape.tail.c_str());
		}
		else
		{
			printf("%s", shipShape.body.c_str());
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
void GameUIIngame::DrawMap(Map* map, const Point& stdPos)
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

	pos = stdPos;
	pos.MoveX(2);
	pos.MoveY(1);
	DrawFrame(MAP_COL + 2, MAP_ROW + 2, pos, m_FrameMain);

	//map;
	pos = stdPos;
	pos.MoveX(4);
	pos.MoveY(2);
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			ConsoleControl::Instance().Gotoxy(pos.GetX() + j * 2, pos.GetY() + i);
			DrawTile(map->GetTile(i, j));
		}
	}
}
void GameUIIngame::DrawTile(const Tile& tile)
{
	//if (tile.GetShipType() == EShip::NONE)
	//{

	//}
	//else
	//{
	//	ConsoleControl::Instance().SetColor();
	//	printf("%s"GenerateMapShape());
	//}

	ConsoleControl::Instance().SetColor(GenerateColorMap(tile));
	printf("%s", GenerateShapeMap(tile).c_str());
	ConsoleControl::Instance().SetColor(m_ColorNormal);
}

void GameUIIngame::DrawMyMap(Map* map)
{
	DrawMap(map, m_PosMyMap);
}
void GameUIIngame::DrawEnemyMap(Map* map)
{
	DrawMap(map, m_PosEnemyMap);
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
void GameUIIngame::DrawGameEnd()
{

}
void GameUIIngame::DrawFrame(int width, int height, const Point& stdPos, const Frame& frame)
{
	Point pos;
	char c;
	//Top
	pos = stdPos;
	for (int x = 0; x < width; ++x)
	{
		if (x == 0)
		{
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.upLeft.c_str());
			pos.MoveY(height - 1);
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.downLeft.c_str());
			pos.MoveY(-(height - 1));
		}
		else if (x == width - 1)
		{
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.upRight.c_str());
			pos.MoveY(height - 1);
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.downRight.c_str());
			pos.MoveY(-(height - 1));
		}
		else{
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.horizontal.c_str());
			pos.MoveY(height - 1);
			ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.horizontal.c_str());
			pos.MoveY(-(height - 1));
		}
		pos.MoveX(2);
	}
	pos = stdPos;
	pos.MoveY(1);
	for (int y = 1; y < height - 1; ++y)
	{
		ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.vertical.c_str());
		pos.MoveX(2*(width - 1));
		ConsoleControl::Instance().Gotoxy(pos); printf("%s", frame.vertical.c_str());
		pos.MoveX(-2*((width - 1)));
		pos.MoveY(1);
	}
}
void GameUIIngame::ClearLineWith(Point& pos, std::string blank)
{

}
