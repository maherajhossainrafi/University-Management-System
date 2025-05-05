#include "grades.h"
#include <fstream>
#include <sstream>

std::map<std::string, std::pair<int, int>> loadGradeScale() {
    std::map<std::string, std::pair<int, int>> scale;
    std::ifstream file("grade_scale.csv");
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string grade;
            int min, max;
            std::getline(ss, grade, ',');
            ss >> min; ss.ignore();
            ss >> max;
            scale[grade] = {min, max};
        }
    } else {
        scale = {
            {"A+", {80, 100}}, {"A", {75, 79}}, {"A-", {70, 74}},
            {"B+", {65, 69}}, {"B", {60, 64}}, {"B-", {55, 59}},
            {"C+", {50, 54}}, {"C", {45, 49}}, {"D", {40, 44}}, {"F", {0, 39}}
        };
    }
    return scale;
}

std::map<std::string, float> loadGradePoints() {
    return {
        {"A+", 4.0}, {"A", 3.75}, {"A-", 3.5},
        {"B+", 3.25}, {"B", 3.0}, {"B-", 2.75},
        {"C+", 2.5}, {"C", 2.25}, {"D", 2.0}, {"F", 0.0}
    };
}

std::string calculateGrade(int marks) {
    auto scale = loadGradeScale();
    for (const auto& [grade, range] : scale) {
        if (marks >= range.first && marks <= range.second) {
            return grade;
        }
    }
    return "F";
}