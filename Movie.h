
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

#include "ShowTime.h"

using namespace std;


enum class Category {
  Comedy,
  Action,
  Drama
};

class Movie {
  static int nextId ;
  int id ;
  string title ;
  string description ;
  int duration ;
  Category category ;
  vector<ShowTime> showTimes ;
  public:
    Movie( string title, string description,
    int duration, Category category,vector<ShowTime> showTimes);
    vector<ShowTime> viewShowTimes();
    int getId() const ;
    string getTitle() const ;

};


#endif //MOVIE_H
