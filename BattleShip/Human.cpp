#include "stdafx.h"
#include "Human.h"


Human::Human()
{
	m_PlayerType = EPlayer::HUMAN;
}
Human::~Human()
{
}
//void Human::PrintMyMap(){
//	m_MyMap.Draw();
//}
//void Human::PrintEnemyMap(){
//	m_EnemyMap.Draw();
//}

void Human::SetupShips()
{
	Point head;
	Point tail;
	bool IsValidShipPos = true;
	bool IsValidMapPos = true;
//	for (std::vector<Ship*>::iterator ship = m_MyShips.begin(); ship != m_MyShips.end(); ++ship)
	for (auto ship:m_MyShips)
	{
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, ship->GetName() + "start"); //
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_HEAD_POS);
		head = MakeShipPos();
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_TAIL_POS);
		tail = MakeShipPos();
		while (!(IsValidShipPos = ship->IsValidPosition(head, tail)) ||
			!(IsValidMapPos = IsValidShipPositionOnMap(head,tail)))
		{
			if (!IsValidShipPos) GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_SETUP_SHIP_MAKING_FAIL);
			if (!IsValidMapPos)	 GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_SETUP_SHIP_ON_MAP_FAIL);
			GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_HEAD_POS);
			head = MakeShipPos();
			GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, MSG_INPUT_TAIL_POS);
			tail = MakeShipPos();
		}
		ship->SetPosition(head, tail);
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs ,ship->GetName() + "fin"); //
		SetShipOnMyMap(*ship);
		GameUIIngame::Instance().DrawMyMap(m_MyMap);
	}
}
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