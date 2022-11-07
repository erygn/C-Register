#include "Register.h"
#include <iostream>

using namespace std;

Register::Register() : m_password(0), m_role(1) {
	m_password = new Password();
}

Register::Register(string username, string password, int role_number) : m_username(username), m_password(0), m_role(role_number) {
	m_password = new Password(password);
}

Register::Register(Register const& registerCopy) : m_username(registerCopy.m_username), m_password(0), m_role(registerCopy.m_role) {
	m_password = new Password(*(registerCopy.m_password));
}

void Register::print_username() const {
	cout << m_username << endl;
}

void Register::print_role() const {
	cout << m_username << " -> " << m_role << endl;
}

bool Register::change_role(int role) {
	m_role = role;
	return true;
}

void Register::change_role_user(Register &registerChange, int role) const {
	registerChange.change_role(role);
}

bool Register::password_check(string password) {
	if (!m_password->check_password(password)) {
		return false;
	}
	return true;
}

string Register::get_username() {
	return m_username;
}

Register::~Register() {
	delete m_password;
}