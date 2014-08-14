#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_Type = EShip::AIRCRAFT;
	m_Hp = 5;
	m_Position = new Point[m_Hp];
	m_Name = "Aircraft";
}


Aircraft::~Aircraft()
{
}
