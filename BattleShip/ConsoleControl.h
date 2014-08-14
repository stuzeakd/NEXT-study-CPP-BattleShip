#pragma once
#include <Windows.h>
#include <conio.h>
#include "common.h"
//Singleton Class

struct ColorSet
{
	int m_FontColor;
	int m_BackColor;
};

class ConsoleControl
{
public:
	~ConsoleControl();
	static ConsoleControl& Instance();

protected:
	ConsoleControl();

public:
	void Gotoxy(int x, int y);
	void Gotoxy(Point pos);
	void Setcolor(int color, int bgcolor);
//	void Setcolor(ColorSet consoleColor);
	int CursorPosVerti(std::string cursor, Point stdPos, int range, int interval, int state);
	void Clear();

	static ConsoleControl* m_Instance;

private:

};
