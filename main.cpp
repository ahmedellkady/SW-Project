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
    Customers.push_back(Customer("admin", "admin", "admin", 150));

     Route();

    cout << "Bye!" << endl;
    return 0;
}




