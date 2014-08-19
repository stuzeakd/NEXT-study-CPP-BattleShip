#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_Type = EShip::AIRCRAFT;
	m_Hp = GetLength();
	m_Name = "Aircraft";
}


Aircraft::~Aircraft()
{
}
