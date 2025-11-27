#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Movie.h"
using namespace std;

class User {
protected:

    int id;
    string name;
    string email;
    string password;
    int age;
    bool isAdmin;

public:
    static int nextId;
    User();

    void login(string email, string password);
    void registerAccount(string email, string password, int age);
    vector<Movie> listMovies();
    virtual void displayRole() = 0;
    int getId();
};

#endif
