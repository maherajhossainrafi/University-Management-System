#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib> 
#include <iomanip>
#include <algorithm> 
#include <limits>   

using namespace std;

class SystemManager;
class User;         
class IUBATChatbot {
private:
    void displayMainMenu() {
        cout << "\nHow can I help you today? Choose an option:\n";
        cout << "1. About IUBAT\n";
        cout << "2. Academic Programs\n";
        cout << "3. Admission Information\n";
        cout << "4. Scholarships & Fees\n";
        cout << "5. Campus Facilities\n";
        cout << "6. Contact Information\n";
        cout << "7. Exit Chat\n";
        cout << "Enter your choice (1-7): ";
    }

    void displayAboutMenu() {
        cout << "\nWhat would you like to know about IUBAT?\n";
        cout << "1. History & Recognition\n";
        cout << "2. Campus Location\n";
        cout << "3. Student Health Insurance\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice (1-4): ";
    }

    void displayProgramMenu() {
        cout << "\nWhich programs are you interested in?\n";
        cout << "1. Undergraduate Programs\n";
        cout << "2. Graduate Programs\n";
        cout << "3. Diploma Programs\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice (1-4): ";
    }

    void displayAdmissionMenu() {
        cout << "\nAdmission Information:\n";
        cout << "1. Requirements\n";
        cout << "2. Application Process\n";
        cout << "3. Required Documents\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice (1-4): ";
    }

public:
    void startChat() {
        system("cls");
        cout << "Welcome to IUBAT Chatbot!\n";
        cout << "I'm here to help you with information about International University of Business Agriculture and Technology.\n";
        cout << "\nPress Enter to continue to the main menu...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("cls");

        string input;
        int choice;
        while (true) {
            displayMainMenu();
            cin >> input;
            system("cls");

            try {
                choice = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter a number between 1-7.\n";
                cout << "\nPress Enter to try again...";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                system("cls");
                continue;
            }

            switch (choice) {
                case 1:
                    handleAbout();
                    break;
                case 2:
                    handlePrograms();
                    break;
                case 3:
                    handleAdmissions();
                    break;
                case 4:
                    handleScholarships();
                    cout << "\nPress Enter to return to the Main Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 5:
                    handleFacilities();
                    cout << "\nPress Enter to return to the Main Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 6:
                    handleContacts();
                    cout << "\nPress Enter to return to the Main Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 7:
                    cout << "\nThank you for chatting with me!\n";
                    cout << "Good luck with your academic journey!\n";
                    cout << "\nPress Enter to exit chatbot...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    return;
                default:
                    cout << "Hmm, that doesn't look right. Please choose between 1-7.\n";
                    cout << "\nPress Enter to try again...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
            }
        }
    }

private:
    void handleAbout() {
        string input;
        int choice;
        while (true) {
            displayAboutMenu();
            cin >> input;
            system("cls");

            try {
                choice = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter 1-4.\n";
                cout << "\nPress Enter to try again...";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                system("cls");
                continue;
            }

            switch (choice) {
                case 1:
                    cout << "\nEstablished in 1991, IUBAT is the first non-government university in Bangladesh!\n";
                    cout << "- Approved by Govt. of Bangladesh & UGC\n";
                    cout << "- ACU member (Commonwealth recognition)\n";
                    cout << "More info: https://iubat.edu/brief-history/\n";
                    cout << "\nPress Enter to return to the About IUBAT Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 2:
                    cout << "\nPermanent Campus at:\n4 Embankment Drive Road, Uttara Model Town, Dhaka\n";
                    cout << "Phone: 88 02 55091801-5\nEmail: admissions@iubat.edu\n";
                    cout << "Campus tour: https://iubat.edu/campus-life/\n";
                    cout << "\nPress Enter to return to the About IUBAT Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 3:
                    cout << "\nStudent Health Insurance:\n";
                    cout << "- First university in Bangladesh to offer health insurance\n";
                    cout << "- Covers up to Tk. 100,000/year\n";
                    cout << "Details: https://iubat.edu/student/group-health-insurance-sghi/\n";
                    cout << "\nPress Enter to return to the About IUBAT Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 4:
                    return;
                default:
                    cout << "Please choose between 1-4\n";
                    cout << "\nPress Enter to try again...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
            }
        }
    }

