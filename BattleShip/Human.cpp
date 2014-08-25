#include "stdafx.h"
#include "Human.h"


Human::Human()
{
	srand(time(NULL));
	m_PlayerType = EPlayer::HUMAN;
}
Human::~Human()
{
}
void Human::Render()
{
	ConsoleControl::Instance().SetStdXY(0, 0);
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs);
	GameUIIngame::Instance().DrawMyShips(m_MyShips);
	GameUIIngame::Instance().DrawEnemyShips(m_EnemyShips);
	GameUIIngame::Instance().DrawMyMap(m_MyMap);
	GameUIIngame::Instance().DrawEnemyMap(m_EnemyMap);
}

//void Human::SetupShips()
//{
//	Point head;
//	Point tail;
//	bool IsValidShipPos = true;
//	bool IsValidMapPos = true;
////	for (std::vector<Ship*>::iterator ship = m_MyShips.begin(); ship != m_MyShips.end(); ++ship)
//	for (auto ship:m_MyShips)
//	{
//		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, ship->GetName() + "start"); //
//		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_HEAD_POS);
//		head = MakeShipPos();
//		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_TAIL_POS);
//		tail = MakeShipPos();
//		while (!(IsValidShipPos = ship->IsValidPosition(head, tail)) ||
//			!(IsValidMapPos = IsValidShipPositionOnMap(head,tail)))
//		{
//			if (!IsValidShipPos) GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_SETUP_SHIP_MAKING_FAIL);
//			if (!IsValidMapPos)	 GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_SETUP_SHIP_ON_MAP_FAIL);
//			GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_HEAD_POS);
//			head = MakeShipPos();
//			GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_TAIL_POS);
//			tail = MakeShipPos();
//		}
//		ship->SetPosition(head, tail);
//		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs ,ship->GetName() + "fin"); //
//		SetShipOnMyMap(*ship);
//		GameUIIngame::Instance().DrawMyMap(m_MyMap);
//	}
//}
Point Human::Attack()
{
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_ATTACK);
	Point pos = MakeShipPos();
	while (!IsValidAttackPos(pos))
	{
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_WRONG_ATTACK);
		GameUIIngame::Instance().DrawInput("Position : ");
		pos = MakeShipPos();
	}
	return pos;
}
Point Human::MakeShipPos()
{
	GameUIIngame::Instance().DrawInput("Position : ");
	std::string input;
	std::cin >> input;
	getchar();
	while (!Utility::Instance().IsValidRC(input)){
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_WRONG_INPUT);
		GameUIIngame::Instance().DrawInput("Position : ");
		std::cin >> input;
		getchar();
	}
	return Utility::Instance().StringToPoint(input);
}
//void Human::UpdateTileOnMyMap(Tile& tile)
//{
//	//char row = tile.GetX() + 'A';
//	//char col = tile.GetY() + '1';
//	//char strPointC[2];
//	//strPointC[0] = row;
//	//strPointC[1] = col;
//	//std::string strPoint = strPoint;
//
//	//GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, strPoint +" " + "Attacked");
//	//getchar();
//	m_MyMap.SetTile(tile);
//}
void Human::UpdateTileOnEnemyMap(Tile& tile)
{
	Player::UpdateTileOnEnemyMap(tile);
}
void Human::UpdateShipOnMyShips(Ship& ship)
{
	Player::UpdateShipOnMyShips(ship);
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, ship.GetName() + MSG_UPDATE_MY_SHIP_2);
}
void Human::UpdateShipOnEnemyShips(Ship& ship)
{
	Player::UpdateShipOnEnemyShips(ship);
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, ship.GetName() + MSG_UPDATE_ENEMY_SHIP_2);
}
void Human::SetupShips()
{
	UDLRRand UDLR;
	Point head;
	Point tail;
	bool IsValidShipPos = false;
	bool IsValidMapPos = false;
	//	for (std::vector<Ship*>::iterator ship = m_MyShips.begin(); ship != m_MyShips.end(); ++ship)
	for (auto ship : m_MyShips)
	{
		do
		{
			UDLR.Reset();
			head = MakeShipPosRand();
			while (!UDLR.IsEmpty())
			{
				switch (UDLR.GetRand())
				{
				case EUDLRRand::UP:
					tail.SetX(head.GetX());
					tail.SetY(head.GetY() + (ship->GetLength() - 1));
					break;
				case EUDLRRand::DOWN:
					tail.SetX(head.GetX());
					tail.SetY(head.GetY() - (ship->GetLength() - 1));
					break;
				case EUDLRRand::LEFT:
					tail.SetX(head.GetX() - (ship->GetLength() - 1));
					tail.SetY(head.GetY());
					break;
				case EUDLRRand::RIGHT:
					tail.SetX(head.GetX() + (ship->GetLength() - 1));
					tail.SetY(head.GetY());
					break;
				default:
					break;
				}
				if (IsValidMapPos = IsValidShipPositionOnMap(head, tail)) break;
			}
		} while (!IsValidMapPos);
		ship->SetPosition(head, tail);
		SetShipOnMyMap(*ship); //Danger. assign to const Ship&
		GameUIIngame::Instance().DrawMyMap(m_MyMap);
	}
}
Point Human::MakeShipPosRand()
{
	Point pos;
	pos.SetX(rand() % MAP_ROW);
	pos.SetY(rand() % MAP_COL);
	return pos;
}