#pragma once
#include "Player.h"
#include "GameUIIngame.h"
class GameManager
{
public:
	static GameManager& Instance();
	GameManager();
	~GameManager();

	void Run();
	void GameStart();
protected:
	Player *m_Attacker;
	Player *m_Defender;

private:
	static GameManager* m_Instance;

};