    void handlePrograms() {
        string input;
        int choice;
        while (true) {
            displayProgramMenu();
            cin >> input;
            system("cls");

            try {
                choice = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter 1-4.\n";
                cout << "\nPress Enter to try again...";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                system("cls");
                continue;
            }

            switch (choice) {
                case 1:
                    cout << "\nUndergraduate Programs (Credit Hours):\n";
                    cout << "- BBA (133)\n- BCSE (143)\n- BSCE (157)\n- BSME (153.5)\n";
                    cout << "... and 7 more! Full list: https://iubat.edu/programs/\n";
                    cout << "\nPress Enter to return to the Programs Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 2:
                    cout << "\nGraduate Programs:\n";
                    cout << "- MBA (36-60 credits)\n- MSc in CSE/CE\n- MPH\n";
                    cout << "Evening classes available for MBA!\n";
                    cout << "\nPress Enter to return to the Programs Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 3:
                    cout << "\nDiploma Programs:\n";
                    cout << "- DCSE (1.5 years, 61 credits)\n";
                    cout << "- DIA (1.5 years, 64 credits)\n";
                    cout << "\nPress Enter to return to the Programs Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 4: return;
                default:
                    cout << "Please choose between 1-4\n";
                    cout << "\nPress Enter to try again...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
            }
        }
    }

    void handleAdmissions() {
        string input;
        int choice;
        while (true) {
            displayAdmissionMenu();
            cin >> input;
            system("cls");

            try {
                choice = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter 1-4.\n";
                cout << "\nPress Enter to try again...";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                system("cls");
                continue;
            }

            switch (choice) {
                case 1:
                    cout << "\nAdmission Requirements:\n";
                    cout << "- Minimum GPA 2.5 in SSC/HSC (Total 6.0)\n";
                    cout << "- Science background for engineering programs\n";
                    cout << "Full details: www.iubat.edu/admission\n";
                    cout << "\nPress Enter to return to the Admission Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 2:
                    cout << "\nApplication Process:\n";
                    cout << "1. Get form (Tk.500) from campus or online\n";
                    cout << "2. Submit with required documents\n";
                    cout << "3. Pay via bKash/Rocket\n";
                    cout << "Apply online: www.iubat.edu/admission\n";
                    cout << "\nPress Enter to return to the Admission Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 3:
                    cout << "\nRequired Documents:\n";
                    cout << "- Academic certificates\n- 5 passport photos\n- NID/birth certificate\n";
                    cout << "Full list available in admission brochure\n";
                    cout << "\nPress Enter to return to the Admission Menu...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
                    break;
                case 4: return;
                default:
                    cout << "Please choose between 1-4\n";
                    cout << "\nPress Enter to try again...";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("cls");
            }
        }
    }

    void handleScholarships() {
        cout << "\nScholarship Opportunities:\n";
        cout << "- 15% extra for female students\n- Merit-based awards\n";
        cout << "- Financial aid for needy students\n";
        cout << "Details: https://iubat.edu/scholarships/\n";
        cout << "Fee structure: https://iubat.edu/student/tuition-and-fees/\n";
    }

    void handleFacilities() {
        cout << "\nCampus Facilities:\n";
        cout << "- Modern laboratories\n- Library with 30,000+ books\n";
        cout << "- Sports facilities & clubs\n- Free WiFi & transport\n";
        cout << "Lab details: http://cse.iubat.edu/laboratories/\n";
    }

    void handleContacts() {
        cout << "\nImportant Contacts:\n";
        cout << "Admissions: 01810030041-9\n";
        cout << "Email: admissions@iubat.edu\n";
        cout << "Facebook: https://www.facebook.com/iubat\n";
        cout << "Office: Ground Floor, Room 101\n";
    }
};


map<string, pair<int, int>> loadGradeScale();
map<string, float> loadGradePoints();
string calculateGrade(int marks);

class Message {
private:
    string sender;
    string receiver;
    string content;
    time_t timestamp;
public:
    Message(string s, string r, string c) : sender(s), receiver(r), content(c) {
        timestamp = time(nullptr);
    }
    Message(string s, string r, string c, time_t t) :
        sender(s), receiver(r), content(c), timestamp(t) {}

    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getContent() const { return content; }
    time_t getTimestamp() const { return timestamp; }
};

struct Course {
    string name;
    int marks;
    int credit;
    string grade;
};

class User {
protected:
    string username;
    string password;
    string role;
    static int userCount;

