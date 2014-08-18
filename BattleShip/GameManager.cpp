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
}
void GameManager::Run()
{
	ConsoleControl::Instance().Clear();
	GameInit();
	GameStart();
}
void GameManager::GameInit()
{
	//m_P1Data.player = m_P1;
	//m_P2Data.player = m_P2;
	//m_P1Data.map = &m_P1Map;
	//m_P2Data.map = &m_P2Map;
	//m_P1Data.ships = &m_P1Ships;
	//m_P2Data.ships = &m_P2Ships;

	m_P1Data.player = new AI();
	m_P2Data.player = new Human();
	m_P1Data.player->SetPlayerName("AI1");
	GameUIIngame::Instance().DrawInput("Player Name : ");
	m_P2Data.player->SetPlayerName(Utility::Instance().GetInput());
	m_P1Data.map = (m_P1Data.player)->GetMap();
	m_P2Data.map = (m_P1Data.player)->GetMap();
	m_P1Data.ships = (m_P1Data.player)->GetShips();
	m_P2Data.ships = (m_P1Data.player)->GetShips();

	m_Attacker = &m_P1Data;
	m_Defender = &m_P2Data;
}
void GameManager::GameStart()
{
	//Map map;
	//std::vector<Ship*> m_Ships;
	//for (int id = 0; id < _countof(shipRule); id++){
	//	Ship *ship = ShipFactory::Instance()->GenerateShip(shipRule[id], id);
	//	ship->GiveDamage();
	//	ship->GiveDamage();
	//	m_Ships.push_back(ship);
	//}
	//GameUIIngame::Instance().DrawSystemMsgs("System1");
	//getchar();
	//GameUIIngame::Instance().DrawSystemMsgs("System2");
	//getchar();
	//GameUIIngame::Instance().DrawSystemMsgs("System3");
	//getchar();
	//GameUIIngame::Instance().DrawSystemMsgs("System4");
	//GameUIIngame::Instance().DrawSystemMsgs();
	//getchar();
	//GameUIIngame::Instance().DrawSystemMsgs("System5");
	//getchar();
	//GameUIIngame::Instance().DrawSystemMsgs("System6");
	//getchar();

	//GameUIIngame::Instance().DrawEnemyMap(map);

//	Update();
	Draw();
	while (!IsTimeToQuit())
	{
		Point pos = (m_P1Data.player)->Attack();
		Tile m_TmpTile = HitCheck(pos);
		//printf("%d, (%d %d)", m_TmpTile.GetTileState(), m_TmpTile.GetX(), m_TmpTile.GetY());
		Update(m_TmpTile);
		//getchar();
		Draw();
	}
	//Tile& m_TmpTile = HitCheck(pos);
	//Update();
	//Draw();
	//SwapAttDef();
	
	//while (!IsTimeToQuit())
	//{
	//	Point pos = (*m_Attacker).MakeShipPos();
	//	Tile& m_TmpTile = HitCheck(pos);
	//	Update();
	//	Draw();
	//	SwapAttDef();
	//}
}
void GameManager::Draw()
{
	m_P2Data.player->Render();
}
Tile GameManager::HitCheck(const Point& pos)
{
	Tile targetTile = (m_Defender->map).GetTile(pos);
	if (targetTile.GetShipType() != EShip::NONE)
	{
		Ship *targetShip = ( (m_Defender->ships).at(targetTile.GetShipID()) );
		targetShip->GiveDamage();

		if (targetShip->GetHP() > 0) targetTile.SetTileState(ETile::HIT);			// Ship state is damaged
		else if(targetShip->GetHP() == 0) targetTile.SetTileState(ETile::DESTROY);	// Ship state is Destroyed
		else printf("err");
	}
	else
	{
		targetTile.SetTileState(ETile::MISS);
	}
	return targetTile;
}
void GameManager::Update(Tile& tile)
{
	(m_Attacker->map).SetTile(tile);
	(m_Defender->map).SetTile(tile);
	(m_Defender->ships);
	(m_Defender->ships);
	(m_Attacker->player)->UpdateTileOnEnemyMap(tile);
	(m_Defender->player)->UpdateTileOnMyMap(tile);
}