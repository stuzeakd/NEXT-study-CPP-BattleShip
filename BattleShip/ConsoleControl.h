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
	void SetWindowSize(int width, int height);
	void Gotoxy(int x, int y);
	void Gotoxy(Point pos);
	void SetColor(int color, int bgcolor);
	void SetColor(ColorSet consoleColor);
	int CursorPosVerti(std::string cursor, Point stdPos, int range, int interval, int state);
	void Clear();

	static ConsoleControl* m_Instance;

private:

};
