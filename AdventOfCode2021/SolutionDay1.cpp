// AdventOfCode2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("InputDay01.txt");

    if (inputFile.is_open()) {
        string fileString;
        vector<int> inputs;
        int j = 0;

        while (inputFile) {
            getline(inputFile, fileString);
            int num = stoi(fileString);
            inputs.push_back(num);

            //checks if sum of 3 elements is less than the 3 elements that are one index position ahead on a vector
            //if the first sum is less than the second sum, counter variable int j goes up by 1.
            //will repeat until the end of the vector
            if (inputs.size() == 2000)
                for (int i = 0; i < (inputs.size() - 3); i++)
                    if ((inputs[i] + inputs[i + 1] + inputs[i + 2]) < (inputs[i + 1] + inputs[i + 2] + inputs[i + 3])) {
                        j++;

                        //checks first sum
                        int sum1 = (inputs[i] + inputs[i + 1] + inputs[i + 2]);
                        cout << "sum1:" << sum1 << endl;

                        //checks second sum
                        int sum2 = (inputs[i + 1] + inputs[i + 2] + inputs[i + 3]);
                        cout << "sum2:" << sum2 << endl;

                        //couts sums and counter
                        cout << "j:" << j << endl;
                    }

        }
        cout << j;
    }
    else {
        cout << "Could not open file." << endl;
    }

}