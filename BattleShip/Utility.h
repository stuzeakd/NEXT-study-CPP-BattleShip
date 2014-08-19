#pragma once
#include "common.h"
class Utility
{
public:
	static Utility& Instance();
	~Utility();
private:
	Utility();

protected:
	static Utility* m_Instance;

public:
	std::string GetInput(void);
	Point StringToPoint(std::string &rc);
	bool IsValidRC(std::string &rc);
	bool IsValidLowerRow(char c);
	bool IsValidUpperRow(char c);
	bool IsValidNumCol(char c);
	bool HaveSameX(Point& pos1, Point& pos2){ return pos1.GetX() == pos2.GetX(); }
	bool HaveSameY(Point& pos1, Point& pos2){ return pos1.GetY() == pos2.GetY(); }
	bool IsUncrossedLine(const Point& line1pos1, const Point& line1pos2, const Point& line2pos1, const Point& line2pos2);
	char Utility::LowerToUpper(char c);
	char RowOfPoint(Point pos);
	char ColOfPoint(Point pos);
};

