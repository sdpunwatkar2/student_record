#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }

    int getRollNo() {
        return rollNo;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(int roll, string name, float marks) {
        Student s(roll, name, marks);
        students.push_back(s);
    }

    void showAll() {
        if (students.empty()) {
            cout << "No student records found!" << endl;
            return;
        }
        for (auto& s : students) {
            s.display();
        }
    }

    void deleteStudent(int roll) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNo() == roll) {
                students.erase(it);
                cout << "Student with Roll No " << roll << " deleted." << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    StudentManager sm;
    int choice;

    while (true) {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n2. Show All Students\n3. Delete Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float marks;
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
            sm.addStudent(roll, name, marks);
        } else if (choice == 2) {
            sm.showAll();
        } else if (choice == 3) {
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            sm.deleteStudent(roll);
        } else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
