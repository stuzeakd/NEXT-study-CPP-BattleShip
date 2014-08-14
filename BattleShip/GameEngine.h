#pragma once
#include "GameUIMain.h"
#include "GameManager.h"

//Singleton Class
namespace EGameEngine
{
	enum State{
		MAIN,
		INGAME,
		QUIT,
	};
}

class GameEngine
{
public:
	static GameEngine& Instance();
	~GameEngine();

protected:
	GameEngine();

public:
	void PrintTest();
	void Run();
	
private:
	static GameEngine* m_Instance;
};

