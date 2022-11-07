#include <iostream>
#include <string>
#include "Register.h"
#include "User.h"
#include <unordered_map>

using namespace std;

int main()
{
    Register actualRegister;
    bool actualRegisterConnect = false;
    bool running = true;
    unordered_map<string, Register> map_register;
    Register reg("test", "test", 1);
    map_register.emplace("test", reg);

    /*if (map_register.find("test") != map_register.end()) {
        cout << "Inside" << endl;
    }*/

    while (running) {
        if (actualRegisterConnect) {
            cout << "--- Account " << actualRegister.get_username() << " ---" << endl;
            cout << "1. Print info" << endl;
            cout << "2. Change password" << endl;
            cout << "3. Logout" << endl;
            cout << "Choice: ";

            string choice;
            getline(cin, choice);

            while (choice != "1" && choice != "2" && choice != "3") {
                cout << "Select option 1, 2 or 3" << endl;
                cout << "Choice: ";
                getline(cin, choice);
            }

            if (choice == "3") {
                actualRegisterConnect = false;
            }
            else if (choice == "1") {
                actualRegister.print_username();
                actualRegister.print_role();
            }
        }
        else {
            cout << "--- Register System ---" << endl;
            cout << "1. Connect" << endl;
            cout << "2. Register" << endl;
            cout << "3. Quit" << endl;
            cout << "Choice: ";

            string choice;
            getline(cin, choice);

            while (choice != "1" && choice != "2" && choice != "3") {
                cout << "Select option 1, 2 or 3" << endl;
                cout << "Choice: ";
                getline(cin, choice);
            }

            if (choice == "1") {
                string username;
                string password;
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";
                getline(cin, password);

                bool userConnect = false;
                if (map_register.find(username) != map_register.end()) {
                    Register checkConnect = map_register[username];
                    if (checkConnect.password_check(password)) {
                        userConnect = true;
                        actualRegister = checkConnect;
                        actualRegisterConnect = true;
                    }
                }
                if (!userConnect) {
                    cout << "Can't connect to user" << endl;
                }
                else {
                    cout << "Connected!" << endl;
                    actualRegister.print_role();
                }
            }
            else if (choice == "3") {
                running = false;
            }
            else {
                string username;
                string password;
                cout << "Username: ";
                getline(cin, username);

                while (map_register.find(username) != map_register.end()) {
                    cout << "Username already used, choise another one" << endl;
                    cout << "Username: ";
                    getline(cin, username);
                }
                cout << "Password: ";
                getline(cin, password);

                User newAccount(username, password);
                map_register.emplace(username, newAccount);
                actualRegister = newAccount;
                actualRegisterConnect = true;
                cout << "Congrats! " << username << endl;
            }
        }
        cout << endl;
    }

    return 0;
}