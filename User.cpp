
#include "User.h"
#include <iostream>

#include "globals.h"
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
vector<Movie> User::listMovies() {
    cout << "\033[34mListing of movies...\033[0m\n"; // Blue text

    for (int i = 0; i < movies.size(); i++) {

        cout << "\033[33m"
             << "\033[3m"
             << "Movie #"
             << movies[i].getId()
             << "\033[0m"
             << " : "
             << movies[i].getTitle()
             << "\033[0m"
             << endl;
    }
    return movies;
}

int User::getId() {
    return this->id;
}


