#include "stdafx.h"
#include "Destroyer.h"


Destroyer::Destroyer()
{
	m_Type = EShip::DESTROYER;
	m_Hp = GetLength();
	m_Position = new Point[m_Hp];
	m_Name = "Destroyer";
}


Destroyer::~Destroyer()
{
}
