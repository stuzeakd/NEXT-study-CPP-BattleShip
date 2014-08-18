#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	InitShips();
	m_PlayerName = "";
}
Player::~Player()
{
}
Player::Player(EPlayer::Type type){
}

void Player::InitShips()
{
	for (int i = 0; i < _countof(shipRule); i++){
		m_MyShips.push_back(ShipFactory::Instance() -> GenerateShip(shipRule[i], i));
	}
	for (int i = 0; i < _countof(shipRule); i++){
		m_EnemyShips.push_back(ShipFactory::Instance()->GenerateShip(shipRule[i], i));
	}
	m_Msgs = new Messages();
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
void Player::UpdateTileOnMap(Tile& tile, Map& map)
{
	map.SetTile(tile);
}
void Player::UpdateTileOnMyMap(Tile tile)
{
	m_MyMap.SetTile(tile);
}
void Player::UpdateTileOnEnemyMap(Tile tile)
{
	m_EnemyMap.SetTile(tile);
	//UpdateTileOnMap(tile, m_EnemyMap);
	//printf("after update : %d point (%d, %d)\n", m_EnemyMap.GetTile(tile).GetTileState(), m_EnemyMap.GetTile(tile).GetX(), m_EnemyMap.GetTile(tile).GetY());
}
Point Player::Attack()
{
	GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, "Attack!");
	Point pos = MakeShipPos();
	while (!IsValidAttackPos(pos))
	{
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, "You already did.");
		GameUIIngame::Instance().DrawInput("Position : ");
		pos = MakeShipPos();
	}
	return pos;
}
Point Player::MakeShipPos()
{
	GameUIIngame::Instance().DrawInput("Position : ");
	std::string input;
	std::cin >> input;
	getchar();
	while (!Utility::Instance().IsValidRC(input)){
		GameUIIngame::Instance().DrawSystemMsgs(m_Msgs, "Wrong Input");
		GameUIIngame::Instance().DrawInput("Position : ");
		//printf("errinMakeShipPos");
		std::cin >> input; 
		getchar();
	}
	return Utility::Instance().StringToPoint(input);                  
}
void Player::PrintShips(){
	for (std::vector<Ship*>::iterator IterPos = m_MyShips.begin(); IterPos != m_MyShips.end(); ++IterPos){
		(*IterPos)->PrintPos();
		std::cout << (*IterPos)->GetName() << "\n";
	}
}
int Player::GetHP(){
	int HP = 0;
	for (auto ship : m_MyShips){
		HP += ship->GetHP();
	}
	return HP;
}
void Player::SetTile(Tile& tile, Map& map)
{
	map.SetTile(tile);

}
void Player::SetMyTile(Tile& tile)
{
	SetTile(tile, m_MyMap);
}
void Player::SetEnemyTile(Tile& tile)
{
	m_EnemyMap.SetTile(tile);
}
bool Player::IsValidAttackPos(Point pos)
{
	if ( m_EnemyMap.GetTile(pos).GetTileState() == ETile::NONE ) return true;
	else return false;
}
