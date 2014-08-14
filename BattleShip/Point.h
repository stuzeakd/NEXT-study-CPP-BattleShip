#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

public:
	int GetX() const { return m_X; };
	int GetY() const { return m_Y; };
	void SetX(char x){ m_X = x; };
	void SetY(char y){ m_Y = y; };
	void Print();

private:
	char m_X, m_Y;
	


};