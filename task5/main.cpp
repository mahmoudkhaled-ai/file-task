#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream out("students.txt", ios::app);
    char choice;

    do {
        Student s;
        s.delim = '$';

        cout << "Enter name: ";
        cin.ignore(1000, '\n');
        cin.getline(s.name, 20);

        cout << "Enter ID: ";
        cin >> s.id;

        cout << "Enter grade: ";
        cin >> s.grade;

        out << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Add more records? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    out.close();
    return 0;
}
