#pragma once

namespace EUDLRRand
{
	enum Direc
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT = 3,
	};
}
class UDLRRand
{
public:
	UDLRRand();
	~UDLRRand();
	
	void Reset();
	EUDLRRand::Direc GetRand();
	bool IsEmpty();

private:
	bool dir[4];
};

