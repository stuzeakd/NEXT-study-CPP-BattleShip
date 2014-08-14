#include "stdafx.h"
#include "Cruiser.h"


Cruiser::Cruiser()
{
	m_Type = EShip::CRUISER;
	m_Hp = 3;
	m_Position = new Point[m_Hp];
	m_Name = "Cruiser";
}                                        
                 
                                
Cruiser::~Cruiser()
{
}
