//
// Created by Lenovo on 11/27/2025.
//

#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <vector>
#include "Movie.h"
#include "User.h"

extern std::vector<Movie> movies; // ONLY declaration
extern std::vector<shared_ptr<User>> users;
#endif //GLOBALS_H
