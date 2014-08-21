#include "stdafx.h"
#include "Utility.h"

Utility* Utility::m_Instance = nullptr;
Utility& Utility::Instance(){
	if (m_Instance == nullptr){
		m_Instance = new Utility();
	}
	return *m_Instance;
}
Utility::Utility()
{
}


Utility::~Utility()
{
}
std::string Utility::GetInput()
{
	std::string str;
	std::cin >> str;
	getchar(); //fflush
	return str;
}
Point Utility::StringToPoint(std::string &rc)
{
	Point pos;
	pos.SetX(Utility::Instance().LowerToUpper(rc.c_str()[0]) - 'A');
	pos.SetY(rc.c_str()[1] - '1');
	return pos;
}
bool Utility::IsValidRC(std::string &rc){
	//
	if ((rc.size() == 2) &&
		(IsValidLowerRow(rc.c_str()[0]) || IsValidUpperRow(rc.c_str()[0])) &&
		IsValidNumCol(rc.c_str()[1]))
		return true;
	else return false;
		//((rc.c_str()[0]<'a' || rc.c_str()[0]>'a' + MAP_COL) && (rc.c_str()[0]<'A' || rc.c_str()[0]>'A' + MAP_COL)) ||
		//(rc.c_str()[1]<'0' || rc.c_str()[1]>'0' + MAP_RAW)
}
bool Utility::IsValidLowerRow(char c){
	if ('a' <= c && c <= 'a' + MAP_ROW) return true;
	else return false;
}
bool Utility::IsValidUpperRow(char c){
	if ('A' <= c && c <= 'A' + MAP_ROW) return true;
	else return false;
}
bool Utility::IsValidNumCol(char c){
	if ('1' <= c && c <= '0' + MAP_COL) return true;
	else return false;
}
bool Utility::IsUncrossedLine(const Point& line1pos1, const Point& line1pos2, const Point& line2pos1, const Point& line2pos2)
{
	//Wrong input check. 
	//it is not line.
	if (line1pos1 == line1pos2 || line2pos1 == line2pos2) return false;

	int line1MinX = line1pos1.GetX() < line1pos2.GetX() ? line1pos1.GetX() : line1pos2.GetX();
	int line1MaxX = line1pos1.GetX() > line1pos2.GetX() ? line1pos1.GetX() : line1pos2.GetX();
	int line1MinY = line1pos1.GetY() < line1pos2.GetY() ? line1pos1.GetY() : line1pos2.GetY();
	int line1MaxY = line1pos1.GetY() > line1pos2.GetY() ? line1pos1.GetY() : line1pos2.GetY();

	//line is tilted.
	if ((line1MinX != line1MaxX) && (line1MinY != line1MinY)) return false;

	int line2MinX = line2pos1.GetX() < line2pos2.GetX() ? line2pos1.GetX() : line2pos2.GetX();
	int line2MaxX = line2pos1.GetX() > line2pos2.GetX() ? line2pos1.GetX() : line2pos2.GetX();
	int line2MinY = line2pos1.GetY() < line2pos2.GetY() ? line2pos1.GetY() : line2pos2.GetY();
	int line2MaxY = line2pos1.GetY() > line2pos2.GetY() ? line2pos1.GetY() : line2pos2.GetY();

	//line is tilted.
	if ((line2MinX != line2MaxX) && (line2MinY != line2MinY)) return false;

	if (line1MinX > line2MinX && line1MinX > line2MaxX) return true;
	else if (line1MaxX < line2MinX && line1MaxX < line2MaxX) return true;
	else if (line1MinY > line2MinY && line1MinY > line2MaxY) return true;
	else if (line1MaxY < line2MinY && line1MaxY < line2MaxY) return true;
	else return false;

	//bool isLine1Vertical = line1pos1.GetX() == line1pos2.GetX();
	//bool isLine2Vertical = line2pos1.GetX() == line2pos2.GetX();
	//bool isLine1Horizontal = line1pos1.GetY() == line1pos2.GetY();
	//bool isLine2Horizontal = line2pos1.GetY() == line2pos2.GetY();

	////They're Not a Line but just a Point. 
	//if ((isLine1Vertical && isLine1Horizontal) || (isLine2Vertical && isLine2Horizontal)) return false; 
	////Line is tilted
	//else if (!(isLine1Vertical || isLine1Horizontal) || !(isLine2Vertical || isLine2Horizontal)) return false;
	//
	//else if (isLine1Horizontal && isLine2Horizontal)
	//{
	//	if (line1pos1.GetY() != line2pos1.GetY()) return true; //Lines are parallel
	//	else return false; //Lines are same.
	//}
	//else if (isLine1Vertical && isLine2Vertical)
	//{
	//	if (line1pos1.GetX() != line2pos1.GetX()) return true; //Lines are parallel
	//	else return false; //Lines are same.
	//}

	//else if (isLine1Vertical && isLine2Horizontal)
	//{
	//	if (line1pos1.GetX() > line2pos1.GetX() && line1pos1.GetX() > line2pos2.GetX()) return true;
	//	else if (line1pos1.GetX() < line2pos1.GetX() && line1pos1.GetX() < line2pos2.GetX()) return true;
	//	else
	//	{
	//		if (line1pos1.GetY() > line2pos1.GetY() && line1pos2.GetY() > line2pos1.GetY()) return true;
	//		else if (line1pos1.GetY() < line2pos1.GetY() && line1pos2.GetY() < line2pos1.GetY()) return true;
	//		else return false;
	//	}
	//}
	//else if (isLine1Horizontal && isLine2Vertical)
	//{
	//	if (line1pos1.GetY() > line2pos1.GetY() && line1pos1.GetY() > line2pos2.GetY()) return true;
	//	else if (line1pos1.GetY() < line2pos1.GetY() && line1pos1.GetY() < line2pos2.GetY()) return true;
	//	else
	//	{
	//		if (line1pos1.GetX() > line2pos1.GetX() && line1pos2.GetX() > line2pos1.GetX()) return true;
	//		else if (line1pos1.GetX() < line2pos1.GetX() && line1pos2.GetX() < line2pos1.GetX()) return true;
	//		else return false;
	//	}
	//}
	//else printf("unexpected err");
}

char Utility::LowerToUpper(char c)
{
	if (IsValidLowerRow(c)) return c - ('a' - 'A');
	else return c;
}
char Utility::RowOfPoint(Point pos)
{
	return pos.GetX();
}
char Utility::ColOfPoint(Point pos)
{
	return pos.GetY();
}
