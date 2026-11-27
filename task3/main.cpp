#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("welcome.txt");

    file << "Hello Everybody";
    file.close();

    fstream myfile("welcome.txt");

    string text;
    getline(myfile, text);

    size_t pos = text.find("body");

    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    myfile.close();

    ofstream output("welcome.txt");

    output << text;
    output.close();

    cout << text;

    return 0;
}
