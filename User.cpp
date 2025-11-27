
#include "User.h"
#include <iostream>
using namespace std;

int User::nextId = 1;

User::User() {
    this->id = nextId;
    nextId++;
}

void User::login(string email, string password) {
    if (this->email == email && this->password == password) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid email or password.\n";
    }
}
void User::registerAccount(string email, string password, int age) {
    this->email = email;
    this->password = password;
    this->age = age;

    cout << "User registered successfully!\n";
}


