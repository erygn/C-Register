#pragma once
#include <iostream>
#include <string>
#include "Register.h"

class User : public Register
{
public:
	User(std::string username, std::string password);
	bool change_password(std::string old_password, std::string new_password);
};

