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

	m_P1Data.ships = (m_P1Data.player)->GetShips();
	m_P2Data.ships = (m_P1Data.player)->GetShips();

	m_Attacker = &m_P1Data;
	m_Defender = &m_P2Data;
}
void GameManager::GameStart()
{
	Draw();
	while (!IsTimeToQuit())
	{
		Point pos = (m_Attacker->player)->Attack();
		Tile m_TmpTile = HitCheck(pos);
		//printf("%d, (%d %d)", m_TmpTile.GetTileState(), m_TmpTile.GetX(), m_TmpTile.GetY());
		Update(m_TmpTile);
		//getchar();
		Draw();
		SwapAttDef();
	}
	//Tile& m_TmpTile = HitCheck(pos);
	//Update();
	//Draw();
	//
	
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

		if (targetShip->GetHP() > 0) targetTile.SetTileState(ETile::HIT);// Ship state is damaged
		else if (targetShip->GetHP() == 0)
		{
			targetTile.SetTileState(ETile::DESTROY);		// Ship state is Destroyed
			targetTile.SetShipType(targetShip->GetType());	// Give Ship type.
		}
		else printf("unexpected err");
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
void GameManager::SwapAttDef()
{
	PlayerData* tmp;
	tmp = m_Attacker;
	m_Attacker = m_Defender;
	m_Defender = tmp;
}