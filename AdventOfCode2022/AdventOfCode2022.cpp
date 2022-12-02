#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	ifstream file("input.txt");

	if (file.is_open()) {
		string line;
		vector<int> lonelyElves;
		vector<int> elfSum;
		int topThree[3];
		int sum = 0;

		while (file) {

			// läser EN rad i file och sparar i string line
			getline(file, line);

			// om line inte är tom konverteras värdet till int num och läggs till sist i vectorn lonelyElves för att representera enskilda elves packning
			if (!line.empty()) {
				int num = stoi(line);
				lonelyElves.push_back(num);
			}

			// om line ÄR tom:
			// 1. innehåll i lonelyElves summeras och sparas i int sum.
			// 2. sum sätts in i en ny vector elfSum där alla totalen av elvesens packningar samlas
			// 3. lonelyElves töms så att iterationen kan börja om
			else {
				sum = accumulate(lonelyElves.begin(), lonelyElves.end(), 0);
				elfSum.push_back(sum);

				lonelyElves.clear();
			}
		}

		// highest pekar på största värdet i elfSum
		// highest värde läggs in i en array topThree
		// högsta värdet i elfSum raderas, så att det finns en ny högsta värde i vectorn
		// körs 3 gånger
		for (int i = 0; i < 3; i++) {
			int highest = *max_element(elfSum.begin(), elfSum.end());
			topThree[i] = highest;
			elfSum.erase(max_element(elfSum.begin(), elfSum.end()));
		}

		// beräknar summan av topThree och printar ut det
		cout << accumulate(topThree, topThree + 3, 0);

	}
	else {
		cout << "Could not open file." << endl;
	}
}

int SolutionD1P1()
{
	ifstream file("input.txt");

	if (file.is_open()) {
		string line;
		vector<int> myVector;
		int sum = 0;

		while (file) {

			//läser EN rad
			getline(file, line);

			//om raden inte är tom konverteras string till int och värdet läggs till sist i vectorn
			if (!line.empty()) {
				int num = stoi(line);
				myVector.push_back(num);
			}

			//om raden ÄR tom:
			//1. vectors innehåll summeras och sparas i en variabel sum.
			//2. sum kontrolleras om den är större än nästa summering av vectorn,
			// om sant: sparas värdet, om falskt: värdet kastas.
			//3. vectorn töms så att iterationen kan börja om
			else {
				if (sum < accumulate(myVector.begin(), myVector.end(), 0))
					sum = accumulate(myVector.begin(), myVector.end(), 0);
				myVector.clear();
			}
		}
		cout << sum;
	}
	else {
		cout << "Could not open file." << endl;
	}
	return 0;
}
