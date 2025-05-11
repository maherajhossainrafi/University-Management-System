#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

vector<vector<string>> readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        if(line.empty()) continue;
        vector<string> row;
        size_t pos = 0;
        while ((pos = line.find(',')) != string::npos) {
            row.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        row.push_back(line);
        data.push_back(row);
    }
    return data;
}

void writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) file << ",";
        }
        file << "\n";
    }
}

string getCurrentTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ltm);
    return string(timestamp);
}

class User {
protected:
    string username;
    string role;

public:
    User(const string& uname, const string& r) : username(uname), role(r) {}
    virtual ~User() = default;

    virtual void showDashboard() = 0;

    static User* login();
    static void registerUser();
    void sendMessage() const;
    void viewMessages() const;

    string getUsername() const { return username; }
    string getRole() const { return role; }
};

class Student : public User {
    float calculateCGPA() const {
        auto grades = readCSV("grades.csv");
        float totalPoints = 0;
        int totalCredits = 0;
        map<string, float> gradeScale = {
            {"A+", 4.0}, {"A", 3.75}, {"B+", 3.5}, {"B", 3.0},
            {"C+", 2.5}, {"C", 2.0}, {"D", 1.5}, {"F", 0.0}
        };

        for (const auto& grade : grades) {
            if (grade.size() >= 4 && grade[0] == username) {
                try {
                    int credits = stoi(grade[3]);
                    totalPoints += gradeScale[grade[2]] * credits;
                    totalCredits += credits;
                } catch (...) {}
            }
        }
        return totalCredits > 0 ? totalPoints / totalCredits : 0.0f;
    }

public:
    Student(const string& uname) : User(uname, "student") {}

    void showDashboard() override;
    void viewGrades() const;
    void viewAttendance() const;
};

class Faculty : public User {
public:
    Faculty(const string& uname) : User(uname, "faculty") {}
    void showDashboard() override;
    void updateAttendance();
    void manageStudentAttendance(const string& course, const string& date);
    void viewCurrentAttendance(const string& course, const string& date);
    void manageGrades();
};

class Admin : public User {
public:
    Admin(const string& uname) : User(uname, "admin") {}
    void showDashboard() override;
    void manageUsers();
    void modifyGrades();
    void sendAnnouncement();
};

void Student::showDashboard() {
    int choice;
    do {
        clearScreen();
        cout << "STUDENT DASHBOARD - " << username << "\n\n";
        cout << "1. View Report Card\n"
             << "2. Check Attendance\n"
             << "3. Message Faculty/Admin\n"
             << "4. View Messages\n"
             << "5. Logout\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            continue;
        }

        switch(choice) {
            case 1: viewGrades(); break;
            case 2: viewAttendance(); break;
            case 3: sendMessage(); break;
            case 4: viewMessages(); break;
        }
    } while(choice != 5);
}

void Student::viewGrades() const {
    clearScreen();
    auto grades = readCSV("grades.csv");
    cout << "ACADEMIC REPORT\n";
    cout << "CGPA: " << fixed << setprecision(2) << calculateCGPA() << "\n\n";

    for (const auto& g : grades) {
        if (g.size() >= 4 && g[0] == username) {
            cout << g[1] << ": " << g[2]
                 << " (" << g[3] << " credits)\n";
        }
    }
    pause();
}

void Student::viewAttendance() const {
    clearScreen();
    auto attendance = readCSV("attendance.csv");
    map<string, vector<pair<string, string>>> courseAttendance;

    for (const auto& record : attendance) {
        if(record.size() >= 4 && record[0] == username) {
            string course = record[1];
            string date = record[2];
            string status = record[3] == "1" ? "Present" : "Absent";
            courseAttendance[course].push_back({date, status});
        }
    }

    cout << "ATTENDANCE RECORD\n";
    for(const auto& [course, records] : courseAttendance) {
        cout << "\nCourse: " << course << "\n";
        for(const auto& [date, status] : records) {
            cout << date << ": " << status << "\n";
        }
    }

    if(courseAttendance.empty()) cout << "No attendance records found!\n";
    pause();
}

void Faculty::showDashboard() {
    int choice;
    do {
        clearScreen();
        cout << "FACULTY DASHBOARD - " << username << "\n\n";
        cout << "1. Update Attendance\n"
             << "2. Manage Grades\n"
             << "3. Message Students/Admin\n"
             << "4. View Messages\n"
             << "5. Logout\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            continue;
        }

        switch(choice) {
            case 1: updateAttendance(); break;
            case 2: manageGrades(); break;
            case 3: sendMessage(); break;
            case 4: viewMessages(); break;
        }
    } while(choice != 5);
}

