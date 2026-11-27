
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;

    ofstream out("persons.txt");
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Person " << i + 1 << " name: ";
        cin >> name;
        cout << "Person " << i + 1 << " age: ";
        cin >> age;
        out << name << " " << age << endl;
    }
    out.close();

    vector<Person> v;
    ifstream in("persons.txt");
    Person p;
    while (in >> p.name >> p.age) {
        v.push_back(p);
    }
    in.close();

    if (v.empty()) {
        cout << "No data found." << endl;
        return 0;
    }

    Person younger = v[0], older = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i].age < younger.age) younger = v[i];
        if (v[i].age > older.age)   older = v[i];
    }

    ofstream res("results.txt");
    res << "Youngest: " << younger.name << " " << younger.age << endl;
    res << "Oldest: " << older.name << " " << older.age << endl;
    res.close();

    cout << "Results saved in results.txt" << endl;
    return 0;
}
