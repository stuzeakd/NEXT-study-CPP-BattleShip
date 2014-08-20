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
}


ConsoleControl::~ConsoleControl()
{
}
void ConsoleControl::Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void ConsoleControl::SetWindowSize(int width, int height)
{

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
int ConsoleControl::CursorPosVerti(std::string cursor, Point stdPos, int range , int interval, int state){
	int opt = state;
	char ch = 0;
	Point pos = { stdPos.GetX(), stdPos.GetY() + state * interval };
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
		if (ch == 72 && pos.GetY() > stdPos.GetY()){
			pos.SetY(pos.GetY() - interval);
			opt--;
		}
		else if (ch == 80 && pos.GetY() < stdPos.GetY() + (range - 1) * interval){
			pos.SetY(pos.GetY() + interval);
			opt++;
		}
	}
	return opt;
}