void Faculty::updateAttendance() {
    clearScreen();
    string course, date;
    cout << "Enter Course Name: ";
    cin >> course;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    while(true) {
        clearScreen();
        cout << "ATTENDANCE MANAGEMENT - " << course << " (" << date << ")\n\n";
        cout << "1. Add/Edit Student Attendance\n";
        cout << "2. View Current Attendance\n";  // Fixed this option
        cout << "3. Save and Finish\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if(choice == 1) manageStudentAttendance(course, date);
        else if(choice == 2) viewCurrentAttendance(course, date);  // Fixed this line
        else if(choice == 3) {
            cout << "Attendance saved!\n";
            pause();
            return;
        }
        else {
            cout << "Invalid choice!\n";
            pause();
        }
    }
}


void Faculty::manageStudentAttendance(const string& course, const string& date) {
    auto users = readCSV("users.csv");
    auto attendance = readCSV("attendance.csv");

    string student;
    cout << "Enter Student Username: ";
    cin >> student;

    bool validStudent = false;
    for(const auto& user : users) {
        if(user.size() > 2 && user[0] == student && user[2] == "student") {
            validStudent = true;
            break;
        }
    }

    if(!validStudent) {
        cout << "Invalid student username!\n";
        pause();
        return;
    }

    vector<vector<string>> newAttendance;
    for(const auto& record : attendance) {
        if(!(record.size() > 3 && record[0] == student &&
             record[1] == course && record[2] == date)) {
            newAttendance.push_back(record);
        }
    }

    string status;
    cout << "Mark attendance for " << student << " (1=Present/0=Absent): ";
    cin >> status;
    newAttendance.push_back({student, course, date, status});

    writeCSV("attendance.csv", newAttendance);
    cout << "Attendance updated for " << student << "!\n";
    pause();
}

void Faculty::viewCurrentAttendance(const string& course, const string& date) {
    clearScreen();

    auto users = readCSV("users.csv");
    vector<string> students;
    for(const auto& user : users) {
        if(user.size() >= 3 && user[2] == "student") {
            students.push_back(user[0]);
        }
    }

    auto attendance = readCSV("attendance.csv");
    map<string, string> attendanceMap;

    for(const auto& record : attendance) {
        if(record.size() >= 4 && record[1] == course && record[2] == date) {
            attendanceMap[record[0]] = record[3];
        }
    }

    cout << "ATTENDANCE FOR " << course << " ON " << date << "\n\n";
    cout << "Student ID\t\tStatus\n";
    cout << "----------------------------------------\n";

    for(const auto& student : students) {
        cout << student << "\t\t";
        if(attendanceMap.find(student) != attendanceMap.end()) {
            cout << (attendanceMap[student] == "1" ? "Present" : "Absent");
        } else {
            cout << "Not Recorded";
        }
        cout << "\n";
    }

    pause();
}

void Faculty::manageGrades() {
    clearScreen();
    string student, course, grade, credits;
    cout << "Student Username: ";
    cin >> student;
    cout << "Course: ";
    cin >> course;
    cout << "Grade (A+/A/B+/B/C+/C/D/F): ";
    cin >> grade;
    cout << "Credits: ";
    cin >> credits;

    auto grades = readCSV("grades.csv");
    vector<vector<string>> newGrades;
    bool updated = false;

    for(auto& g : grades) {
        if(g.size() >= 4 && g[0] == student && g[1] == course) {
            g[2] = grade;
            g[3] = credits;
            updated = true;
        }
        newGrades.push_back(g);
    }

    if(!updated) newGrades.push_back({student, course, grade, credits});
    writeCSV("grades.csv", newGrades);
    cout << "Grade updated!\n";
    pause();
}

void Admin::showDashboard() {
    int choice;
    do {
        clearScreen();
        cout << "ADMIN DASHBOARD - " << username << "\n\n";
        cout << "1. Manage Users\n"
             << "2. Modify Student Grades\n"
             << "3. Send Announcement\n"
             << "4. Message Anyone\n"
             << "5. View Messages\n"
             << "6. Logout\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            continue;
        }

        switch(choice) {
            case 1: manageUsers(); break;
            case 2: modifyGrades(); break;
            case 3: sendAnnouncement(); break;
            case 4: sendMessage(); break;
            case 5: viewMessages(); break;
        }
    } while(choice != 6);
}

