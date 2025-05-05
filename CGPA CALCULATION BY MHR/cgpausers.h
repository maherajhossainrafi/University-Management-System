#ifndef CGPA_USER
#define CGPA_USER

#include <string>

class User {
protected:
    std::string username;
    std::string password;

    void printHeader(const std::string& title);
public:
    User(const std::string& u, const std::string& p);
    virtual void showDashboard() = 0;
    virtual ~User() = default;
    std::string getUsername();
};

#endif