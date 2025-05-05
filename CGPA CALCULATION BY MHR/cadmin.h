#ifndef ADMIN
#define ADMIN

#include "cgpausers.h"

class Admin : public User {
public:
    Admin(const std::string& u, const std::string& p);
    void showDashboard() override;

    private:
    void configureGradeScale();
    void editGrades();
    void exportAllData();
};

#endif