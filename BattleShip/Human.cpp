#include "stdafx.h"
#include "Human.h"


Human::Human()
{
	m_PlayerType = EPlayer::HUMAN;
}


Human::~Human()
{
}
void Human::PrintMyMap(){
	m_MyMap.Draw();
}
void Human::PrintEnemyMap(){
	m_EnemyMap.Draw();
}
void Human::SetupShips(){
	Point pos;
	for (std::vector<Ship*>::iterator IterPos = m_MyShips.begin(); IterPos != m_MyShips.end(); ++IterPos){
		std::cout << (*IterPos)->GetName();
		while (!((*IterPos)->IsFinishToAddPos())){
			pos = MakeShipPos();
			(*IterPos)->AddPosition(pos);
		}
		std::cout << (*IterPos)->GetName() << "fin\n"; //
	}
}