#pragma once
#include "Point.h"
#include "common.h"

class Ship
{
public:
	Ship();
	~Ship();
	Ship(const Ship& src);


public:
	bool			SetPosition(const Point& head, const Point& tail);
	void			Set_ID(int id){ m_Id = id; }
	
	void			GiveDamage(){ if(m_Hp > 0) --m_Hp; }
	void			Destroy(){ m_Hp = 0; }

	EShip::Type&	GetType(){ return m_Type; }
	std::string&	GetName(){ return m_Name; }
	int&			GetHP(){ return m_Hp; }
	int&			GetID(){ return m_Id; }
	virtual int		GetLength() const = 0;
	Point&			GetHeadPos(){ return m_HeadPos; }
	Point&			GetTailPos(){ return m_TailPos; }
	Point*			GetPosition(){ return m_Position; }

	bool			IsValidPosition(const Point& head, const Point& tail);
	//bool IsFinishToAddPos();
	
protected:

	EShip::Type m_Type;
	std::string m_Name;
	int m_Hp;
	int m_Id;
	Point m_HeadPos;
	Point m_TailPos;
	Point* m_Position;
};

