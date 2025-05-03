#include "sysm.h"

int main ()
{
    SystemManager sys;
    sys.loadUsersFromFile();
    sys.loadMessagesFromFile();

    while(true)
    {
        if(!sys.isLoggedIn())
    {
            system("cls");
            std::cout<<"University Management System\n--------------------------------------------\n";
            std::cout<<"1. Register\n2. Login\n3. Exit\nChoice: ";
            int choice;
            std::cin>>choice;

        switch (choice)
        {
            case 1:
            {
                sys.registeruser();
                break;
            }
            case 2:
            {
                sys.login();
                break;
            }
            case 3:
            {
                return 0;
            }
        }

    }
        else
        {
            sys.getCurrentUser()->displayDashboard(sys);
        }
    }

}