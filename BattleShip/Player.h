#pragma once
#include "Ship.h"
#include "common.h"
#include "Map.h"
#include "ShipFactory.h"
#include "Messages.h"
#include "GameUIIngame.h"

class Player
{
public:
	Player();
	Player(EPlayer::Type type);
	~Player();

public:
	void				Init();
	virtual void		SetupShips() = 0;
	virtual Point		Attack() = 0;
	virtual Point		MakeShipPos() = 0;
	void				Render();

	virtual void		UpdateTileOnMyMap(Tile& tile);
	void				UpdateTileOnEnemyMap(Tile& tile);
	void				UpdataShipOnMyShips(Ship& ship);
	void				UpdataShipOnEnemyShips(Ship& ship);

	int					GetHP();
	std::vector<Ship*>	GetShips(){ return m_MyShips; }
	Map					GetMap(){ return m_MyMap; }
	std::string			GetPlayerName(){ return m_PlayerName; }
	void				SetPlayerName(std::string name){ m_PlayerName = name; }
	void				SetShipOnMyMap(Ship& ship);
	//void				SetTile(Tile& tile, Map &map);
	//void				SetMyTile(Tile& tile);
	//void				SetEnemyTile(Tile& tile);

//	void				PrintShips();
	
protected:
	bool			IsValidAttackPos(Point pos);
	bool			IsValidShipPositionOnMap(const Point& head, const Point& tail);
	void			CreateShips();
	
	std::string		m_PlayerName;
	EPlayer::Type	m_PlayerType;
	Messages*		m_Msgs;
	Map				m_MyMap;
	Map				m_EnemyMap;
	std::vector<Ship*> m_MyShips;
	std::vector<Ship*> m_EnemyShips;
};

