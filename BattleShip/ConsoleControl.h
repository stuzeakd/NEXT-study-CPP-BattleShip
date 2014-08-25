#pragma once
#include <Windows.h>
#include <conio.h>
#include "common.h"

//color
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKMINT 3
#define DARKRED 4
#define DARKPURPLE 5
#define DARKYELLOW 6
#define GOLD 6
#define GREY 7
#define DARKGREY 8
#define BLUE 9
#define GREEN 10
#define MINT 11
#define RED 12
#define PURPLE 13
#define PINK 13
#define YELLOW 14
#define WHITE 15

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
	void SetTitle(const std::wstring& title);
	void SetTitle(const std::string& title);
	void SetWindowSize(int width, int height);
	void SetStdXY(int x, int y);
	void SetStdXY(Point stdPos);
	void Gotoxy(int x, int y);
	void Gotoxy(Point pos);
	void SetColor(int color, int bgcolor);
	void SetColor(ColorSet consoleColor);
	int	CursorPosVerti(std::string cursor, Point stdPos, int range, int interval, int state);
	void Clear();

	static ConsoleControl* m_Instance;

private:
	Point m_StdPos;
};
