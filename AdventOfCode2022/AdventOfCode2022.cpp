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
		vector<string> shapes;
		int totalScore = 0;

		while (file) {

			// läser EN rad i file och sparar i string line
			getline(file, line);
			shapes.push_back(line);

			// A: Rock, 1p
			// B: Paper, 2p
			// C: Scissors, 3p

			// X: lose, 0p
			// Y: draw, 3p
			// Z: win, 6p
			
		}
		for (int i = 0; i < shapes.size() - 1; i++) {
			char c = shapes[i][2];
			switch (c)
			{
			case 'X':
				//lose
				break;

			case 'Y':
				//draw
				break;

			case 'Z':
				//win
				break;
			}

			if (shapes[i][0] == shapes[i][2])
				totalScore += 3;

			if ((shapes[i][0] == 'A' && shapes[i][2] == 'B') || (shapes[i][0] == 'B' && shapes[i][2] == 'C') || (shapes[i][0] == 'C' && shapes[i][2] == 'A'))
				totalScore += 6;
		}

		cout << totalScore;
	}
	else {
		cout << "Could not open file." << endl;
	}
}

// int SolutionD1P1()
// {
// 	ifstream file("input.txt");
// 
// 	if (file.is_open()) {
// 		string line;
// 		vector<int> myVector;
// 		int sum = 0;
// 
// 		while (file) {
// 
// 			//läser EN rad
// 			getline(file, line);
// 
// 			//om raden inte är tom konverteras string till int och värdet läggs till sist i vectorn
// 			if (!line.empty()) {
// 				int num = stoi(line);
// 				myVector.push_back(num);
// 			}
// 
// 			//om raden ÄR tom:
// 			//1. vectors innehåll summeras och sparas i en variabel sum.
// 			//2. sum kontrolleras om den är större än nästa summering av vectorn,
// 			// om sant: sparas värdet, om falskt: värdet kastas.
// 			//3. vectorn töms så att iterationen kan börja om
// 			else {
// 				if (sum < accumulate(myVector.begin(), myVector.end(), 0))
// 					sum = accumulate(myVector.begin(), myVector.end(), 0);
// 				myVector.clear();
// 			}
// 		}
// 		cout << sum;
// 	}
// 	else {
// 		cout << "Could not open file." << endl;
// 	}
// 	return 0;
// }

// alternativ lösning: sortera elfSum efter descending order och take 3.
// int SolutionD1P2()
// {
// 	ifstream file("input.txt");
// 
// 	if (file.is_open()) {
// 		string line;
// 		vector<int> lonelyElves;
// 		vector<int> elfSum;
// 		int topThree[3];
// 		int sum = 0;
// 
// 		while (file) {
// 
// 			// läser EN rad i file och sparar i string line
// 			getline(file, line);
// 
// 			// om line inte är tom konverteras värdet till int num och läggs till sist i vectorn lonelyElves för att representera enskilda elves packning
// 			if (!line.empty()) {
// 				int num = stoi(line);
// 				lonelyElves.push_back(num);
// 			}
// 
// 			// om line ÄR tom:
// 			// 1. innehåll i lonelyElves summeras och sparas i int sum.
// 			// 2. sum sätts in i en ny vector elfSum där alla totalen av elvesens packningar samlas
// 			// 3. lonelyElves töms så att iterationen kan börja om
// 			else {
// 				sum = accumulate(lonelyElves.begin(), lonelyElves.end(), 0);
// 				elfSum.push_back(sum);
// 
// 				lonelyElves.clear();
// 			}
// 		}
// 
// 		// highest pekar på största värdet i elfSum
// 		// highest värde läggs in i en array topThree
// 		// högsta värdet i elfSum raderas, så att det finns en ny högsta värde i vectorn
// 		// körs 3 gånger
// 		for (int i = 0; i < 3; i++) {
// 			int highest = *max_element(elfSum.begin(), elfSum.end());
// 			topThree[i] = highest;
// 			elfSum.erase(max_element(elfSum.begin(), elfSum.end()));
// 		}
// 
// 		// beräknar summan av topThree och printar ut det
// 		cout << accumulate(topThree, topThree + 3, 0);
// 
// 	}
// 	else {
// 		cout << "Could not open file." << endl;
// 	}
// 
// 	return 0;
// }

//int SolutionD2P1()
//{
//	ifstream file("input.txt");
//
//	if (file.is_open()) {
//		string line;
//		vector<string> shapes;
//		int totalScore = 0;
//
//		while (file) {
//
//			// läser EN rad i file och sparar i string line
//			getline(file, line);
//			shapes.push_back(line);
//
//			// A: Rock
//			// B: Paper
//			// C: Scissors
//
//			// X: Rock, 1p
//			// Y: Paper, 2p
//			// Z: Scissors, 3p
//
//			// draw: 3p
//			// win: 6p
//
//		}
//		for (int i = 0; i < shapes.size() - 1; i++) {
//			char c = shapes[i][2];
//			switch (c)
//			{
//			case 'X':
//				shapes[i][2] = 'A';
//				totalScore += 1;
//				break;
//
//			case 'Y':
//				shapes[i][2] = 'B';
//				totalScore += 2;
//				break;
//
//			case 'Z':
//				shapes[i][2] = 'C';
//				totalScore += 3;
//				break;
//			}
//
//			if (shapes[i][0] == shapes[i][2])
//				totalScore += 3;
//
//			if ((shapes[i][0] == 'A' && shapes[i][2] == 'B') || (shapes[i][0] == 'B' && shapes[i][2] == 'C') || (shapes[i][0] == 'C' && shapes[i][2] == 'A'))
//				totalScore += 6;
//		}
//
//		cout << totalScore;
//	}
//	else {
//		cout << "Could not open file." << endl;
//	}
//}