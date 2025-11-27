#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Movie.h"
#include "ShowTime.h"
#include "User.h"
#include <memory>

class Customer : public User {
public:
    Customer(int id,
             const std::string& email,
             const std::string& name,
             const std::string& password,
             int age);

    virtual ~Customer() = default;

    virtual void displayRole() const override;

    // book a seat in a given showtime of a movie
    void bookSeat(const std::shared_ptr<Movie>& movie,
                  const std::shared_ptr<ShowTime>& showTime,
                  int seatIndex);
};

#endif //CUSTOMER_H
