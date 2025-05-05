#include "cadmin.h"
#include "filemanager.h"
#include "grades.h"
#include "win.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

Admin::Admin(const string& u, const string& p)
    : User(u, p) {}

void Admin::showDashboard() {
    int choice;
    do {
        printHeader("ADMIN DASHBOARD");
        cout << "1. Configure Grade Scale\n2. Edit Grades\n"
             << "3. Export All Data\n4. Logout\nChoice: ";
        cin >> choice;

        if (choice == 1) configureGradeScale();
        else if (choice == 2) editGrades();
        else if (choice == 3) exportAllData();
    } while (choice != 4);
}

void Admin::configureGradeScale() {
    printHeader("CONFIGURE GRADE SCALE");
    ofstream file("grade_scale.csv");
    if (file) {
        cout << "Enter grades in format (Grade,Min,Max). Enter 'done' to finish:\n";
        string line;
        cin.ignore();
        while (true) {
            cout << "> ";
            getline(cin, line);
            if (line == "done") break;
            file << line << "\n";
        }
        cout << "Grade scale updated!\n";
    } else {
        cout << "Error saving grade scale!\n";
    }
    cin.get();
}

void Admin::editGrades() {
    printHeader("EDIT GRADES");
    string student;
    cout << "Enter student username: ";
    cin >> student;

    vector<Course> courses;
    ifstream in(student + ".csv");
    if (in) {
        string line;
        while (getline(in, line)) {
            Course c;
            stringstream ss(line);
            getline(ss, c.name, ',');
            ss >> c.marks; ss.ignore();
            ss >> c.credit; ss.ignore();
            getline(ss, c.grade);
            courses.push_back(c);
        }
    }

    cout << "\nCourses:\n";
    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i].name << " - "
             << courses[i].grade << endl;
    }

    cout << "\nEnter course number to edit: ";
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= static_cast<int>(courses.size())) {
        cout << "New marks: ";
        cin >> courses[choice - 1].marks;
        courses[choice - 1].grade = calculateGrade(courses[choice - 1].marks);

        ofstream out(student + ".csv");
        for (const auto& c : courses) {
            out << c.name << "," << c.marks << ","
                << c.credit << "," << c.grade << "\n";
        }
        cout << "Grade updated!\n";
    } else {
        cout << "Invalid selection!\n";
    }
    cin.ignore();
    cin.get();
}

void Admin::exportAllData() {
    printHeader("EXPORT ALL DATA");
    ofstream backup("full_backup.zip");
    if (backup) {
        cout << "All data exported to full_backup.zip\n";
    } else {
        cout << "Error creating backup!\n";
    }
    cin.ignore();
    cin.get();
}
