#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	Init();
	m_PlayerName = "";
}
Player::~Player()
{
}
Player::Player(EPlayer::Type type){
}
void Player::Init()
{
	CreateShips();
	m_Msgs = new Messages();
}
void Player::CreateShips()
{
	//##id is same with vector position.##
	for (int id = 0; id < _countof(shipRule); id++){
		m_MyShips.push_back(ShipFactory::Instance() -> GenerateShip(shipRule[id], id));
	}
	for (int id = 0; id < _countof(shipRule); id++){
		m_EnemyShips.push_back(ShipFactory::Instance()->GenerateShip(shipRule[id], id));
	}
}
void Player::Render()
{
	ConsoleControl::Instance().Clear();
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs);
	GameUIIngame::Instance().DrawMyShips(m_MyShips);
	GameUIIngame::Instance().DrawEnemyShips(m_EnemyShips);
	GameUIIngame::Instance().DrawMyMap(m_MyMap);
	GameUIIngame::Instance().DrawEnemyMap(m_EnemyMap);
}

void Player::UpdateTileOnMyMap(Tile& tile)
{
	//if (tile.GetTileState == ETile::DESTROY)
	//{
	//	m_MyShips.at(tile.GetShipID())
	//}
	m_MyMap.SetTile(tile);
}
void Player::UpdateTileOnEnemyMap(Tile& tile)
{
	m_EnemyMap.SetTile(tile);
}
//void Player::PrintShips(){
//	for (std::vector<Ship*>::iterator IterPos = m_MyShips.begin(); IterPos != m_MyShips.end(); ++IterPos){
//		(*IterPos)->PrintPos();
//		std::cout << (*IterPos)->GetName() << "\n";
//	}
//}
int Player::GetHP(){
	int HP = 0;
	for (auto ship : m_MyShips){
		HP += ship->GetHP();
	}
	return HP;
}
void Player::SetShipOnMyMap(Ship& ship)
{
	Point head = ship.GetHeadPos();
	Point tail = ship.GetTailPos();
	Tile tmpTile;
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
			m_MyMap.SetTile(tmpTile);
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
			m_MyMap.SetTile(tmpTile);
		}
	}
	else printf("unexpected err");
}
//void Player::SetTile(Tile& tile, Map& map)
//{
//	map.SetTile(tile);
//
//}
//void Player::SetMyTile(Tile& tile)
//{
//	SetTile(tile, m_MyMap);
//}
//void Player::SetEnemyTile(Tile& tile)
//{
//	m_EnemyMap.SetTile(tile);
//}
bool Player::IsValidAttackPos(Point pos)
{
	if ( m_EnemyMap.GetTile(pos).GetTileState() == ETile::NONE ) return true;
	else return false;
}
bool Player::IsValidShipPositionOnMap(const Point& head, const Point& tail)
{
	bool isHorizontal = head.GetX() == tail.GetX();
	for (auto ship : m_MyShips){
		Point& shipHead = ship->GetHeadPos();
		Point& shipTail = ship->GetTailPos();
		if ((shipHead.GetX() == -1) || (shipTail.GetX() == -1)) continue;
		if (!Utility::Instance().IsUncrossedLine(head, tail, shipHead, shipTail))
		{
			return false;
		}
	}
	return true;
}