void Admin::manageUsers() {
    int choice;
    do {
        clearScreen();
        cout << "USER MANAGEMENT\n\n";
        cout << "1. Add User\n"
             << "2. Delete User\n"
             << "3. View All Users\n"
             << "4. Return\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            continue;
        }

        switch(choice) {
            case 1: User::registerUser(); break;
            case 2: {
                auto users = readCSV("users.csv");
                string uname;
                cout << "Username to delete: ";
                cin >> uname;

                vector<vector<string>> newUsers;
                for (const auto& u : users) {
                    if(u.size() >= 1 && u[0] != uname) newUsers.push_back(u);
                }
                writeCSV("users.csv", newUsers);
                cout << "User deleted!\n";
                pause();
                break;
            }
            case 3: {
                auto users = readCSV("users.csv");
                for (const auto& u : users) {
                    if(u.size() >= 3) cout << u[0] << " - " << u[2] << "\n";
                }
                pause();
                break;
            }
        }
    } while(choice != 4);
}

void Admin::modifyGrades() {
    clearScreen();
    string student;
    cout << "Student Username: ";
    cin >> student;

    auto grades = readCSV("grades.csv");
    vector<vector<string>> studentGrades;

    cout << "\nCurrent Grades:\n";
    int index = 1;
    for (const auto& grade : grades) {
        if(grade.size() >= 4 && grade[0] == student) {
            studentGrades.push_back(grade);
            cout << index++ << ". " << grade[1]
                 << " - " << grade[2]
                 << " (" << grade[3] << " credits)\n";
        }
    }

    if(studentGrades.empty()) {
        cout << "No grades found!\n";
        pause();
        return;
    }

    int choice;
    cout << "\nSelect grade to modify (0 to cancel): ";
    cin >> choice;

    if(choice < 1 || choice > studentGrades.size()) {
        cout << "Modification cancelled.\n";
        pause();
        return;
    }

    string newGrade, newCredits;
    cout << "New Grade (A+/A/B+/B/C+/C/D/F): ";
    cin >> newGrade;
    cout << "New Credits: ";
    cin >> newCredits;

    vector<vector<string>> newGrades;
    for(auto& g : grades) {
        if(g == studentGrades[choice-1]) {
            g[2] = newGrade;
            g[3] = newCredits;
        }
        newGrades.push_back(g);
    }

    writeCSV("grades.csv", newGrades);
    cout << "Grade updated successfully!\n";
    pause();
}

void Admin::sendAnnouncement() {
    clearScreen();
    string content;
    cout << "Announcement: ";
    cin.ignore();
    getline(cin, content);

    auto users = readCSV("users.csv");
    ofstream file("messages.csv", ios::app);
    string timestamp = getCurrentTimestamp();

    for(const auto& user : users) {
        if(user.size() >= 1) {
            file << username << "," << user[0] << "," << content << "," << timestamp << "\n";
        }
    }
    cout << "Announcement sent to all users!\n";
    pause();
}

User* User::login() {
    clearScreen();
    string uname, pwd;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pwd;

    auto users = readCSV("users.csv");
    for(const auto& user : users) {
        if(user.size() >= 3 && user[0] == uname && user[1] == pwd) {
            if(user[2] == "student") return new Student(uname);
            if(user[2] == "faculty") return new Faculty(uname);
            if(user[2] == "admin") return new Admin(uname);
        }
    }
    cout << "Invalid credentials!\n";
    pause();
    return nullptr;
}

void User::registerUser() {
    clearScreen();
    string uname, pwd, role;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pwd;
    cout << "Role (student/faculty/admin): ";
    cin >> role;

    transform(role.begin(), role.end(), role.begin(), ::tolower);

    if(role != "student" && role != "faculty" && role != "admin") {
        cout << "Invalid role!\n";
        pause();
        return;
    }

    auto users = readCSV("users.csv");
    for(const auto& user : users) {
        if(user.size() >= 1 && user[0] == uname) {
            cout << "Username already exists!\n";
            pause();
            return;
        }
    }

    ofstream file("users.csv", ios::app);
    file << uname << "," << pwd << "," << role << "\n";
    cout << "Registration successful!\n";
    pause();
}

void User::sendMessage() const {
    clearScreen();
    string receiver, content;
    cout << "Recipient: ";
    cin >> receiver;

    auto users = readCSV("users.csv");
    string receiverRole = "";
    for(const auto& user : users) {
        if(user.size() >= 3 && user[0] == receiver) {
            receiverRole = user[2];
            break;
        }
    }

    bool valid = false;
    if(role == "student") valid = (receiverRole == "faculty" || receiverRole == "admin");
    else if(role == "faculty") valid = (receiverRole == "student" || receiverRole == "admin");
    else if(role == "admin") valid = true;

    if(!valid) {
        cout << "Invalid recipient for your role!\n";
        pause();
        return;
    }

    cout << "Message: ";
    cin.ignore();
    getline(cin, content);

    ofstream file("messages.csv", ios::app);
    file << username << "," << receiver << "," << content << "," << getCurrentTimestamp() << "\n";
    cout << "Message sent!\n";
    pause();
}

