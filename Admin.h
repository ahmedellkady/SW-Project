//
// Created by Lenovo on 11/26/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "Customer.h"
#include "Movie.h"
#include "User.h"


class Admin: public User {

    public:
    Admin();
    vector<User> users;
    void addMovie(Movie movie);
    void removeMovie(int id);
    void displayRole() override;
    vector<Customer> listCustomers();

};



#endif //ADMIN_H
