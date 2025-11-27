

//
// Created by Lenovo on 11/26/2025.
//

#include "Admin.h"

#include <iostream>
#include <ostream>
#include "globals.h"


void Admin::displayRole() {
    cout<<"Admin"<<endl;
}
void Admin::addMovie(Movie movie ) {
    movies.push_back(movie);
    cout << "Movie \"" << movie.getTitle() << "\" added successfully.\n";
}

void Admin::removeMovie(int id) {
    bool found = false;
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getId() == id) {
            cout << "Removing movie: " << it->getTitle() << endl;
            movies.erase(it);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Movie with ID " << id << " not found.\n";
    }
}

vector<shared_ptr<User>> Admin::listUsers() {
    for (auto &u : ::users) {
        cout << "\033[33m\033[3mID #"
             << u->getId()
             << "\033[0m : ";
        u->displayRole();
    }
    return ::users;
}


