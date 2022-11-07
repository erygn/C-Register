#pragma once
#include <string>
#include "Password.h"

class Register
{
public:
	Register();
	Register(std::string username, std::string password, int role_number);
	Register(Register const& registerCopy);
	void print_username() const;
	void print_role() const;
	bool change_role(int role);
	void change_role_user(Register &registerChange, int role) const;
	bool password_check(std::string password);
	std::string get_username();
	~Register();
protected:
	int m_role;
	std::string m_username;
	Password *m_password;
};

