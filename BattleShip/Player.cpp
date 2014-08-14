#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	InitShip();
}

Player::~Player()
{
}
Player::Player(EPlayer::Type type){
}


void Player::InitShip(){
	for (int i = 0; i < _countof(shipRule); i++){
		m_Ships.push_back(ShipFactory::Instance() -> GenerateShip(shipRule[i]));
	}
}
Point Player::MakeShipPos(){
	std::string input;
	std::cin >> input;
	while (Utility::Instance()->IsValidRC(input)){
		std::cout << "pos error\n" ; //
		std::cin >> input; 
	}
	Point pos;
	pos.SetX(input.c_str()[0]);
	pos.SetY(input.c_str()[1]);
	if (pos.GetX() >= 'a' || pos.GetX() <= 'z') pos.SetX(pos.GetX() - ('a' - 'A'));
	return pos;
}
void Player::PrintShips(){
	for (std::vector<Ship*>::iterator IterPos = m_Ships.begin(); IterPos != m_Ships.end(); ++IterPos){
		(*IterPos)->PrintPos();
		std::cout << (*IterPos)->GetName() << "\n";
	}
}
int Player::GetHP(){
	int HP = 0;
	for (auto ship : m_Ships){
		HP += ship->GetHP();
	}
	return HP;
}