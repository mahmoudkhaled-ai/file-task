#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ofstream out("names.txt");
    cout << "esraa ebrahim" << endl;
    cout << "ahmed mostafa" << endl;
    cout << "youssef ali" << endl;
    cout << "hadeer ebrahim" << endl;
    out.close();

    ifstream input("names.txt");
    string line;
    vector<string> data;
    while (getline(input, line))
    {
        data.push_back(line);
    }
    sort(data.begin(), data.end());
    input.close();

    cout << "Lines sorted ascending Successfully" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}
