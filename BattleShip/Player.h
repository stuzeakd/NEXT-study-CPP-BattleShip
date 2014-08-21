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

	virtual void		UpdateTileOnMyMap(const Tile& tile);
	virtual void		UpdateTileOnEnemyMap(const Tile& tile);
	virtual void		UpdateShipOnMyShips(const Ship& ship);
	virtual void		UpdateShipOnEnemyShips(const Ship& ship);

	int							GetHP() const;
	std::vector<Ship*>			GetShips() const{ return m_MyShips; }
	Map							GetMap() const{ return *m_MyMap; }
	std::string					GetPlayerName() const{ return m_PlayerName; }
	void						SetPlayerName(std::string name){ m_PlayerName = name; }
	void						SetShipOnMyMap(const Ship& ship);
	void						SetShipOnEnemyMap(const Ship& ship);
	
protected:
	void			SetShipOnMap(const Ship& ship, Map* map);

	bool			IsValidPosRange(const Point& pos) const;
	bool			IsValidAttackPos(const Point& pos) const;
	bool			IsValidShipPositionOnMap(const Point& head, const Point& tail) const;
	void			CreateShips();
	
	std::string		m_PlayerName;
	EPlayer::Type	m_PlayerType;
	Messages*		m_Msgs;
	Map*			m_MyMap;
	Map*			m_EnemyMap;
	std::vector<Ship*> m_MyShips;
	std::vector<Ship*> m_EnemyShips;
};

