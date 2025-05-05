#include "filemanager.h"
#include <fstream>
#include <sstream>

std::vector<Course> loadCourses(const std::string& username) {
    std::vector<Course> courses;
    std::ifstream file(username + ".csv");
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            Course c;
            std::stringstream ss(line);
            std::getline(ss, c.name, ',');
            ss >> c.marks; ss.ignore();
            ss >> c.credit; ss.ignore();
            std::getline(ss, c.grade);
            courses.push_back(c);
        }
    }
    return courses;
}

void saveCourses(const std::string& username, const std::vector<Course>& courses) {
    std::ofstream file(username + ".csv");
    for (const auto& course : courses) {
        file << course.name << "," << course.marks << ","
             << course.credit << "," << course.grade << "\n";
    }
}

bool userExists(const std::string& username) {
    std::ifstream check("users.csv");
    std::string line;
    while (std::getline(check, line)) {
        std::stringstream ss(line);
        std::string storedUser;
        std::getline(ss, storedUser, ',');
        if (storedUser == username) return true;
    }
    return false;
}

void saveUser(const std::string& username, const std::string& password, const std::string& role) {
    std::ofstream file("users.csv", std::ios::app);
    file << username << "," << password << "," << role << "\n";
}