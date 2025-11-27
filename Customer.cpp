#include "Customer.h"
#include "Movie.h"
#include "ShowTime.h"
#include <iostream>

Customer::Customer(int id,
                   const std::string& email,
                   const std::string& name,
                   const std::string& password,
                   int age)
    : User(id, email, name, password, age, /* isAdmin = */ false) {}

void Customer::displayRole() const {
    std::cout << "Role: Customer (user id = " << getId() << ", name = " << getName() << ")\n";
}

void Customer::bookSeat(const std::shared_ptr<Movie>& movie,
                        const std::shared_ptr<ShowTime>& showTime,
                        int seatIndex) {
    // naive implementation: attempt to book seat in the showtime
    if (showTime->bookSeat(seatIndex)) {
        std::cout << "Seat " << seatIndex
                  << " successfully booked for movie \""
                  << movie->getTitle()
                  << "\" at showtime " << showTime->getDate()
                  << "\n";
    } else {
        std::cout << "Failed to book seat " << seatIndex
                  << ". It may already be booked or invalid.\n";
    }
}
