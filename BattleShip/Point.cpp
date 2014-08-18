#include "stdafx.h"
#include "Point.h"


Point::Point()
{
	m_X = -1;
	m_Y = -1;
}
Point::Point(int x, int y){
	m_X = x;
	m_Y = y;
}

Point::~Point()
{
}
Point::Point(const Point & src)
{
	m_X = src.GetX();
	m_Y = src.GetY();
}

void Point::Print(){
	printf_s("%d%d", m_X, m_Y);
}