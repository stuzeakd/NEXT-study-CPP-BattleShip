#include "stdafx.h"
#include "AI.h"


AI::AI()
{
	m_PlayerType = EPlayer::AI;
}


AI::~AI()
{
}

void AI::SetupShips()
{
	for (std::vector<Ship*>::iterator IterPos = m_MyShips.begin(); IterPos != m_MyShips.end(); ++IterPos){

	}
}
Point AI::Attack()
{
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, GetPlayerName()+ " " + "Attack!");
	Point pos = MakeShipPos();
	while (!IsValidAttackPos(pos))
	{
		pos = MakeShipPos();
	}
	return pos;
}
Point AI::MakeShipPos()
{
	srand(time(NULL));
	Point pos;
	pos.SetX(rand() % 8);
	pos.SetY(rand() % 8);
	return pos;
}