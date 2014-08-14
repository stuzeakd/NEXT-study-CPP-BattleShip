#pragma once
#include "ConsoleControl.h"

namespace EGameUIMain
{
	enum Mode
	{
		VS_AI,
		VS_HUMAN,
		QUIT,
	};
}
class GameUIMain
{
public:
	static GameUIMain& Instance();
	~GameUIMain();

	void PrintMain();
	EGameUIMain::Mode SelectMode();
	void PrintBye();

private:
	GameUIMain();
	static GameUIMain* m_Instance;
	static const std::string m_Cursor;
};

