#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string fruit;

    ifstream file("fruit.txt");

    while (getline(file, fruit))
    {
        cout << fruit << endl;
    }

    file.close();

    ofstream outfile("fruit.txt", ios::app);

    outfile << "Fresh Fruits" << endl;

    outfile.close();

    return 0;
}
