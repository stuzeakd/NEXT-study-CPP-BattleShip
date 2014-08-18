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
	void Set_ID(int id){ m_Id = id; }
	void GiveDamage(){ if(m_Hp > 0) --m_Hp; }

	std::string	GetName(){ return m_Name; }
	int			GetHP(){ return m_Hp;}
	virtual int GetLength(){ return 0; }
	EShip::Type GetType(){ return m_Type; }
	Point*		GetM_Position();

	bool IsFinishToAddPos();
	
	//for check
	void PrintPos();

protected:
	bool IsValidM_Position();

	EShip::Type m_Type;
	std::string m_Name;
	int m_Hp;
	int m_Id;
	Point* m_Position;
	int m_PositionIdx;

};

