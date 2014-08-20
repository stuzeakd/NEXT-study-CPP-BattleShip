#include "stdafx.h"
#include "Battleship.h"


Battleship::Battleship()
{
	m_Type = EShip::BATTLESHIP;
	m_Hp = GetLength();
	m_Position = new Point[m_Hp];
	m_Name = "Battleship";
}

Battleship::~Battleship()
{
	delete m_Position;
}