    void printHeader(const string& title) {
        system("cls");
        cout << "=================================\n";
        cout << "  " << title << "\n";
        cout << "=================================\n";
    }

public:
    User(string uname, string pwd, string r) : username(uname), password(pwd), role(r) {
        userCount++;
    }
    virtual ~User() { userCount--; }
    virtual void displayDashboard(SystemManager& sys) = 0;

    string getUsername() const { return username; }
    string getRole() const { return role; }
    static int getUserCount() { return userCount; }


    virtual float calculateCGPA() { return 0.0f; }
    virtual void viewReport() {}
    virtual void enterGrades(SystemManager& sys) {}
    virtual void configureGradeScale(SystemManager& sys) {}
    virtual void editGrades(SystemManager& sys) {}

    friend class SystemManager; 
};
int User::userCount = 0;

class Student : public User {
    vector<Course> courses;
    void loadCourses(SystemManager& sys);

public:
    Student(string uname, string pwd) : User(uname, pwd, "student") {}
    void displayDashboard(SystemManager& sys) override;
    float calculateCGPA() override;
    void viewReport() override;
};

class Faculty : public User {
public:
    Faculty(string uname, string pwd) : User(uname, pwd, "faculty") {}
    void displayDashboard(SystemManager& sys) override;
    void enterGrades(SystemManager& sys) override;
};

class Admin : public User {
public:
    Admin(string uname, string pwd) : User(uname, pwd, "admin") {}
    void displayDashboard(SystemManager& sys) override;
    void configureGradeScale(SystemManager& sys) override;
    void editGrades(SystemManager& sys) override;
};

class SystemManager {
private:
    vector<User*> users;
    vector<Message> messages;
    User* currentUser = nullptr;

public:
    ~SystemManager() {
        for (auto user : users) delete user;
    }

    void pauseScreen() {
        cout << "\nPress Enter to continue...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    bool userExists(const string& username) {
        for (auto user : users) {
            if (user->getUsername() == username) return true;
        }
        return false;
    }


