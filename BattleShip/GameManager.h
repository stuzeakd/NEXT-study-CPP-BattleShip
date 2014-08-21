#pragma once
#include "Player.h"
#include "GameUIIngame.h"
#include "AI.h"
#include "Human.h"
#include "Utility.h"

struct PlayerData
{
	Player *player;
	Map map;
	std::vector<Ship*> ships;
};

class Tile;
class GameManager
{
public:
	static GameManager& Instance();
	~GameManager();
private:
	GameManager();
	static GameManager* m_Instance;

public:
	void Run();
	void GameInit();
	void GameStart();
	bool IsTimeToQuit(){ return (m_P1Data.player->GetHP() == 0) || (m_P2Data.player->GetHP() == 0); }
	void Draw() const;
	Tile HitCheck(const Point& pos);
	void Update(Tile &tile);
	void SwapAttDef();

protected:
	//Ship

protected:
	PlayerData m_P1Data;
	PlayerData m_P2Data;
	PlayerData *m_AttackerData;
	PlayerData *m_DefenderData;
};

