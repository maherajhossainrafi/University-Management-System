#include "cstudent.h"
#include "filemanager.h"
#include "cgpa.h"
#include "win.h"
#include <iomanip>
#include <iostream>
#include <fstream>

Student::Student(const std::string& u, const std::string& p)
    : User(u, p), courses(loadCourses(u)) {}

void Student::showDashboard() {
    int choice;
    do {
        printHeader("STUDENT DASHBOARD");
        std::cout << "1. View Report Card\n"
                  << "2. Export Transcript\n"
                  << "3. Logout\n"
                  << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            printHeader("GRADE REPORT");
            std::cout << std::left << std::setw(25) << "COURSE"
                      << std::setw(10) << "MARKS"
                      << std::setw(10) << "CREDITS"
                      << "GRADE\n";
            std::cout << "-------------------------------------------------\n";
            for (const auto& course : courses) {
                std::cout << std::setw(25) << course.name
                          << std::setw(10) << course.marks
                          << std::setw(10) << course.credit
                          << course.grade << "\n";
            }
            std::cout << "\nCGPA: " << std::fixed << std::setprecision(2)
                      << calculateCGPA(courses) << "\n";
            std::cin.ignore();
            std::cin.get();
        } else if (choice == 2) {
            std::ofstream file(username + "_transcript.csv");
            file << "Course,Marks,Credit,Grade\n";
            for (const auto& course : courses) {
                file << course.name << "," << course.marks << ","
                     << course.credit << "," << course.grade << "\n";
            }
            std::cout << "Transcript exported successfully!\n";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != 3);
}
