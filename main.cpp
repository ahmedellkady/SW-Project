#include <iostream>
#include <memory>
#include "Admin.h"
#include "Customer.h"
#include "Movie.h"
#include "ShowTime.h"
#include "globals.h"

using namespace std;

int main() {
    // Create admin
    shared_ptr<Admin> admin = make_shared<Admin>();

    // Create customers
    shared_ptr<User> customer1 = make_shared<Customer>();
    shared_ptr<User> customer2 = make_shared<Customer>();

    // Add users to global users vector
    users.push_back(admin);
    users.push_back(customer1);
    users.push_back(customer2);

    // Test listUsers()
    cout << "Listing all users:\n";

    admin->listUsers();

    // Create some ShowTimes
    ShowTime show1(5);
    ShowTime show2(5);
    vector<ShowTime> showTimes1 = {show1, show2};

    // Create movies
    Movie m1("Avengers", "Action movie", 120, Category::Action, showTimes1);
    Movie m2("The Hangover", "Comedy movie", 100, Category::Comedy, showTimes1);

    // Admin adds movies
    admin->addMovie(m1);
    admin->addMovie(m2);

    // Display all movies
    admin->listMovies();

    // Remove a movie
    admin->removeMovie(1);

    // Display remaining movies
    cout << "\nMovies after removal:\n";
    admin->listMovies();

    return 0;
}
