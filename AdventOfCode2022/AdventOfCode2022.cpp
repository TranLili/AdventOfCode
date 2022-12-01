#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile("2022Day1.txt");

    if (inputFile.is_open()) {
        string fileString;

        while (inputFile) {
            getline(inputFile, fileString);
            vector<int> inputsList;
            
            cout << fileString << endl;
        }
    }
    else {
        cout << "Could not open file." << endl;
    }
}
