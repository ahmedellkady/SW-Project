//
// Created by Lenovo on 11/26/2025.
//

#ifndef SHOWTIME_H
#define SHOWTIME_H
#include <string>
#include <vector>

using namespace std;

class ShowTime {
    static  int nextId ;
    int id;
    int numberOfSeats ;
    vector<bool> seats;
    bool isfull ;
    public:
    ShowTime(int num) {
        id = nextId;
        nextId++;
        numberOfSeats = num;
        seats.resize(num, false);
        isfull = false;
    }
    void showAvailableSeats();

};



#endif //SHOWTIME_H
