#include <vector>
#include <iostream>
#include <conio.h>
#include "Auth.h"
#include "globals.h"
using namespace std;

        vector<string> usersMenu {"show Movies", "Exit"};
  vector<string> authMenu {"Register", "Login"};
    vector<string> adminsMenu {"Remove Movies", "listMovies", "listUsers", " Movie", "Exit"};
    bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}
// Print the menu with highlight
void printMenu(const vector<string>& menu, int choice) {
    system("cls");
    cout << "\nUse Up/Down arrows to navigate, Enter to select, Esc to exit.\n\n";
    bool lastIsNumber = isNumber(menu.back());
    int size = menu.size(); 
    if (lastIsNumber) {size-=1 ;}
if (choice>=size)choice-=1;
    for (int i = 0; i < size; i++) {
        if (i == choice)
            cout << "\033[31m" << " >> " << menu[i] << " << " << "\033[0m" << endl;
        else
            cout << " >> " << menu[i] << " << " << endl;
    
}
}
vector<string> preper_Movies_To_be_Printed_As_Menue (const vector<Movie>& Movies, int Moviechoice=0) {
    vector<string> Movies_as_String;
    for (int i = 0; i < Movies.size(); i++) {
Movies_as_String.push_back("id: "+to_string(Movies.at(i).getId())+" title: "+ Movies.at(i).getTitle() );
  
    }
    return Movies_as_String;
}
vector<string> preper_Movies_Properties_As_Menue (const vector<Movie>& Movies) {
    vector<string> Movies_as_String;
    for (auto movie:movies)
     Movies_as_String.push_back("\nid: "+to_string(movie.getId())+"\nTitle: "+movie.getTitle()+"\nDescription: "+movie.getdescription()+""
     + "\nDuration: "  +to_string(movie.getduration())+"\n"+"Enter To see Avilable Seats \n"
    );
                        
    return Movies_as_String;
}

vector<string> preper_Movies_Showtimes_As_Menue ( vector<Movie>& Movies, int choice) {
    vector<string> Movies_as_String;
    system("cls");
      int index=1;
         for(auto showtime : Movies.at(choice).viewShowTimes()){            
            Movies_as_String.push_back("\nFilm Name "+Movies.at(choice).getTitle()+"\nShow Time Number "+to_string(index)
                +"\nSeats: "+to_string(showtime.getNumberOfSeats())
            +"\nReservation Avilabilty: "+(!showtime.getIsfull()?"There are avilable seats\n":"no seats left\n")
            //+"index: "+to_string(index)+"Movies.size()-1: " + to_string(Movies.size()-1)

    );
                ++index;
                        } 
                        Movies_as_String.push_back(to_string(choice));//to know which film that user chose 
    return Movies_as_String;
}

// Handle key press, update choice, and return action
int makeAction(int &choice, int limit) {
    int key = _getch();

    if (key == 27) { // ESC
        return -1;
    }
    else if (key == 224) { // Arrow keys
        key = _getch();
        if (key == 72 && choice > 0) { // Up
            choice--;
        } else if (key == 80 && choice < limit - 1) { // Down
            choice++;
        }
        return 0;
    }
    else if (key == 13) { // Enter
        return 1;
    }

    return 0; // Other keys
}


void Route( int menuNum=1,std::vector<std::string> menu={"Register", "Login"},int choice =0 ) {
    int customerid;
    while (true) {
    static int choice = 0;

    printMenu(menu, choice);
    
    int action = makeAction(choice, menu.size());

    switch (menuNum) {
        case 1: { // auth menu
            switch (action) {
                case 1:
                    if (choice == 0){
                        
                        registerForm();
                          system("pause");
                    } 
                    else if (choice == 1) 
                    {
                     customerid=loginForm()-1;
                    if (customerid<0){ 
                      system("pause");
                        Route(1,authMenu);}
                          system("pause");
                    Route(2/*case switch number 2*/,usersMenu);// user menu >>show movies >>exit
                    }
                  
                    break;
                case -1:
                {cout<<"Bye!";
                    exit(0);
                }

                default:
                    break;
            }
            break; // break for case 1
        }

        case 2: { 
            switch (action) {
             case 1:
                    if (choice == 0)//>>show movies
                    {Route (3,preper_Movies_Properties_As_Menue (movies));}// id 1 title desc duration 
                    else if (choice == 1)Route(1,authMenu);//>>Exit       
                    system("pause");
                    break;
                case -1:
                    Route();
                default:
                    std::cout << "Use arrows to navigate\n";
                    break;
            }
            break; // break for case 2
        }

        // case 2: { // Movies menu >>id 1 title >> id2 title
        //     switch (action) {
        //      case 1://enter
        //             {
        //             {Route (3, preper_Movies_Properties_As_Menue (movies));}
        //             } 
        //             system("pause");
        //             break;
        //         case -1://esc back to screen 2 
        //             // {Route (2,preper_Movies_To_be_Printed_As_Menue(movies));}// id 1 title id2 title
        //             Route();   
        //         default:
        //             std::cout << "Use arrows to navigate\n";
        //             break;
        //     }
        //     break; // break for case 3
        // }
        case 3: { // Selected Movie Show Times 
            switch (action) {
             case 1://enter
                    {
                    {
                    Route (4, preper_Movies_Showtimes_As_Menue (movies,choice),choice);}
                    } 
                    system("pause");
                    break;
                case -1://Esc back to movies
                Route (2, preper_Movies_Properties_As_Menue(movies));

                default:
                    std::cout << "Use arrows to navigate\n";
                    break;
            }
            break; // break for case 3
        }
        case 4: { // reserve seat
            switch (action) {
             case 1://enter
                    {
                        system("cls");
 Customers.at(customerid).bookSeat(stoi(menu.back()),choice);
                    } 
                    system("pause");
                    break;
                case -1://Esc back to movies
                 Route (3, preper_Movies_Properties_As_Menue(movies));


                default:
                    std::cout << "Use arrows to navigate\n";
                    break;
            }
            break; // break for case 3
        }

        default:
            break;
    }
}
}

