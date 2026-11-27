#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    ofstream out("grades.txt");
    if (!out) {
        cout << "Error: cannot create grades.txt" << endl;
        return 1;
    }
    for (int i = 1; i <= 5; i++) {
        int g;
        cout << "Enter grade " << i << ": ";
        cin >> g;
        out << g << endl;
    }
    out.close();

    ifstream in("grades.txt");
    if (!in) {
        cout << "Error: cannot open grades.txt" << endl;
        return 1;
    }
    int x;
    cout << "\nGrades before deletion:" << endl;
    while (in >> x) {
        cout << x << endl;
    }
    in.close();

    int toDelete;
    cout << "\nEnter grade to delete: ";
    cin >> toDelete;

    in.open("grades.txt");
    ofstream temp("temp.txt");
    if (!in || !temp) {
        cout << "Error: cannot open files" << endl;
        return 1;
    }

    bool found = false;
    while (in >> x) {
        if (x == toDelete && !found) {
            found = true;
        } else {
            temp << x << endl;
        }
    }
    in.close();
    temp.close();

    if (found) {
        remove("grades.txt");
        rename("temp.txt", "grades.txt");
        cout << "Grade deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Error: grade not found." << endl;
    }

    ifstream result("grades.txt");
    cout << "\nGrades after deletion:" << endl;
    while (result >> x) {
        cout << x << endl;
    }
    result.close();

    return 0;
}
