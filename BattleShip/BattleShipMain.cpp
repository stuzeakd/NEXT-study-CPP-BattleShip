// BattleShip.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "common.h"
#include "Ship.h"
#include "Player.h"
#include "GameEngine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	GameEngine::Instance().Run();
	getchar();
	return 0;
}

	