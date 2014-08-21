#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_Type = EShip::AIRCRAFT;
	m_Hp = GetLength();
//	m_Position = new Point[m_Hp];
	m_Name = "Aircraft";
}


Aircraft::~Aircraft()
{
//	delete m_Position;
}
