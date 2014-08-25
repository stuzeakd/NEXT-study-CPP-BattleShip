#pragma once
#include "Point.h"
#include "common.h"

class Ship
{
public:
	Ship();
	virtual ~Ship();
	Ship(const Ship& src);


public:
	void			GiveDamage(){ if(m_Hp > 0) --m_Hp; }
	void			Destroy(){ m_Hp = 0; }
	
	bool			SetPosition(const Point& head, const Point& tail);
	void			Set_ID(int id){ m_Id = id; }

	const EShip::Type&	GetType() const{ return m_Type; }
	const std::string&	GetName() const{ return m_Name; }
	int					GetHP() const{ return m_Hp; }
	int					GetID() const{ return m_Id; }
	const Point&		GetHeadPos() const { return m_HeadPos; }
	const Point& 		GetTailPos() const{ return m_TailPos; }
	virtual int			GetLength() const = 0;
//	Point*			GetPosition() const{ return m_Position; }

	bool			IsValidPosition(const Point& head, const Point& tail) const;
	//bool IsFinishToAddPos();
	
protected:

	EShip::Type m_Type;
	std::string m_Name;
	int m_Hp;
	int m_Id;
	Point m_HeadPos;
	Point m_TailPos;
//	Point* m_Position;
};