    User* getUserByUsername(const string& username) {
        for (auto user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr;
    }


    void registerUser() {
        string username, password, role;
        cout << "Enter username: ";
        cin >> username;
        if (userExists(username)) {
            cout << "Username exists!\n";
            pauseScreen();
            return;
        }
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter role (student/faculty/admin): ";
        cin >> role;

        User* newUser = nullptr;
        if (role == "student") {
            newUser = new Student(username, password);
            ofstream gradeFile(username + ".csv");
            gradeFile.close();
        }
        else if (role == "faculty") newUser = new Faculty(username, password);
        else if (role == "admin") newUser = new Admin(username, password);
        else {
            cout << "Invalid role!\n";
            pauseScreen();
            return;
        }

        users.push_back(newUser);
        saveUsersToFile();
        cout << "Registration successful!\n";
        pauseScreen();
    }

    bool login() {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (auto user : users) {
            if (user->getUsername() == username && user->password == password) { 
                currentUser = user;
                cout << "Login successful!\n";
                pauseScreen();
                return true;
            }
        }
        cout << "Invalid credentials!\n";
        pauseScreen();
        return false;
    }

    void logout() {
        currentUser = nullptr;
        system("cls");
    }

    void sendMessage(string receiver, string content) {
        if (!currentUser) return;
        if (!userExists(receiver)) {
            cout << "Receiver not found!\n";
            pauseScreen();
            return;
        }
        messages.emplace_back(currentUser->getUsername(), receiver, content);
        saveMessagesToFile();
        cout << "Message sent!\n";
        pauseScreen();
    }

    void viewInbox() {
        if (!currentUser) return;
        string username = currentUser->getUsername();
        bool found = false;

        cout << "\n--- Your Messages ---\n";
        for (auto& msg : messages) {
            if (msg.getReceiver() == username) {
                time_t timestamp = msg.getTimestamp();
                cout << "From: " << msg.getSender() << "\nContent: "
                     << msg.getContent() << "\nTime: " << ctime(&timestamp)
                     << "-------------------------\n";
                found = true;
            }
        }

        if (!found) cout << "No messages found!\n";
        pauseScreen();
    }

    void saveUsersToFile() {
        ofstream file("users.csv");
        if (!file) { return; }
        for (auto user : users) {
            file << user->getUsername() << "," << user->password << "," << user->getRole() << "\n"; 
        }
    }

    void loadUsersFromFile() {
        ifstream file("users.csv");
        if (!file) { return; }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username, password, role;
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, role, ',');

            if (username.empty() || password.empty() || role.empty()) continue;

            User* user = nullptr;
            if (role == "student") user = new Student(username, password);
            else if (role == "faculty") user = new Faculty(username, password);
            else if (role == "admin") user = new Admin(username, password);

            if (user && !userExists(username)) {
                 users.push_back(user);
            } else if (user) {
                delete user;
            }
        }
    }

    void saveMessagesToFile() {
        ofstream file("messages.txt");
        if (!file) { return; }
        for (auto& msg : messages) {
            file << msg.getSender() << "|" << msg.getReceiver() << "|"
                 << msg.getContent() << "|" << msg.getTimestamp() << "\n";
        }
    }

    void loadMessagesFromFile() {
        ifstream file("messages.txt");
        if (!file) { return; }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string sender, receiver, content, timeStr;
            getline(ss, sender, '|');
            getline(ss, receiver, '|');
            getline(ss, content, '|');
            getline(ss, timeStr);

            if (sender.empty() || receiver.empty() || timeStr.empty()) continue;

            try {
                time_t timestamp = stol(timeStr);
                messages.emplace_back(sender, receiver, content, timestamp);
            } catch (const std::invalid_argument&) {
            } catch (const std::out_of_range&) {
            }
        }
    }

    bool isLoggedIn() { return currentUser != nullptr; }
    User* getCurrentUser() { return currentUser; }

    vector<Course> loadStudentCourses(const string& username) {
        vector<Course> courses_vec;
        ifstream in(username + ".csv");
        if (in) {
            string line;
            while (getline(in, line)) {
                Course c;
                stringstream ss(line);
                getline(ss, c.name, ',');
                ss >> c.marks; ss.ignore();
                ss >> c.credit; ss.ignore();
                getline(ss, c.grade);

                if (c.name.empty() || c.grade.empty() || c.credit <=0) continue;

                courses_vec.push_back(c);
            }
        }
        return courses_vec;
    }

    void saveStudentCourses(const string& username, const vector<Course>& courses_vec) {
        ofstream out(username + ".csv");
        if (!out) { return; }
        for (const auto& c : courses_vec) {
            out << c.name << "," << c.marks << ","
                << c.credit << "," << c.grade << "\n";
        }
    }
};

void Student::loadCourses(SystemManager& sys) {
    courses = sys.loadStudentCourses(username);
}

void Student::displayDashboard(SystemManager& sys) {
    loadCourses(sys);
    int choice;
    do {
        printHeader("STUDENT DASHBOARD");
        cout << "Welcome, " << username << "!\n\n";
        cout << "1. View Inbox\n2. Send Message\n3. View Report Card\n"
             << "4. Logout\nChoice: ";

        cin >> choice;

        switch (choice) {
            case 1: sys.viewInbox(); break;
            case 2: {
                system("cls");
                string receiver, content;
                cout << "--- Send New Message ---\n";
                cout << "Receiver Username: ";
                cin >> receiver;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Message Content: ";
                getline(cin, content);
                sys.sendMessage(receiver, content);
                break;
            }
            case 3:
                viewReport();
                break;
            case 4: sys.logout(); break;
            default:
                cout << "Invalid choice. Please try again.\n";
                sys.pauseScreen();
        }
    } while (sys.isLoggedIn());
}

float Student::calculateCGPA() {
    if (courses.empty()) return 0.0f;
    float totalPoints = 0;
    int totalCredits = 0;
    map<string, float> gradeValues = loadGradePoints();

    for (const auto& course : courses) {
        if (gradeValues.count(course.grade)) {
            totalPoints += gradeValues[course.grade] * course.credit;
            totalCredits += course.credit;
        }
    }
    return totalCredits > 0 ? totalPoints / totalCredits : 0.0f;
}

