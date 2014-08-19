#include "stdafx.h"
#include "Ship.h"
#include "common.h"


Ship::Ship()
{
}
Ship::~Ship()
{

}
//void Ship::init(EShip::Type type){
//	m_Type = type;
//	m_Hp = (int)m_Type;
//	m_Position = new Point[m_Hp];
//	m_Name = shipName[m_Hp];
//}
/*
 *	Try to set the head and tail of ship. if that Points are incorrect, do nothing and return false.
 *
 */
bool Ship::SetPosition(const Point& head, const Point& tail)
{
	if (IsValidPosition(head, tail))
	{
		m_HeadPos = head;
		m_TailPos = tail;
		return true;
	}
	else return false;
}
//bool Ship::IsFinishToAddPos(){
//	if (m_PositionIdx == m_Hp) return true;
//	else return false;
//}
/*
 *  Check the head and the tail with ship's length
 *
 */
bool Ship::IsValidPosition(const Point& head, const Point& tail)
{
	if (head.GetX() == tail.GetX()) //Horizontal
	{
		if (abs(head.GetY() - tail.GetY()) == GetLength() - 1) return true;
		else return false;
	}
	else							//Vertical
	{
		if (abs(head.GetX() - tail.GetX()) == GetLength() - 1) return true;
		else return false;
	}

	//bool isVertical = m_Position[0].GetX() == m_Position[1].GetX() ? true : false;
	//char min, max;
	//if (isVertical){
	//	min = m_Position[0].GetY();
	//	max = m_Position[0].GetY();
	//	for (int i = 1; i < m_Hp; i++){
	//		if (min > m_Position[i].GetY()) min = m_Position[i].GetY();
	//		if (max < m_Position[i].GetY()) max = m_Position[i].GetY();
	//		if (m_Position[i - 1].GetX() != m_Position[i].GetX()) return false;
	//	}
	//}
	//else{
	//	min = m_Position[0].GetX();
	//	max = m_Position[0].GetX();
	//	for (int i = 1; i < m_Hp; i++){
	//		if (min > m_Position[i].GetX()) min = m_Position[i].GetX();
	//		if (max < m_Position[i].GetX()) max = m_Position[i].GetX();
	//		if (m_Position[i - 1].GetY() != m_Position[i].GetY()) return false;
	//	}
	//}
	//if (max - min != m_Hp - 1) return false;
	//return true;
}
