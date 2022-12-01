// AdventOfCode2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
        vector<int> inputs;
        int j = 0;

        while (inputFile) {
            getline(inputFile, fileString);
            
        }
    }
    else {
        cout << "Could not open file." << endl;
    }
}
