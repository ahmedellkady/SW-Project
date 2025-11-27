#include <windows.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Customer.h"
#include "globals.h"

using namespace std;

// Function declarations
void printMenu(const vector<string>& menu, int choice);
int makeAction(int &choice, int limit);
void registerForm();
void loginForm();
bool isEmailUnique(string& email);

int main() {
    vector<string> authMenu {"Register", "Login"};
    int choice = 0;
    bool running = true;

    while (running) {
        printMenu(authMenu, choice);
        
        int action = makeAction(choice, authMenu.size());

        switch (action) {
            case 1 : // Enter pressed
                if (choice == 0) {
                    registerForm();
                } else if (choice == 1) {
                    loginForm();
                }
                system("pause");
                break;
            case -1 : // ESC pressed
                cout << endl;
                running = false;
                break;
            default : // just navigation
                cout << "\nUse Up/Down arrows to navigate, Enter to select, Esc to exit.\n" << endl;
                break;
        }
    }

    cout << "Bye!" << endl;
    return 0;
}

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

// validating the email uniqueness
bool isEmailUnique(string& email) {
    for(const auto& customer : Customers) {
        if(customer.getEmail() == email) {
            return false;
        }
	}
	return true;
}

// Registeration form
void registerForm() {
    system("cls");
    string email, name, password;
    int age;
    cout << "\033[1;34m"; // Blue header
    cout << "+----------------------+----------------------+\n";
    cout << "| Field                | Input                |\n";
    cout << "+----------------------+----------------------+\n";
    cout << "\033[0m"; // Reset color


    // Email
    cout << "| Email                | ";
    cin.ignore();
    cin >> email;
    cout << "+----------------------+----------------------|\n";

    if (!isEmailUnique(email)) {
        cout << "\n\033[1;31mError: Email already exists!\033[0m\n";
        system("pause");
        return; // Stop registration
    }

    // Password
    cout << "| Password             | ";
    cin.ignore();
    cin >> password;
    cout << "+----------------------+----------------------|\n";

    // Name
    cout << "| Name                 | ";
    cin.ignore();
    cin >> name;
    cout << "+----------------------+----------------------|\n";

    // Age
    cout << "| Age                  | ";
    cin.ignore();
    cin >> age;
    cout << "+----------------------+----------------------|\n";

    cout << "\033[1;32mRegistration Complete!\033[0m\n"; // Green success message
    // string email, string name, string password, int age
    Customer customer(email, name, password, age);
    Customers.push_back(customer);
}

// Login form
void loginForm() {

    system("cls");
    string email, password;

    cout << "\033[1;34m"; // Blue header
    cout << "+----------------------+----------------------+\n";
    cout << "| Field                | Input                |\n";
    cout << "+----------------------+----------------------+\n";
    cout << "\033[0m"; // Reset color

    // Email
    cout << "| Email                | ";
    cin.ignore();
    cin >> email;
    cout << "+----------------------+----------------------|\n";

    // Password
    cout << "| Password             | ";
    cin.ignore();
    cin >> password;
    cout << "+----------------------+----------------------|\n";

    // Validate login
    bool found = false;
    for (auto& customer : Customers) {
        if (customer.getEmail() == email && customer.getPassword() == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\033[1;32mLogin Successful!\033[0m\n"; // Green success
    }
    else {
        cout << "\033[1;31mInvalid email or password!\033[0m\n"; // Red error
    }

}
