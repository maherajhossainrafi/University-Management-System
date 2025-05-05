#include "cgpausers.h"
#include "win.h"
#include <iostream>

User::User(const std::string& u, const std::string& p)
    : username(u), password(p) {}

std::string User::getUsername() { return username; }

void User::printHeader(const std::string& title) {
    clearScreen();
    std::cout << "=================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "=================================" << std::endl;
}