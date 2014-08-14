// BattleShip_PP.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Player p1 = Player();
	Player ai = Player(); // 상속
	Gamemanager justice = Gamemanager(p1.ReturnMap(), ai.ReturnMap());
	justice.GameStart();

	while (1){
		justice.AttackCheck(p1.attack());
		if (justice.isGameEnd()) break;
		p1.StateUpdate(/**/); // player HP update, Map update, Ship update 
		justice.AttackCheck(ai.attck() );
		if (justice.isGameEnd()) break;
		ai.StateUpdate(/**/); // player "
	}

	justice.EndMessage();

	return 0;

}

