#ifndef SYSTEM_MANAGER
#define SYSTEM_MANAGER

#include "msg.h"
#include "user.h"
#include<vector>
#include<fstream>
#include<sstream>



class SystemManager
{
    private:
    std::vector<User*>users;
    std::vector<Message>messages;

    User* currentUser=nullptr;

    bool userExists(const std::string &username) //issues
    {
        for(auto user:users)
        {
            if(user->username==username) //username issue
            {
                return true;
            }
        }
        return false;
    }

    public:
    ~SystemManager()
    {
        for(auto user:users)
        {
            delete user;
        }
    }

    void pauseScreen()
    {
        std::cout<<"\nPress ENTER to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    void registeruser();

    bool login();

    void logout();

    void sendMessage(std::string receiver, std::string content);

    void viewInbox();

    void saveUsersToFile();

    void loadUsersFromFile();

    void saveMessagesToFile();

    void loadMessagesFromFile();

    bool isLoggedIn()
    {
        return currentUser!=nullptr;
    }

    User* getCurrentUser()
    {
        return currentUser;
    }

};

void Student::displayDashboard(SystemManager &sys) //issues
{
    int choice;
    do
    {
        system("cls");
        std::cout<<"\n STUDENT DASHBOARD\n1. View Inbox\n2. Send Message\n3. Logout\nChoice: ";
        std::cin>>choice;

        switch(choice)
        {
            case 1:
            {
                sys.viewInbox();
                break;
            }

            case 2: //issues2
            {
                std::string receiver, content;

                std::cout<<"Receiver: ";
                std::cin>>receiver;

                std::cin.ignore();
                std::cout<<"Message: ";
                std::getline(std::cin,content);

                sys.sendMessage(receiver,content);
                break;
            }

            case 3:
            {
                sys.logout();
                break;
            }
        }

    } while (sys.isLoggedIn());
    
}

void Faculty::displayDashboard(SystemManager &sys) //issues
{
    int choice;
    do
    {
        system("cls");
        std::cout<<"\n FACULTY DASHBOARD\n1. View Inbox\n2. Send Message\n3. Logout\nChoice: ";
        std::cin>>choice;

        switch(choice)
        {
            case 1:
            {
                sys.viewInbox();
                break;
            }

            case 2: //issues2
            {
                std::string receiver, content;

                std::cout<<"Receiver: ";
                std::cin>>receiver;

                std::cin.ignore();
                std::cout<<"Message: ";
                std::getline(std::cin,content);

                sys.sendMessage(receiver,content);
                break;
            }

            case 3:
            {
                sys.logout();
                break;
            }
        }

    } while (sys.isLoggedIn());
    
}

void Admin::displayDashboard(SystemManager &sys) //issues
{
    int choice;
    do
    {
        system("cls");
        std::cout<<"\n ADMIN DASHBOARD\n1. View Inbox\n2. Send Message\n3. Logout\nChoice: ";
        std::cin>>choice;

        switch(choice)
        {
            case 1:
            {
                sys.viewInbox();
                break;
            }

            case 2: //issues2
            {
                std::string receiver, content;

                std::cout<<"Receiver: ";
                std::cin>>receiver;

                std::cin.ignore();
                std::cout<<"Message: ";
                std::getline(std::cin,content);

                sys.sendMessage(receiver,content);
                break;
            }

            case 3:
            {
                sys.logout();
                break;
            }
        }

    } while (sys.isLoggedIn());
    
}

void SystemManager::registeruser()
{
    std::string username, password, role;

    std::cout<<"Enter Username: ";
    std::cin>>username;

    if(userExists(username))
    {
        std::cout<<"\nUsername exists!\n";
        pauseScreen();
        return;
    }

    std::cout<<"Enter Password: ";
    std::cin>>password;

    std::cout<<"Enter Role(student/faculty/admin): ";
    std::cin>>role;

    User* newUser=nullptr;

    if(role=="student")
    {
        newUser= new Student(username,password);
    }

    else if(role=="faculty")
    {
        newUser= new Faculty (username,password);
    }
    else if(role=="admin")
    {
        newUser= new Admin(username,password);
    }

    else
    {
        std::cout<<"Invalid Role!\n";
        pauseScreen();
        return;
    }

    users.push_back(newUser);
    saveUsersToFile(); //issues

    std::cout<<"Registration Successful!\n";
    pauseScreen();

}

bool SystemManager::login()
{
    std::string username, password;
    std::cout<<"Enter Username: ";
    std::cin >>username;
    std::cout<<"Enter Password: ";
    std::cin >>password;


    for(auto user:users)
    {
        if(user->username==username && user->password==password )
        {
            currentUser=user;
            std::cout<<"Login Successful!\n";
            pauseScreen();
            return true;
        }
    }

    std::cout<<"INVALID CREDENTIALS!\n";
    pauseScreen();
    return false;
}

void SystemManager::logout()
{
    currentUser=nullptr;
    system("cls");
}

void SystemManager::sendMessage(std::string receiver,std::string content)
{
    if(!currentUser)
    {
        return;
    }
    if(!userExists(receiver))
    {
        std::cout<<"Receiver not found!\n";
        pauseScreen();
        return;
    }

    messages.emplace_back(currentUser->getUsername(), receiver, content);
    saveMessagesToFile();
    std::cout<<"Message Sent!\n";
    pauseScreen();

}

void SystemManager::viewInbox()
{
    if(!currentUser)
    {
        return;
    }

    std::string username=currentUser->getUsername();
    bool found=false;

    for(auto &msg:messages)
    {
        if(msg.getReceiver()==username)
        {
            time_t timestamp = msg.getTimestamp();

            std::cout<<"From: "<<msg.getSender()<<"\nContent: "
            <<msg.getContent()<<"\nTime: "<<ctime(&timestamp)
            <<"------------------------------------------\n";

            found=true;

        }
    }

    if(!found)
    {
        std::cout<<"No Messages found!\n";
    }
    pauseScreen();

}


    
void SystemManager::saveUsersToFile()
{
    std::ofstream file("users.csv");
    for(auto user:users)
    {
        file<<user->username<<","<<user->password<<","<<user->role<<"\n";
    }

}

void SystemManager::loadUsersFromFile()
{
    std::ifstream file("users.csv");
    std::string line;

    while(getline(file,line))
    {
        std::stringstream ss(line);
        std::string username,password,role;

        getline(ss, username,',');
        getline(ss, password,',');
        getline(ss, role,',');

        User* user = nullptr;

        if(role=="student")
        {
            user= new Student(username,password); 
        }
        else if(role=="faculty")
        {
            user= new Faculty(username,password); 
        }
        else if(role=="admin")
        {
            user= new Admin(username,password); 
        }

        if(user)
        {
            users.push_back(user);
        }

    }

}

void SystemManager::saveMessagesToFile()
{
    std::ofstream file("messages.csv");
    for(auto &msg:messages)
    {
        file<<msg.getSender()<<"|"<<msg.getReceiver()<<"|"
        <<msg.getContent()<<"|"<<msg.getTimestamp()<<"\n";
    }

}

void SystemManager::loadMessagesFromFile()
{
    std::ifstream file("messages.csv");
    std::string line;

    while(getline(file,line))
    {
        std::stringstream ss(line);
        std::string sender, receiver, content, timeStr;

        getline(ss, sender,'|');
        getline(ss, receiver,'|');
        getline(ss, content,'|');
        getline(ss, timeStr);

        time_t timestamp=std::stol(timeStr);

        messages.emplace_back(sender, receiver, content, timestamp);

    }


}

#endif