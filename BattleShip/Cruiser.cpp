#include "stdafx.h"
#include "Cruiser.h"


Cruiser::Cruiser()
{
	m_Type = EShip::CRUISER;
	m_Hp = GetLength();
	m_Name = "Cruiser";
}                                        
                 
                                
Cruiser::~Cruiser()
{
}
