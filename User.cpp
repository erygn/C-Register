#include "User.h"
#include <string>

using namespace std;

User::User(string username, string password) : Register(username, password, 2) {
	
}

bool User::change_password(string old_password, string new_password) {
	if (!m_password->check_password(old_password)) {
		return false;
	}
	m_password->change_password(new_password);
	return true;
}