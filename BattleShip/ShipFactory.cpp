#include "stdafx.h"
#include "ShipFactory.h"

ShipFactory* ShipFactory::m_Instance = nullptr;

ShipFactory& ShipFactory::Instance(){
	if (m_Instance == nullptr){
		m_Instance = new ShipFactory();
	}
	return *m_Instance;
}

ShipFactory::ShipFactory()
{

}


ShipFactory::~ShipFactory()
{
}

Ship* ShipFactory::GenerateShip(EShip::Type shipType, int id)
{
	Ship* pShip = NULL;
	switch (shipType)
	{
	case EShip::AIRCRAFT:
		pShip = new Aircraft();
		break;
	case EShip::BATTLESHIP:
		pShip = new Battleship();
		break;
	case EShip::CRUISER:
		pShip = new Cruiser();
		break;
	case EShip::DESTROYER:
		pShip = new Destroyer();
		break;
	default:
		break;
	}

	pShip->Set_ID(id);
	return pShip;
}