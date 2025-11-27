#ifndef USER_H
#define USER_H

#include <string>
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

    virtual void displayRole() = 0;
};

#endif