void User::viewMessages() const {
    clearScreen();
    auto messages = readCSV("messages.csv");

    cout << "=== INBOX ===\n";
    bool hasMessages = false;
    for(const auto& msg : messages) {
        if(msg.size() >= 4 && msg[1] == username) {
            cout << "From: " << msg[0] << "\n"
                 << "Time: " << msg[3] << "\n"
                 << "Message: " << msg[2] << "\n\n";
            hasMessages = true;
        }
    }
    if(!hasMessages) cout << "No received messages\n";

    cout << "\n=== SENT MESSAGES ===\n";
    hasMessages = false;
    for(const auto& msg : messages) {
        if(msg.size() >= 4 && msg[0] == username) {
            cout << "To: " << msg[1] << "\n"
                 << "Time: " << msg[3] << "\n"
                 << "Message: " << msg[2] << "\n\n";
            hasMessages = true;
        }
    }
    if(!hasMessages) cout << "No sent messages\n";

    pause();
}

class IUBATChatbot {
public:
    void start() {
        clearScreen();
        cout << "Welcome to IUBAT Chatbot!\n";
        cout << "I'm here to help you with information about International University of Business Agriculture and Technology.\n";
        pause();

        int choice;
        while(true) {
            clearScreen();
            cout << "Main Menu:\n"
                 << "1. About IUBAT\n"
                 << "2. Academic Programs\n"
                 << "3. Admission Information\n"
                 << "4. Scholarships & Fees\n"
                 << "5. Campus Facilities\n"
                 << "6. Contact Information\n"
                 << "7. Exit Chatbot\n"
                 << "Choice: ";

            if(!(cin >> choice)) {
                cin.clear();
                cin.ignore();
                continue;
            }

            clearScreen();
            switch(choice) {
                case 1: showAbout(); break;
                case 2: showPrograms(); break;
                case 3: showAdmissions(); break;
                case 4: showScholarships(); break;
                case 5: showFacilities(); break;
                case 6: showContacts(); break;
                case 7:
                    cout << "Thank you for using the chatbot!\n";
                    pause();
                    return;
                default:
                    cout << "Invalid choice!\n";
                    pause();
            }
        }
    }

private:
    void showAbout() {
        clearScreen();
        cout << "About IUBAT:\n"
             << "- Established in 1991\n"
             << "- First private university in Bangladesh\n"
             << "- Offers international standard education\n";
        pause();
    }

    void showPrograms() {
        clearScreen();
        cout << "Academic Programs:\n"
             << "1. Undergraduate Programs\n"
             << "2. Graduate Programs\n"
             << "3. Diploma Programs\n";
        pause();
    }

    void showAdmissions() {
        clearScreen();
        cout << "Admission Requirements:\n"
             << "- Completed application form\n"
             << "- Academic transcripts\n"
             << "- Entrance exam (if applicable)\n";
        pause();
    }

    void showScholarships() {
        clearScreen();
        cout << "Scholarships:\n"
             << "- Merit-based scholarships\n"
             << "- Need-based financial aid\n"
             << "- Special scholarships for women\n";
        pause();
    }

    void showFacilities() {
        clearScreen();
        cout << "Campus Facilities:\n"
             << "- Modern classrooms\n"
             << "- Computer labs\n"
             << "- Library resources\n"
             << "- Sports facilities\n";
        pause();
    }

    void showContacts() {
        clearScreen();
        cout << "Contact Information:\n"
             << "Address: 4 Embankment Drive Road, Uttara, Dhaka\n"
             << "Phone: +88 02 55091801\n"
             << "Email: info@iubat.edu\n";
        pause();
    }
};

int main() {
    User* currentUser = nullptr;
    IUBATChatbot chatbot;

    while(true) {
        clearScreen();
        cout << "UNIVERSITY MANAGEMENT SYSTEM\n\n";
        cout << "1. Login\n"
             << "2. Register\n"
             << "3. Chatbot\n"
             << "4. Exit\n"
             << "Choice: ";

        int choice;
        cin >> choice;

        switch(choice) {
            case 1: {
                currentUser = User::login();
                if(currentUser) {
                    currentUser->showDashboard();
                    delete currentUser;
                }
                break;
            }
            case 2:
                User::registerUser();
                break;
            case 3:
                chatbot.start();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
                pause();
        }
    }
}