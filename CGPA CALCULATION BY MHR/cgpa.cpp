#include "cgpa.h"
#include "grades.h"

float calculateCGPA(const std::vector<Course>& courses) {
    float totalPoints = 0;
    int totalCredits = 0;
    auto gradeValues = loadGradePoints();

    for (const auto& course : courses) {
        totalPoints += gradeValues[course.grade] * course.credit;
        totalCredits += course.credit;
    }
    return totalCredits ? totalPoints / totalCredits : 0;
}
