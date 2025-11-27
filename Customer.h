//
// Created by Lenovo on 11/26/2025.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Movie.h"
#include "User.h"


class Customer : public User {
public:
    void bookSeat(Movie movie,ShowTime showTime);
    void displayRole() override;
};



#endif //CUSTOMER_H
