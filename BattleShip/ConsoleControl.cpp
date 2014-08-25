#include "stdafx.h"
#include "ConsoleControl.h"

ConsoleControl* ConsoleControl::m_Instance = nullptr;
ConsoleControl& ConsoleControl::Instance()
{
	if (m_Instance == nullptr){
		m_Instance = new ConsoleControl();
	}
	return *m_Instance;
}
ConsoleControl::ConsoleControl()
{
	m_StdPos.SetX(0);
	m_StdPos.SetY(0);
}


ConsoleControl::~ConsoleControl()
{
}
void ConsoleControl::SetTitle(const std::wstring& title)
{
	SetConsoleTitle(title.c_str());
}
void ConsoleControl::SetTitle(const std::string& title)
{
	int len;
	int slength = (int)title.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, title.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, title.c_str(), slength, buf, len);
	std::wstring wTitle(buf);
	delete[] buf;
	SetTitle(wTitle);
}
void ConsoleControl::SetStdXY(int stdX, int stdY)
{
	m_StdPos.SetX(stdX);
	m_StdPos.SetY(stdY);
}
void ConsoleControl::SetStdXY(Point stdPos)
{
	SetStdXY(stdPos);
}
void ConsoleControl::Gotoxy(int x, int y)
{
	COORD pos = { m_StdPos.GetX() + x, m_StdPos.GetY() + y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void ConsoleControl::SetWindowSize(int width, int height)
{
	char widthC[8];
	char heightC[8];
	_itoa_s(width, widthC, 10);
	_itoa_s(height, heightC, 10);
	std::string widthCpp = widthC;
	std::string heightCpp = heightC;
	std::string result = "mode con:cols=" + widthCpp + " lines=" + heightCpp;
	system(result.c_str());
}
void ConsoleControl::Gotoxy(Point pos)
{
	Gotoxy(pos.GetX(), pos.GetY());
}
void ConsoleControl::SetColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
void ConsoleControl::SetColor(ColorSet consoleColor){
	SetColor(consoleColor.m_FontColor, consoleColor.m_BackColor);
}

void ConsoleControl::Clear(){
	system("cls");
}
int ConsoleControl::CursorPosVerti(std::string cursor, Point startPos, int range , int interval, int state){
	int opt = state;
	char ch = 0;
	Point pos = { startPos.GetX(), startPos.GetY() + state * interval };
	while (ch != '\r'){
		Gotoxy(pos);
		printf("%s", cursor.c_str());
		ch = _getch();
		if (ch == -32){
			ch = _getch();
		}
		if (ch == 72 || ch == 80){
			Gotoxy(pos);		
			printf("  ");
		}
		if (ch == 72 && pos.GetY() > startPos.GetY()){
			pos.SetY(pos.GetY() - interval);
			opt--;
		}
		else if (ch == 80 && pos.GetY() < startPos.GetY() + (range - 1) * interval){
			pos.SetY(pos.GetY() + interval);
			opt++;
		}
	}
	return opt;
}