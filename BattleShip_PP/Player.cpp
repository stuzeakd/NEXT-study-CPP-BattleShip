#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	Player::playerInit();
}

Player::~Player()
{

}

void Player::playerInit(){
	myMap = Map();
	hpUpdate();
}

void Player::stateUpdate()
{
	hpUpdate();
	mapUpdate();
	shipUpdate();

}
void Player::hpUpdate()
{
	hp = myMap.getHP();
}