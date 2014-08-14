#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{

}


Ship::~Ship()
{

}

bool Ship::giveDamage(){
	if (!hp){
		hp--;
		return true;
	}
	else return false;

}
int Ship::getHP(){
	return hp;
}
int Ship::getLength(){
	return length;
}