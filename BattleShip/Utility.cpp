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
