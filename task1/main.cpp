#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter student full name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student Grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    file << "Student Name: " << name << endl;
    file << "Student ID: " << id << endl;
    file << "Student Grade: " << grade << endl;

    file.close();

    cout << "Data saved successfully!";

    return 0;
}
