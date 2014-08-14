#pragma once

class Ship
{
public:
	Ship();
	~Ship();

public :
	bool giveDamage();
	int	getHP();
	int getLength();
protected :
	int hp;
	int length;

};

