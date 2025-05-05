#ifndef GRADES
#define GRADES

#include <string>
#include <map>
#include <utility>

struct Course {
    std::string name;
    int marks;
    int credit;
    std::string grade;
};

std::map<std::string, std::pair<int, int>> loadGradeScale();
std::map<std::string, float> loadGradePoints();
std::string calculateGrade(int marks);

#endif