#include "stdafx.h"
#include "UDLRRand.h"


UDLRRand::UDLRRand()
{
	Reset();
}


UDLRRand::~UDLRRand()
{
}

void UDLRRand::Reset()
{
	for (int i = 0; i < _countof(dir); i++)
	{
		dir[i] = true;
	}
}
EUDLRRand::Direc UDLRRand::GetRand()
{
	srand(time(NULL));
	int i;
	do
	{
		i = rand() % 4;
	}while (!dir[i]);
	dir[i] = false; 
	return (EUDLRRand::Direc)i;
}
bool UDLRRand::IsEmpty()
{
	for (int i = 0; i < _countof(dir); i++)
	{
		if (dir[i]) return false;
	}
	return true;
}