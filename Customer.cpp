//
// Created by Lenovo on 11/26/2025.
//

#include "Customer.h"

#include <iostream>
#include <ostream>
#include <vector>
#include "globals.h"
#include <algorithm>


void Customer::bookSeat(int  movieid, int showTimeid) {
bool Isfull = movies.at(movieid).viewShowTimes().at(showTimeid).getIsfull();
if(Isfull) { cout<<"\n no Seats left \n";return;};
 cout<<"\n You Choosed "+ movies.at(movieid).getTitle()+ " film to Reserve \n";
 cout<<"\n at Show Time Number: "+ to_string(movies.at(movieid).viewShowTimes().at(showTimeid).getId())+ "\n";
 cout<<"\n seat reserved Number: "+ to_string(movies.at(movieid).viewShowTimes().at(showTimeid).reserve_a_seat())+ "\n";
 cout<<"\n seats Left  : "+ to_string(movies.at(movieid).viewShowTimes().at(showTimeid).getNumberOfSeats())+ " \n";
}

void Customer::displayRole() {
    cout <<" Customer "<<endl;
}