void Student::viewReport() {
    printHeader("GRADE REPORT - " + username);
    if (courses.empty()) {
        cout << "No courses found to display.\n";
    } else {
        cout << left << setw(25) << "COURSE" << setw(10) << "MARKS"
             << setw(10) << "CREDITS" << "GRADE\n";
        cout << "-------------------------------------------------\n";

        for (const auto& course : courses) {
            cout << setw(25) << course.name << setw(10) << course.marks
                 << setw(10) << course.credit << course.grade << endl;
        }
        cout << "\nCGPA: " << fixed << setprecision(2) << calculateCGPA() << endl;
    }
    cout << "\nPress enter to return to dashboard...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Faculty::displayDashboard(SystemManager& sys) {
    int choice;
    do {
        printHeader("FACULTY DASHBOARD");
        cout << "Welcome, Prof. " << username << "!\n\n";
        cout << "1. View Inbox\n2. Send Message\n3. Enter Grades for a Student\n"
             << "4. Logout\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: sys.viewInbox(); break;
            case 2: {
                system("cls");
                string receiver, content;
                cout << "--- Send New Message ---\n";
                cout << "Receiver Username: ";
                cin >> receiver;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Message Content: ";
                getline(cin, content);
                sys.sendMessage(receiver, content);
                break;
            }
            case 3: enterGrades(sys); break;
            case 4: sys.logout(); break;
            default:
                cout << "Invalid choice. Please try again.\n";
                sys.pauseScreen();
        }
    } while (sys.isLoggedIn());
}

void Faculty::enterGrades(SystemManager& sys) {
    printHeader("ENTER GRADES");
    string studentName;
    Course c;

    cout << "Enter student's username: ";
    cin >> studentName;

    User* tempUser = sys.getUserByUsername(studentName); 

    if (!tempUser || tempUser->getRole() != "student") {
        cout << "Student not found or user is not a student!\n";
        sys.pauseScreen();
        return;
    }

    cout << "Enter Course name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c.name);

    cout << "Enter Marks (0-100): ";
    while(!(cin >> c.marks) || c.marks < 0 || c.marks > 100) {
        cout << "Invalid marks. Please enter a value between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Credit hours: ";
    while(!(cin >> c.credit) || c.credit <= 0 || c.credit > 6) {
        cout << "Invalid credit hours. Please enter a positive value (e.g., 1-6): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    c.grade = calculateGrade(c.marks);

    vector<Course> studentCourses = sys.loadStudentCourses(studentName);
    studentCourses.push_back(c);
    sys.saveStudentCourses(studentName, studentCourses);

    cout << "\nGrade for " << c.name << " (" << c.grade << ") added successfully for " << studentName << "!\n";
    sys.pauseScreen();
}

void Admin::displayDashboard(SystemManager& sys) {
    int choice;
    do {
        printHeader("ADMIN DASHBOARD");
        cout << "Welcome, Admin " << username << "!\n\n";
        cout << "1. View Inbox\n2. Send Message\n3. Configure Grade Scale\n"
             << "4. Edit Student Grades\n5. Logout\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: sys.viewInbox(); break;
            case 2: {
                system("cls");
                string receiver, content;
                cout << "--- Send New Message ---\n";
                cout << "Receiver Username: ";
                cin >> receiver;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Message Content: ";
                getline(cin, content);
                sys.sendMessage(receiver, content);
                break;
            }
            case 3: configureGradeScale(sys); break;
            case 4: editGrades(sys); break;
            case 5: sys.logout(); break;
            default:
                cout << "Invalid choice. Please try again.\n";
                sys.pauseScreen();
        }
    } while (sys.isLoggedIn());
}

void Admin::configureGradeScale(SystemManager& sys) {
    printHeader("CONFIGURE GRADE SCALE");
    ofstream file("grade_scale.csv");
    if (file) {
        cout << "Enter grade scale entries. Format: Grade,MinMarks,MaxMarks (e.g., A+,80,100)\n";
        cout << "Type 'done' on a new line when finished.\n\n";
        string line;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true) {
            cout << "Enter (Grade,Min,Max) or 'done': ";
            getline(cin, line);
            if (line == "done") break;

            if (count(line.begin(), line.end(), ',') != 2) {
                cout << "Invalid format. Use Grade,Min,Max. Example: B,60,69. Try again.\n";
                continue;
            }
            file << line << "\n";
            cout << "Entry '" << line << "' added.\n";
        }
        cout << "\nGrade scale configuration updated!\n";
    }
    else {
        cout << "\nError: Could not open grade_scale.csv for writing!\n";
    }
    sys.pauseScreen();
}

