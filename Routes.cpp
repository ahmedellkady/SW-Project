#include <vector>
#include <iostream>
#include <conio.h>
#include "Auth.h"
#include "globals.h"
using namespace std;

        vector<string> usersMenu {"show Movies", "Exit"};
  vector<string> authMenu {"Register", "Login"};
    vector<string> adminsMenu {"Remove Movies", "listMovies", "listUsers", " Movie", "Exit"};
// Print the menu with highlight
void printMenu(const vector<string>& menu, int choice) {
    system("cls");
    cout << "\nUse Up/Down arrows to navigate, Enter to select, Esc to exit.\n\n";
    for (int i = 0; i < menu.size(); i++) {
        if (i == choice)
            cout << "\033[31m" << " >> " << menu[i] << " << " << "\033[0m" << endl;
        else
            cout << " >> " << menu[i] << " << " << endl;
    }
}
vector<string> preper_Movies_To_be_Printed_As_Menue (const vector<Movie>& Movies) {
    vector<string> MoviesAsString;
   for (int i = 0; i < Movies.size(); i++) {
   MoviesAsString.push_back( Movies[i].getId() + "\n" +  Movies[i].getTitle() ) ;        
    }
    return MoviesAsString;
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


void Route( int menuNum, std::vector<std::string> menu ) {
    int customerid;
    while (true) {
    static int choice = 0;

    printMenu(menu, choice);
    
    int action = makeAction(choice, menu.size());

    switch (menuNum) {
        case 1: { // auth menu
            switch (action) {
                case 1:
                    if (choice == 0) registerForm();
                    else if (choice == 1) 
                    {
                        customerid=loginForm()-1;
                    if (!loginForm) break;
                        Route(2,usersMenu);
                    }
                    system("pause");
                    break;

                case -1:
                    exit(0);

                default:
                    std::cout << "Use arrows to navigate\n";
                    break;
            }
            break; // break for case 1
        }

        case 2: { // user menu
            switch (action) {
             case 1:
                    if (choice == 0) printMovies(Customers.at(customerid).listMovies());

                    else if (choice == 1)Route(1,authMenu);
             
                    
                    system("pause");
                    break;
                case -1:
                    exit(0);
                default:
                    std::cout << "Use arrows to navigate\n";
                    break;
            }
            break; // break for case 2
        }

        default:
            break;
    }
}
}

