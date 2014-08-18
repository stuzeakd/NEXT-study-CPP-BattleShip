// BattleShip.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "common.h"
#include "Ship.h"
#include "Player.h"
#include "GameEngine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	GameEngine::Instance().Run();

	//Human p1;
	//AI p2;
	//p1.SetPlayerName("Deok");
	//Map map = p2.GetMap();
	//while (1)
	//{
	//	Point pos = p1.MakeShipPos();
	//	while (!p1.IsValidAttackPos(pos))
	//	{
	//		printf("err\n");
	//		pos = p1.MakeShipPos();
	//	}
	//	Tile tile = map.GetTile(pos);
	//	tile.SetTileState(ETile::MISS);
	//	printf("input : %d (%d, %d)\n", tile.GetTileState(), tile.GetX(), tile.GetY());
	//	p1.UpdateTileOnEnemyMap(tile);
	//	printf("out : %d point (%d,%d) \n", 
	//		p1.m_EnemyMap.GetTile(pos).GetTileState(), p1.m_EnemyMap.GetTile(pos).GetX(), p1.m_EnemyMap.GetTile(pos).GetY());
	//}
	getchar();
	return 0;
}

	