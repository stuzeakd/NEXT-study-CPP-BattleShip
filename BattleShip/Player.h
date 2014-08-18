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
	Point				Attack();
	void				Render();
	void				UpdateTileOnMyMap(Tile tile);
	void				UpdateTileOnEnemyMap(Tile tile);
	Point				MakeShipPos();
	virtual void		SetupShips() = 0;
	void				PrintShips();
	int					GetHP();
	Map					GetMap(){ return m_MyMap; }
	std::vector<Ship*>	GetShips(){ return m_MyShips; }
	std::string			GetPlayerName(){ return m_PlayerName; }
	void				SetMyTile(Tile& tile);
	void				SetEnemyTile(Tile& tile);
	void				SetPlayerName(std::string name){ m_PlayerName = name; }
	bool				IsValidAttackPos(Point pos);

	Map m_EnemyMap;
protected:
	void			UpdateTileOnMap(Tile& tile, Map& map);
	void			SetTile(Tile& tile, Map &map);
	void			InitShips();
	
	std::string		m_PlayerName;
	EPlayer::Type	m_PlayerType;
	Map				m_MyMap;
	Messages*		m_Msgs;
	std::vector<Ship*> m_MyShips;
	std::vector<Ship*> m_EnemyShips;
};

