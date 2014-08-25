#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	Init();
	m_PlayerName = "";
}
Player::~Player()
{
	delete m_Msgs;
	delete m_MyMap;
	delete m_EnemyMap;
	for (std::vector<Ship*>::iterator iter = m_MyShips.begin(); iter != m_MyShips.end();)
	{
		delete *iter;
		iter = m_MyShips.erase(iter);
	}
	m_MyShips.clear();
	for (std::vector<Ship*>::iterator iter = m_EnemyShips.begin(); iter != m_EnemyShips.end();)
	{
		delete *iter;
		iter = m_EnemyShips.erase(iter);
	}
	m_EnemyShips.clear();
}
void Player::Init()
{
	CreateShips();
	m_Msgs = new Messages();
	m_MyMap = new Map();
	m_EnemyMap = new Map();
}
void Player::CreateShips()
{
	//##important! id is same with vector position.##
	for (int id = 0; id < _countof(shipRule); id++){
		m_MyShips.push_back(ShipFactory::Instance().GenerateShip(shipRule[id], id));
	}
	for (int id = 0; id < _countof(shipRule); id++){
		m_EnemyShips.push_back(ShipFactory::Instance().GenerateShip(shipRule[id], id));
	}
}
/*
 * Update Functions
 *
 */
void Player::UpdateTileOnMyMap(const Tile& tile)
{
	m_MyMap->UpdateTile(tile);
}
void Player::UpdateTileOnEnemyMap(const Tile& tile)
{
	m_EnemyMap->SetTile(tile);
}

void Player::UpdateShipOnMyShips(const Ship& ship)
{
	if (ship.GetHP() > 0) m_MyShips.at(ship.GetID())->GiveDamage();
	if (ship.GetHP() == 0){
		m_MyShips.at(ship.GetID())->Destroy();
		SetShipOnMyMap(ship);
	}
}
void Player::UpdateShipOnEnemyShips(const Ship& ship)
{
	m_EnemyShips.at(ship.GetID())->Destroy();
	SetShipOnEnemyMap(ship);
}
/*
 * Get Function
 *
 */
int Player::GetHP() const
{
	int HP = 0;
	for (auto ship : m_MyShips){
		HP += ship->GetHP();
	}
	return HP;
}

void Player::SetShipOnMap(const Ship& ship, Map* map)
{
	//NULL Pointer check
	if (map == nullptr) return;

	Point head = ship.GetHeadPos();
	Point tail = ship.GetTailPos();
	Tile tmpTile;
	if (ship.GetHP() == 0) tmpTile.SetTileState(ETile::DESTROY);
	else if (ship.GetHP() != ship.GetLength()) tmpTile.SetTileState(ETile::HIT);
	//defalut ETile::NONE;

	int dir;
	if (head.GetX() == -1 || tail.GetX() == -1) return;
	if (head.GetX() == tail.GetX())
	{
		if (head.GetY() < tail.GetY()) dir = 1;
		else dir = -1;
		tmpTile.SetX(head.GetX());
		for (int y = head.GetY(); y != tail.GetY() + dir; y += dir)
		{
			tmpTile.SetY(y);
			tmpTile.SetShipType(ship.GetType());
			tmpTile.SetID(ship.GetID());
			map->SetTile(tmpTile);
		}
	}
	else if (head.GetY() == tail.GetY())
	{
		if (head.GetX() < tail.GetX()) dir = 1;
		else dir = -1;
		tmpTile.SetY(head.GetY());
		for (int x = head.GetX(); x != tail.GetX() + dir; x += dir)
		{
			tmpTile.SetX(x);
			tmpTile.SetShipType(ship.GetType());
			tmpTile.SetID(ship.GetID());
			map->SetTile(tmpTile);
		}
	}
	else printf("unexpected err");
}
void Player::SetShipOnMyMap(const Ship& ship)
{
	SetShipOnMap(ship, m_MyMap);
}
void Player::SetShipOnEnemyMap(const Ship& ship) 
{
	SetShipOnMap(ship, m_EnemyMap);
}

/*
 * IsValid Functions 
 *
 */
bool Player::IsValidAttackPos(const Point& pos) const
{
	//Point range check.
	if (!IsValidPosRange(pos)) return false;

	if ( m_EnemyMap->GetTile(pos).GetTileState() == ETile::NONE ) return true;
	else return false;
}
bool Player::IsValidShipPositionOnMap(const Point& head, const Point& tail) const
{
	//Point range check.
	if (!IsValidPosRange(head)) return false;
	if (!IsValidPosRange(tail)) return false;

	for (auto ship : m_MyShips){
		const Point& shipHead = ship->GetHeadPos();
		const Point& shipTail = ship->GetTailPos();
		if ((shipHead.GetX() == -1) || (shipTail.GetX() == -1)) continue;
		if (!Utility::Instance().IsUncrossedLine(head, tail, shipHead, shipTail))
		{
			return false;
		}
	}
	return true;
}
//Point range check.
bool Player::IsValidPosRange(const Point& pos) const
{
	if ((0 <= pos.GetX() && pos.GetX() < MAP_ROW) &&
		(0 <= pos.GetY() && pos.GetY() < MAP_COL)) return true;
	else return false;
}