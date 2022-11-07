#include "Password.h"
#include <string>

using namespace std;

Password::Password() : m_password("1234"), m_key(1) {

}

Password::Password(string password) : m_password(password), m_key(1) {

}

bool Password::check_password(string password) {
	if (m_password != password) {
		return false;
	}
	return true;
}

void Password::change_password(string password) {
	m_password = password;
}