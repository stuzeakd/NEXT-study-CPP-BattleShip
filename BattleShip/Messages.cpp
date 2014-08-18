#include "stdafx.h"
#include "Messages.h"

Messages::Messages()
{
}
Messages::~Messages()
{
}
void Messages::SetNewMessage(std::string msg)
{
	m_MsgVector.push_back(msg);
}