void Admin::editGrades(SystemManager& sys) {
    printHeader("EDIT STUDENT GRADES");
    string studentName;
    cout << "Enter student's username to edit grades: ";
    cin >> studentName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    User* tempUser = sys.getUserByUsername(studentName); 
    if (!tempUser || tempUser->getRole() != "student") {
        cout << "Student not found or user is not a student!\n";
        sys.pauseScreen();
        return;
    }

    vector<Course> courses = sys.loadStudentCourses(studentName);
    if (courses.empty()) {
        cout << "No courses found for student: " << studentName << ".\n";
        sys.pauseScreen();
        return;
    }

    cout << "\nCourses for " << studentName << ":\n";
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << i + 1 << ". " << courses[i].name << " (Marks: " << courses[i].marks
             << ", Credits: " << courses[i].credit << ", Grade: " << courses[i].grade << ")\n";
    }

    int courseChoice;
    cout << "\nEnter course number to edit (0 to cancel): ";
    while(!(cin >> courseChoice) || courseChoice < 0 || courseChoice > static_cast<int>(courses.size())) {
        cout << "Invalid selection. Enter a number between 0 and " << courses.size() << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (courseChoice == 0) {
        cout << "Edit cancelled.\n";
        sys.pauseScreen();
        return;
    }

    Course& C_to_edit = courses[courseChoice - 1];

    cout << "Editing: " << C_to_edit.name << endl;
    cout << "Current Marks: " << C_to_edit.marks << ". Enter new marks (0-100): ";
    while(!(cin >> C_to_edit.marks) || C_to_edit.marks < 0 || C_to_edit.marks > 100) {
        cout << "Invalid marks. Please enter a value between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    C_to_edit.grade = calculateGrade(C_to_edit.marks);

    sys.saveStudentCourses(studentName, courses);
    cout << "\nGrade for " << C_to_edit.name << " updated to " << C_to_edit.grade
         << " (Marks: " << C_to_edit.marks << ").\n";
    sys.pauseScreen();
}

string calculateGrade(int marks) {
    map<string, pair<int, int>> scale = loadGradeScale();
    for (const auto& entry : scale) {
        if (marks >= entry.second.first && marks <= entry.second.second) {
            return entry.first;
        }
    }
    return "F";
}

map<string, pair<int, int>> loadGradeScale() {
    map<string, pair<int, int>> scale;
    ifstream file("grade_scale.csv");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string grade;
            int min_marks, max_marks;
            char comma;

            if (getline(ss, grade, ',') && (ss >> min_marks >> comma >> max_marks) && comma == ',') {
                 if (!grade.empty() && min_marks <= max_marks && min_marks >=0 && max_marks <=100) {
                    scale[grade] = {min_marks, max_marks};
                }
            }
        }
    }

    if (scale.empty()) {
        scale = {
            {"A+", {80, 100}}, {"A",  {75, 79}}, {"A-", {70, 74}},
            {"B+", {65, 69}}, {"B",  {60, 64}}, {"B-", {55, 59}},
            {"C+", {50, 54}}, {"C",  {45, 49}}, {"D",  {40, 44}},
            {"F",  {0, 39}}
        };
    }
    return scale;
}

map<string, float> loadGradePoints() {
    return {
        {"A+", 4.0f}, {"A", 3.75f}, {"A-", 3.5f},
        {"B+", 3.25f}, {"B", 3.0f}, {"B-", 2.75f},
        {"C+", 2.5f}, {"C", 2.25f}, {"D", 2.0f}, {"F", 0.0f}
    };
}

int main() {
    SystemManager sys;
    sys.loadUsersFromFile();
    sys.loadMessagesFromFile();

    IUBATChatbot bot;

    while (true) {
        if (!sys.isLoggedIn()) {
            system("cls");
            cout << "===== University Management System =====\n";
            cout << "----------------------------------------\n";
            cout << "1. Login\n";
            cout << "2. Register\n";
            cout << "3. Chatbot\n";
            cout << "4. Exit System\n";
            cout << "----------------------------------------\n";
            cout << "Enter your choice: ";

            int choice;
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                sys.pauseScreen();
                continue;
            }

            switch (choice) {
                case 1: sys.login(); break;
                case 2:
                    system("cls");
                    sys.registerUser();
                    break;
                case 3:
                    bot.startChat();
                    break;
                case 4:
                    cout << "\nExiting University Management System. Goodbye!\n";
                    return 0;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    sys.pauseScreen();
            }
        } else {
            sys.getCurrentUser()->displayDashboard(sys);
        }
    }
    return 0;
}