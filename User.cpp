
#include "User.h"
#include <iostream>
using namespace std;

int User::nextId = 1;

User::User(string email, string name, string password, int age) {
    this->id = nextId++;
	this->age = age;
	this->email = email;
	this->name = name;
	this->password = password;
	this->isAdmin = false;
}


