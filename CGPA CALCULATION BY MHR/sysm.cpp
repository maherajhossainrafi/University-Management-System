#include "sysm.h"
#include "cstudent.h"
#include "cfaculty.h"
#include "cadmin.h"
#include "filemanager.h"
#include "win.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

User* login() {
    clearScreen();
    std::string role, username, password;
    std::cout << "LOGIN\n";
    std::cout << "Role (student/faculty/admin): ";
    std::cin >> role;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ifstream file("users.csv");
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string storedUser, storedPass, storedRole;
            std::getline(ss, storedUser, ',');
            std::getline(ss, storedPass, ',');
            std::getline(ss, storedRole);
            if (storedUser == username && storedPass == password && storedRole == role) {
                if (role == "student")
                    return new Student(username, password);
                else if (role == "faculty")
                    return new Faculty(username, password);
                else if (role == "admin")
                    return new Admin(username, password);
            }
        }
    }
    return nullptr;
}

void registerUser() {
    clearScreen();
    std::cout << "=================================\n";
    std::cout << "      USER REGISTRATION\n";
    std::cout << "=================================\n";

    std::string role, username, password;
    std::cout << "Choose role (student/faculty/admin): ";
    std::cin >> role;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (userExists(username)) {
        std::cout << "\nUsername already exists!\n";
    } else {
        saveUser(username, password, role);
        if (role == "student") {
            std::ofstream gradeFile(username + ".csv");
            gradeFile.close();
        }
        std::cout << "\nRegistration successful!\n";
    }

    std::cout << "Press enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void mainMenu() {
    User* currentUser = nullptr;
    while (true) {
        clearScreen();
        std::cout << "=================================\n";
        std::cout << "  CGPA MANAGEMENT SYSTEM\n";
        std::cout << "=================================\n";
        std::cout << "1. Login\n2. Register\n3. Exit\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            currentUser = login();
            if (currentUser) {
                currentUser->showDashboard();
                delete currentUser;
            } else {
                std::cout << "Invalid login! Press enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        } else if (choice == 2) {
            registerUser();
        } else if (choice == 3) {
            break;
        }
    }
}