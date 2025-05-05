#ifndef FILE_MANAGER
#define FILE_MANAGER

#include "grades.h"
#include <vector>
#include <string>

std::vector<Course> loadCourses(const std::string& username);
void saveCourses(const std::string& username, const std::vector<Course>& courses);
bool userExists(const std::string& username);
void saveUser(const std::string& username, const std::string& password, const std::string& role);

#endif