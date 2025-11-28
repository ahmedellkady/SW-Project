#ifndef ROUTES_H
#define ROUTES_H

#include <vector>
#include <string>


void printMenu(const std::vector<std::string>& menu, int choice);
int makeAction(int &choice, int limit);
void Route(int meuneNum=1,std::vector<std::string> menu={"Register", "Login"});
#endif
