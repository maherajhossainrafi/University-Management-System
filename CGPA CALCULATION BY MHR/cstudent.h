#ifndef STUDENT
#define STUDENT

#include "cgpausers.h"
#include "grades.h"
#include <vector>

class Student : public User {
    std::vector<Course> courses;
public:
    Student(const std::string& u, const std::string& p);
    void showDashboard() override;
};

#endif 