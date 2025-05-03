#ifndef USER
#define USER

#include<string>
#include<vector>

class SystemManager;

class User
{
    private:
    std::string username;
    std::string password;
    std::string role;
    static int userCount;

    protected:
    User( std::string uname, std::string pwd, std::string r)
    : username(uname), password(pwd), role(r)
    {
        userCount++;
    }

    public:
    virtual ~User()
    {
        userCount--;
    }

    virtual void displayDashboard(SystemManager &sys)=0;
    
    std::string getUsername() const
    {
        return username;
    }
    
    std::string getRole() const
    {
        return role;
    }
    
    static int getUserCount()
    {
        return userCount;
    }

    friend class SystemManager;

};

int User::userCount=0;

class Student:public User
{
    public:
    Student(std::string uname, std::string pwd)
    : User(uname, pwd, "student"){}
    virtual void displayDashboard(SystemManager &sys) override;
};

class Faculty:public User
{
    public:
    Faculty(std::string uname, std::string pwd)
    : User(uname, pwd, "faculty"){}
    virtual void displayDashboard(SystemManager &sys) override;
};


class Admin:public User
{
    public:
    Admin(std::string uname, std::string pwd)
    : User(uname, pwd, "admin"){}
    virtual void displayDashboard(SystemManager &sys) override;
};



#endif
