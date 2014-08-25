#include "stdafx.h"
#include "AI.h"


AI::AI()
{
	srand(time(NULL));
	m_PlayerType = EPlayer::AI;
}


AI::~AI()
{
}
void AI::Render()
{
	ConsoleControl::Instance().SetStdXY(0, 30);
	GameUIIngame::Instance().DrawMyShips(m_MyShips);
	GameUIIngame::Instance().DrawEnemyShips(m_EnemyShips);
	GameUIIngame::Instance().DrawMyMap(m_MyMap);
	GameUIIngame::Instance().DrawEnemyMap(m_EnemyMap);
}
void AI::SetupShips()
{
	UDLRRand UDLR;
	Point head;
	Point tail;
	//bool IsValidShipPos = false;
	bool IsValidMapPos = false;
	for (auto ship : m_MyShips)
	{
		do
		{
			UDLR.Reset();
			head = MakeShipPos();
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
		SetShipOnMyMap(*ship);
	}
}
Point AI::Attack()
{
	Point pos = MakeShipPos();
	while (!IsValidAttackPos(pos))
	{
		pos = MakeShipPos();
	}
	return pos;
}
Point AI::MakeShipPos()
{
	Point pos;
	pos.SetX(rand() % MAP_ROW);
	pos.SetY(rand() % MAP_COL);
	return pos;
}