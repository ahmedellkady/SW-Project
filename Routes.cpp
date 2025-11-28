#include <vector>
#include <iostream>
#include <conio.h>
#include "Auth.h"
#include "globals.h"
using namespace std;

        vector<string> usersMenu {"show Movies", "Exit"};
  vector<string> authMenu {"Register", "Login"};
    vector<string> adminsMenu {"Remove Movies", "listMovies", "listUsers", "add Movie", "Exit"};
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

        if (menu.empty()) {
            cout << "Menu is empty!\n";
            cout << "Press any key to return...\n";
            _getch();
            return;
        }

        cout << "\nUse Up/Down arrows to navigate, Enter to select, Esc to exit.\n\n";

        bool lastIsNumber = isNumber(menu.back());
        int size = menu.size();
        if (lastIsNumber) { size -= 1; }

        if (choice >= size) choice = size - 1;
        if (choice < 0) choice = 0;

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
     Movies_as_String.push_back("id: "+to_string(movie.getId())+" || Title: "+movie.getTitle()+" || Description: "+movie.getdescription()+""
     + " || Duration: "  +to_string(movie.getduration())+" "+" || Enter To see Avilable Seats "
    );
                        
    return Movies_as_String;
}

vector<string> preper_Users_As_Menu(const vector<Customer>& customers) {
        vector<string> customers_as_String;
        for (auto customer : customers)
            customers_as_String.push_back(
                "id: " + to_string(customer.getId()) +
                " || Name: " + customer.getName() +
                " || Email: " + customer.getEmail()
            );
        return customers_as_String;
    }


vector<string> preper_Movies_Showtimes_As_Menue ( vector<Movie>& Movies, int choice) {
    vector<string> Movies_as_String;
    system("cls");
      int index=1;
         for(auto showtime : Movies.at(choice).viewShowTimes()){            
            Movies_as_String.push_back("\nFilm Name "+Movies.at(choice).getTitle()+"\nShow Time Number "+to_string(index)
                +"\nSeats: "+to_string(showtime.getNumberOfSeats())+ "Date is : "+showtime.getDate()
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

    if (key == 27) { //ESC
        cin.ignore();
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


void Route( int menuNum=1,std::vector<std::string> menu={"Register", "Login"},int c =0 ) {
    int customerid;
    while (true) {
    static int choice = c;

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
                        if(customerid==-101) {

                            system("pause");
                            choice =0;
                            Route(5/*case switch number 2*/,adminsMenu);
                        }else if (customerid<0){
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
        case 5: { // Admin menu
            switch (action) {
                case 1: // Enter pressed
                    switch (choice) {
                        case 0: // Remove Movies
                        {
                            system("cls");
                            cout << "Current Movies:\n";
                            for (const auto& movie : movies) {
                                cout << "ID: " << movie.getId()
                                     << " || Title: " << movie.getTitle()
                                     << " || Description: " << movie.getdescription()
                                     << " || Duration: " << movie.getduration() << "\n";
                            }

                            int temp = -1;
                            cout << "\nEnter the Id of the movie to remove: ";
                            cin >> temp;

                            bool found = false;
                            for (const auto& movie : movies) {
                                if (movie.getId() == temp) {
                                    found = true;
                                    break;
                                }
                            }

                            if (found) {
                                admin.removeMovie(temp);
                                cout << "\nMovie with Id " << temp << " removed successfully.\n";
                            } else {
                                cout << "\nError: Movie with Id " << temp << " not found!\n";
                            }

                            cout << "\nPress any key to return to Admin Menu...";
                            _getch();
                            Route(5, adminsMenu,0);
                            break;
                        }


                        case 1: // listMovies
                        {
                            vector<string> movieMenu = preper_Movies_Properties_As_Menue(movies);
                            int movieChoice = 0;
                            while (true) {
                                printMenu(movieMenu, movieChoice);
                                int action = makeAction(movieChoice, movieMenu.size());
                                if (action == 1 || action == -1)
                                    break;
                            }
                            Route(5, adminsMenu);
                            break;
                        }
                        case 2: // listUsers
                        {
                            vector<string> usersMenuList = preper_Users_As_Menu(Customers);
                            int userChoice = 0;
                            while (true) {
                                printMenu(usersMenuList, userChoice);
                                int action = makeAction(userChoice, usersMenuList.size());
                                if (action == 1 || action == -1) // Enter أو ESC
                                    break;
                            }
                            Route(5, adminsMenu);
                            break;
                        }

                        case 3: // Add Movie
                        {
                            system("cls");
                            cin.ignore();
                            string title, description;
                            int duration;
                            int categoryChoice;
                            vector<ShowTime> showTimes;

                            cout << "\033[3;5H\033[36mEnter Title of Movie: \033[0m";
                            getline(cin >> ws, title);

                            cout << "\033[5;5H\033[36mEnter Description: \033[0m";
                            getline(cin, description);

                            cout << "\033[7;5H\033[36mEnter Duration (minutes): \033[0m";
                            cin >> duration;

                            cout << "\033[9;5H\033[36mSelect Category (0: Action, 1: Comedy, 2: Drama ...): \033[0m";
                            cin >> categoryChoice;
                            Category category = static_cast<Category>(categoryChoice);
                            int numShowTimes;
                            cout << "\033[11;5H\033[36mEnter number of show times: \033[0m";
                            cin >> numShowTimes;
                            cin.ignore();

                            for (int i = 0; i < numShowTimes; i++) {
                                int seatsNum;
                                string date;

                                cout << "\033[" << 13 + i*3 << ";5H\033[36mEnter number of seats for showtime " << i+1 << ": \033[0m";
                                cin >> seatsNum;
                                cin.ignore();

                                cout << "\033[" << 14 + i*3 << ";5H\033[36mEnter date for showtime " << i+1 << " (e.g., 2025-12-31): \033[0m";
                                getline(cin, date);

                                showTimes.emplace_back(seatsNum, date);
                            }

                            Movie newMovie(title, description, duration, category, showTimes);

                            bool exists = false;
                            for (const auto& movie : movies) {
                                if (movie.getId() == newMovie.getId()) {
                                    exists = true;
                                    break;
                                }
                            }

                            if (exists) {
                                cout << "\nID already exists! Movie not added.\n";
                            } else {
                                admin.addMovie(newMovie);
                                cout << "\nMovie added successfully!\n";
                            }

                            cout << "\nPress any key to return to Admin Menu...";
                            _getch();
                            Route(5, adminsMenu);
                            break;
                        }


                        case 4: // Exit
                            Route(1, authMenu,0);// go back to auth menu
                        break;
                        default:
                            break;
                    }
                break;

                case -1: // ESC pressed
                    Route(1, authMenu); // go back to auth menu
                break;

                default:
                    cout << "Use arrows to navigate\n";
                break;
            }
            break;

        }

        default:
            break;
    }
}

}

