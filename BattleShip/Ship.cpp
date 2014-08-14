#include "stdafx.h"
#include "Ship.h"
#include "common.h"


Ship::Ship()
{
	m_PositionIdx = 0;
}
//Ship::Ship(EShip::Type type){
//	m_Hp = type;
//	init(type);
//	
//}

Ship::~Ship()
{

}
//void Ship::init(EShip::Type type){
//	m_Type = type;
//	m_Hp = (int)m_Type;
//	m_Position = new Point[m_Hp];
//	m_Name = shipName[m_Hp];
//}
void Ship::AddPosition(Point pos){
	if(m_PositionIdx < m_Hp){
		m_Position[m_PositionIdx++] = pos;
	}
	if (IsFinishToAddPos() && !IsValidM_Position()){
		std::cout << "wrong ship\n"; //
		m_PositionIdx = 0;
	}
	else{
		//
	}
}
bool Ship::IsFinishToAddPos(){
	if (m_PositionIdx == m_Hp) return true;
	else return false;
}
/*
	배가 일렬로 배치되었나 체크.
 */
bool Ship::IsValidM_Position(){
	
	bool isVertical = m_Position[0].GetX() == m_Position[1].GetX() ? true : false;
	char min, max;
	if (isVertical){
		min = m_Position[0].GetY();
		max = m_Position[0].GetY();
		for (int i = 1; i < m_Hp; i++){
			if (min > m_Position[i].GetY()) min = m_Position[i].GetY();
			if (max < m_Position[i].GetY()) max = m_Position[i].GetY();
			if (m_Position[i - 1].GetX() != m_Position[i].GetX()) return false;
		}
	}
	else{
		min = m_Position[0].GetX();
		max = m_Position[0].GetX();
		for (int i = 1; i < m_Hp; i++){
			if (min > m_Position[i].GetX()) min = m_Position[i].GetX();
			if (max < m_Position[i].GetX()) max = m_Position[i].GetX();
			if (m_Position[i - 1].GetY() != m_Position[i].GetY()) return false;
		}
	}
	if (max - min != m_Hp - 1) return false;
	return true;
}

Point* Ship::GetM_Position(){
	return m_Position;
}

void Ship::PrintPos(){
	for (int i = 0; i < m_Hp; i++){
		m_Position[i].Print();
		printf(" ");
	}
}
