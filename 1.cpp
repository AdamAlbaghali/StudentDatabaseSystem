#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Student {
private:
    string name;
    int id;
    double grade;

public:
    Student(string name, int id, double grade)
        : name(name), id(id), grade(grade) {}

    void display() const {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }

    int getId() const { return id; }
};

int main() {
    vector<Student> studentDatabase;
    int choice;
    int id;
    string name;
    double grade;

    while (true) {
        cout << "\nMenu:\n1. Add a new student\n2. Display all students\n3. Find a student by ID\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter grade: ";
            cin >> grade;
            studentDatabase.push_back(Student(name, id, grade));
            break;
        case 2:
            cout << "Student Database:" << endl;
            for (const auto &student : studentDatabase) {
                student.display();
            }
            break;
        case 3: {
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;
            for (const auto &student : studentDatabase) {
                if (student.getId() == id) {
                    cout << "Student found:" << endl;
                    student.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with ID " << id << " not found." << endl;
            }
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
