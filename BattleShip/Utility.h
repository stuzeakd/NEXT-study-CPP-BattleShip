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
	char Utility::LowerToUpper(char c);
	char RowOfPoint(Point pos);
	char ColOfPoint(Point pos);
};

