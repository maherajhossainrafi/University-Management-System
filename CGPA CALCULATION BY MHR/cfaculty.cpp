#include "cfaculty.h"
#include "filemanager.h"
#include "grades.h"
#include "win.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

Faculty::Faculty(const string& u, const string& p)
    : User(u, p) {}

void Faculty::showDashboard() {
    int choice;
    do {
        printHeader("FACULTY DASHBOARD");
        cout << "1. Enter Grades\n2. Bulk Upload\n3. Logout\nChoice: ";
        cin >> choice;

        if (choice == 1) enterGrades();
        else if (choice == 2) bulkUpload();
    } while (choice != 3);
}

void Faculty::enterGrades() {
    printHeader("ENTER GRADES");
    string studentName;
    Course c;

    cout << "Student username: ";
    cin >> studentName;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Marks (0-100): ";
    cin >> c.marks;
    cout << "Credit hours: ";
    cin >> c.credit;

    c.grade = calculateGrade(c.marks);

    ofstream file(studentName + ".csv", ios::app);
    if (file) {
        file << c.name << "," << c.marks << ","
             << c.credit << "," << c.grade << "\n";
        cout << "\nGrade added successfully!\n";
    } else {
        cout << "\nError saving grade!\n";
    }

    cin.ignore();
    cin.get();
}

void Faculty::bulkUpload() {
    printHeader("BULK UPLOAD");
    string filename;
    cout << "CSV filename: ";
    cin >> filename;

    ifstream file(filename);
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string student, course;
            int marks, credit;

            getline(ss, student, ',');
            getline(ss, course, ',');
            ss >> marks;
            ss.ignore();
            ss >> credit;

            ofstream out(student + ".csv", ios::app);
            out << course << "," << marks << ","
                << credit << "," << calculateGrade(marks) << "\n";
        }
        cout << "\nBulk upload completed!\n";
    } else {
        cout << "\nFile not found!\n";
    }

    cin.ignore();
    cin.get();
}
