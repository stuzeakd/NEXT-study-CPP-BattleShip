#pragma once
class Player
{
public:
	Player();
	~Player();

public :
	void playerInit();
	void stateUpdate();
	void hpUpdate();

private :
	
	Map myMap;
	Map oppMap;
	int hp;

};

