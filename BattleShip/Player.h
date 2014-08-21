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
	//I'm hungry.
	Player();
	Player(EPlayer::Type type);
	~Player();

public:
	void				Init();
	virtual void		SetupShips() = 0;
	virtual Point		Attack() = 0;
	virtual Point		MakeShipPos() = 0;
	virtual void		Render() = 0;

	virtual void		UpdateTileOnMyMap(Tile& tile);
	virtual void		UpdateTileOnEnemyMap(Tile& tile);
	virtual void		UpdateShipOnMyShips(Ship& ship);
	virtual void		UpdateShipOnEnemyShips(Ship& ship);

	int					GetHP();
	std::vector<Ship*>	GetShips(){ return m_MyShips; }
	Map					GetMap(){ return *m_MyMap; }
	std::string			GetPlayerName(){ return m_PlayerName; }
	void				SetPlayerName(std::string name){ m_PlayerName = name; }
	void				SetShipOnMyMap(Ship& ship);
	void				SetShipOnEnemyMap(Ship& ship);
	
protected:
	void			SetShipOnMap(Ship& ship, Map* map);
	bool			IsValidAttackPos(Point pos);
	bool			IsValidShipPositionOnMap(const Point& head, const Point& tail);
	void			CreateShips();
	
	std::string		m_PlayerName;
	EPlayer::Type	m_PlayerType;
	Messages*		m_Msgs;
	Map*			m_MyMap;
	Map*			m_EnemyMap;
	std::vector<Ship*> m_MyShips;
	std::vector<Ship*> m_EnemyShips;
};

