#pragma once
#include <string>

class Password
{
public:
	Password();
	Password(std::string password);
	bool check_password(std::string password);
	void change_password(std::string password);
private:
	std::string m_password;
	int m_key;
};

