#include <windows.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Customer.h"
#include "globals.h"
#include "Admin.h"
#include "usersMeneuFunctions.h"
#include "Routes.h"
using namespace std;



int route = 0;
int indexOfCustomerLoggedIn;
int main() {
    //make static Admin
    Admin admin("a", "a","a", 150);
    ShowTime show1(5);
    ShowTime show2(5);
    vector<ShowTime> showTimes1 = {show1, show2};
    
    // Admin adds movies  
    Movie m1("Avengers", "Action movie", 120, Category::Action, showTimes1);
    Movie m2("The Hangover", "Comedy movie", 100, Category::Comedy, showTimes1);

    admin.addMovie(m1);
    admin.addMovie(m2);    // Create movies
     Route();

    cout << "Bye!" << endl;
    return 0;
}




