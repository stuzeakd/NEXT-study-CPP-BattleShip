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
	srand(time(NULL));
	for (std::vector<Ship*>::iterator IterPos = m_Ships.begin(); IterPos != m_Ships.end(); ++IterPos){

	}

	char row, col;
	row = rand() % 8;
	col = rand() % 8;
}