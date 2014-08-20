#pragma once

class Messages
{
public:
	Messages();
	~Messages();
	
public:
	void						SetNewMessage(std::string msg);
	std::vector<std::string>&	GetMessageVector(){ return m_MsgVector; }

private:
	//I'm hungry.
	std::vector<std::string> m_MsgVector;
};

