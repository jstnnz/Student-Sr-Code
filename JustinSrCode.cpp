#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct Student {
    int srCode;
    string name;
    string subjectCode;
    string instructorName;
    string scheduleTime;
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "-----Enter the data for student no. " << i + 1 << "-----" << endl;
        cout << "SR-CODE: ";
        cin >> students[i].srCode;
        cout << "Name of student: ";
        cin >> students[i].name;
        cout << "Subject code: ";
        cin >> students[i].subjectCode;
        cout << "Instructor's name: ";
        cin >> students[i].instructorName;
        cout << "Schedule time: ";
        cin >> students[i].scheduleTime;
        cout << endl;
    }

    int studentId;
    cout << "\n\nEnter the student ID to display the data: ";
    cin >> studentId;

    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].srCode == studentId) {
            cout << "Name: " << students[i].name << endl;
            cout << "Subject Code: " << students[i].subjectCode << endl;
            cout <<  "Instructor: "<<students[i].instructorName << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }

    char choice;
    cout << "\nTry again? [Y/N]: ";
    cin >> choice;

    delete[] students;
    students = NULL;

    if (choice == 'Y' || choice == 'y') {
        main();
    }

    return 0;
}