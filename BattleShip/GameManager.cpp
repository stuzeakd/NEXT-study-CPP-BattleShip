#include "stdafx.h"
#include "GameManager.h"

GameManager* GameManager::m_Instance = nullptr;
GameManager& GameManager::Instance(){
	if (m_Instance == nullptr){
		m_Instance = new GameManager();
	}
	return *m_Instance;
}
GameManager::GameManager()
{
}
GameManager::~GameManager()
{
	delete m_P1Data.player;
	delete m_P2Data.player;
}
void GameManager::Run()
{
	ConsoleControl::Instance().Clear();
	GameInit();
	GameStart();
}
void GameManager::GameInit()
{
	m_P1Data.player = new AI();
	m_P2Data.player = new Human();
	m_P1Data.player->SetPlayerName("AI1");
	GameUIIngame::Instance().DrawInput("Player Name : ");
	m_P2Data.player->SetPlayerName(Utility::Instance().GetInput());

	Draw();
	m_P1Data.player->SetupShips();
	m_P2Data.player->SetupShips();
	m_P1Data.map = (m_P1Data.player)->GetMap();
	m_P2Data.map = (m_P2Data.player)->GetMap();
	//GameUIIngame::Instance().DrawEnemyMap((m_P1Data.player)->GetMap());

	for (auto ship : m_P1Data.player->GetShips())
	{
		Ship *tmpShip = ShipFactory::Instance()->GenerateShip(ship->GetType(), ship->GetID());
		m_P1Data.ships.push_back(tmpShip);
	}
	for (auto ship : m_P2Data.player->GetShips())
	{
		Ship *tmpShip = ShipFactory::Instance()->GenerateShip(ship->GetType(), ship->GetID());
		m_P2Data.ships.push_back(tmpShip);
	}

	m_AttackerData = &m_P1Data;
	m_DefenderData = &m_P2Data;
}
void GameManager::GameStart()
{
	Draw();
	while (!IsTimeToQuit())
	{
		Point pos = (m_AttackerData->player)->Attack();
		//getchar();
		Tile m_TmpTile = HitCheck(pos);
		//printf("%d, (%d %d)", m_TmpTile.GetTileState(), m_TmpTile.GetX(), m_TmpTile.GetY());
		Update(m_TmpTile);
		Draw();
		SwapAttDef();
	}
}
void GameManager::Draw()
{
	ConsoleControl::Instance().Clear();
	m_P1Data.player->Render();
	m_P2Data.player->Render();
}
Tile GameManager::HitCheck(const Point& pos)
{
	Tile targetTile = (m_DefenderData->map).GetTile(pos);

	if (targetTile.GetShipType() != EShip::NONE)
	{
		Ship *targetShip = ( (m_DefenderData->ships).at(targetTile.GetShipID()) );
		targetShip->GiveDamage();

		if (targetShip->GetHP() > 0) targetTile.SetTileState(ETile::HIT);// Ship state is damaged
		else if (targetShip->GetHP() == 0)
		{
			targetTile.SetTileState(ETile::DESTROY);		// Ship state is Destroyed
			//resultTile.SetShipType(targetShip->GetType());	// Give Ship type.
			//resultTile.SetID(targetShip->GetID());
		}
		else printf("unexpected err");
	}
	else
	{
		targetTile.SetTileState(ETile::MISS);
	}
	return targetTile;
}
void GameManager::Update(Tile& resultTile)
{
	int targetShipID = resultTile.GetShipID();

	(m_AttackerData->map).UpdateTile(resultTile);
	(m_DefenderData->map).UpdateTile(resultTile);

	Tile capsuleTile;
	capsuleTile.SetPoint(resultTile);
	capsuleTile.SetTileState(resultTile.GetTileState());

	if (resultTile.GetShipType() != EShip::NONE)
	{
		Ship *targetShip = m_DefenderData->ships.at(targetShipID);
		if (targetShip->GetHP() == 0){
			(m_AttackerData->player)->UpdateShipOnEnemyShips(*targetShip);
			capsuleTile.SetID(targetShipID);
			capsuleTile.SetShipType(targetShip->GetType());
		}
		(m_DefenderData->player)->UpdateShipOnMyShips(*targetShip);
	}

	(m_AttackerData->player)->UpdateTileOnEnemyMap(capsuleTile);
	(m_DefenderData->player)->UpdateTileOnMyMap(capsuleTile);
}
void GameManager::SwapAttDef()
{
	PlayerData* tmp;
	tmp = m_AttackerData;
	m_AttackerData = m_DefenderData;
	m_DefenderData = tmp;
}