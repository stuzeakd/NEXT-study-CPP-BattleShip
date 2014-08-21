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
	Point	StringToPoint(const std::string &rc) const;
	bool	IsValidRC(const std::string &rc) const;
	bool	IsValidLowerRow(char c) const;
	bool	IsValidUpperRow(char c) const;
	bool	IsValidNumCol(char c) const;
	bool	IsUncrossedLine(const Point& line1pos1, const Point& line1pos2, const Point& line2pos1, const Point& line2pos2) const;
	char	Utility::LowerToUpper(char c) const;
	char	RowOfPoint(const Point& pos) const;
	char	ColOfPoint(const Point& pos) const;
};

