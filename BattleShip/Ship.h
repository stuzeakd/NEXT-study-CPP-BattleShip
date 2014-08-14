#pragma once
#include "Point.h"
#include "common.h"

class Ship
{
public:
	Ship();
	~Ship();

public:
	void AddPosition(Point pos);
	bool IsFinishToAddPos();
	bool GiveDamage();
	std::string GetName(){ return m_Name; }
	int GetHP(){ return m_Hp; }
	Point* GetM_Position();
	
	//for check
	void PrintPos();

protected:
	bool IsValidM_Position();

	EShip::Type m_Type;
	std::string m_Name;
	int m_Hp;
	Point* m_Position;
	int m_PositionIdx;
};

