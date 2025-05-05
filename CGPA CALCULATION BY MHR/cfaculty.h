#ifndef FACULTY
#define FACULTY

#include "cgpausers.h"
#include "grades.h"
#include <vector>

class Faculty : public User {
public:
    Faculty(const std::string& u, const std::string& p);
    void showDashboard() override;

private:
    void enterGrades();
    void bulkUpload();
};

#endif