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
		vector<string> input;
		vector<string> pairs;
		vector<int> sections;
		int count = 0;

		// loop för att läsa hela filen
		while (file) {
			// läser EN rad i file och sparar i string line
			// line pushas till slutet av vector sections
			getline(file, line);
			input.push_back(line);
		}
		for (int i = 0; i < input.size(); i++)
		{
			string delimiter = ",";
			string pair1 = input[i].substr(0, input[i].find(delimiter));
			string pair2 = input[i].substr(input[i].find(delimiter) + delimiter.length());
			pairs.push_back(pair1);
			pairs.push_back(pair2);

			for (int j = 0; j < pairs.size(); j++)
			{
				string delimiter = "-";
				string numA = pairs[j].substr(0, pairs[j].find(delimiter));
				string numB = pairs[j].substr(pairs[j].find(delimiter) + delimiter.length());
				int num1 = stoi(numA);
				int num2 = stoi(numB);
				sections.push_back(num1);
				sections.push_back(num2);
			}
			pairs.clear();
		}

		// sections är en lista med alla pairs a-b,c-d
		for (int i = 0; i < sections.size() - 4; i += 4)
		{
			//pair a-b
			int a = sections[i];
			int b = sections[i + 1];

			//pair c-d
			int c = sections[i + 2];
			int d = sections[i + 3];

			
		}
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

//int SolutionD2P2()
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
//
//			// line sparas längst bak i en string vector kallad shapes
//			shapes.push_back(line);
//
//			// A: Rock, 1p
//			// B: Paper, 2p
//			// C: Scissors, 3p
//
//			// X: lose, 0p
//			// Y: draw, 3p
//			// Z: win, 6p
//
//		}
//		// för varje iteration, kolla på värdet på position 3 på index i.
//		for (int i = 0; i < shapes.size() - 1; i++) {
//			char c = shapes[i][2];
//			switch (c)
//			{
//			case 'X':
//				// då position 2 innehåller ett X: lose
//				cout << "lose: ";
//				if (shapes[i][0] == 'A') {
//					shapes[i][2] = 'C';
//					cout << "shape 2 is C" << endl;
//				}
//
//				if (shapes[i][0] == 'B') {
//					shapes[i][2] = 'A';
//					cout << "shape 2 is A" << endl;
//				}
//
//
//				if (shapes[i][0] == 'C') {
//					shapes[i][2] = 'B';
//					cout << "shape 2 is B" << endl;
//				}
//				break;
//
//			case 'Y':
//				//då position 2 innehåller ett Y: draw
//				cout << "draw: ";
//				shapes[i][2] = shapes[i][0];
//				cout << shapes[i][0] << endl;
//				totalScore += 3;
//				break;
//
//			case 'Z':
//				// då position 2 innehåller ett Z: win
//				cout << "win: ";
//				if (shapes[i][0] == 'A') {
//					shapes[i][2] = 'B';
//					cout << "shape 2 is B" << endl;
//				}
//
//				if (shapes[i][0] == 'B') {
//					shapes[i][2] = 'C';
//					cout << "shape 2 is C" << endl;
//				}
//
//				if (shapes[i][0] == 'C') {
//					shapes[i][2] = 'A';
//					cout << "shape 2 is A" << endl;
//				}
//
//				totalScore += 6;
//				break;
//			}
//			if (shapes[i][2] == 'A')
//				totalScore += 1;
//			if (shapes[i][2] == 'B')
//				totalScore += 2;
//			if (shapes[i][2] == 'C')
//				totalScore += 3;
//		}
//
//		cout << totalScore;
//	}
//	else {
//		cout << "Could not open file." << endl;
//	}
//	return 0;
//}

//int SolutionD3P1()
//{
//	ifstream file("input.txt");
//
//	if (file.is_open()) {
//		string line;
//		vector<string> rucksack;
//		vector<int> priority;
//
//		while (file) {
//
//			// läser EN rad i file och sparar i string line
//			getline(file, line);
//
//			// line sparas längst bak i en string vector kallad shapes
//			rucksack.push_back(line);
//		}
//		for (int i = 0; i < rucksack.size() - 1; i++) {
//			//hitta storleken på varje line och delar på hälften
//			int compartment = rucksack[i].size() / 2;
//
//			// dela upp line i 2 lika stora substrings, kallade sub1 och sub2 med storleken av en compartment (halva storleken på line)
//			string sub1 = rucksack[i].substr(0, compartment);
//			string sub2 = rucksack[i].substr(compartment, compartment);
//
//			// character på index [j] i sub1 översättas till ett nummer, det jämförs med karaktärerna i sub2.
//			for (int j = 0; j < sub1.size(); j++) {
//				int c1 = sub1[j];
//
//				// om den gemensamma bokstaven har hittats bryts loopen och går vidare till nästa rad
//				bool answerFound = false;
//				for (int k = 0; k < sub2.size(); k++) {
//					int c2 = sub2[k];
//					if (c2 == c1) {
//						// om det är a-z (lowercase a = 97 -> c2 blir större än 96), värdet subtraheras med 96 så det blir 1 enl. uppgiften.
//						// om det är A-Z (uppercase A = 65 -> c2 är INTE större än 96), värdet subtraheras med 37 så att det blir 27 enl. uppgiften.
//						int cvalue = (c2 > 96) ? c2 -= 96 : c2 -= 38;
//						priority.push_back(cvalue);
//						answerFound = true;
//						break;
//					}
//				}
//				if (answerFound)
//					break;
//			}
//
//		}
//		int sum = accumulate(priority.begin(), priority.end(), 0);
//		cout << sum;
//	}
//
//	else {
//		cout << "Could not open file." << endl;
//	}
//	return 0;
//}

//int SolutionD3P2()
//{
//	ifstream file("input.txt");
//
//	if (file.is_open()) {
//		string line;
//		vector<string> rucksack;
//		vector<int> priority;
//
//		// loop för att läsa hela filen
//		while (file) {
//			// läser EN rad i file och sparar i string line
//			getline(file, line);
//			rucksack.push_back(line);
//		}
//
//		// loopen hoppar 3 steg varje gång
//		for (int i = 0; i < rucksack.size() - 1; i += 3) {
//
//
//			// loopen går lika långt som raden på index [i] är stort.
//			for (int j = 0; j < rucksack[i].size(); j++) {
//				bool answerFound = false;
//				int c1 = rucksack[i][j];
//
//				for (int k = 0; k < rucksack[i + 1].size(); k++) {
//					int c2 = rucksack[i + 1][k];
//					if (c1 == c2) {
//						for (int l = 0; l < rucksack[i + 2].size(); l++) {
//							int c3 = rucksack[i + 2][l];
//							if (c2 == c3) {
//								int cvalue = (c1 > 96) ? c1 -= 96 : c1 -= 38;
//								priority.push_back(cvalue);
//								answerFound = true;
//								break;
//							}
//						}
//						if (answerFound)
//							break;
//					}
//				}
//				if (answerFound)
//					break;
//			}
//		}
//		int sum = accumulate(priority.begin(), priority.end(), 0);
//		cout << sum;
//	}
//
//	else {
//		cout << "Could not open file." << endl;
//	}
//}

//int SolutionD4P1()
//{
//	ifstream file("input.txt");
//
//	if (file.is_open()) {
//		string line;
//		vector<string> input;
//		vector<string> pairs;
//		vector<int> sections;
//		int count = 0;
//
//		// loop för att läsa hela filen
//		while (file) {
//			// läser EN rad i file och sparar i string line
//			// line pushas till slutet av vector sections
//			getline(file, line);
//			input.push_back(line);
//		}
//		for (int i = 0; i < input.size(); i++)
//		{
//			string delimiter = ",";
//			string pair1 = input[i].substr(0, input[i].find(delimiter));
//			string pair2 = input[i].substr(input[i].find(delimiter) + delimiter.length());
//			pairs.push_back(pair1);
//			pairs.push_back(pair2);
//
//			for (int j = 0; j < pairs.size(); j++)
//			{
//				string delimiter = "-";
//				string numA = pairs[j].substr(0, pairs[j].find(delimiter));
//				string numB = pairs[j].substr(pairs[j].find(delimiter) + delimiter.length());
//				int num1 = stoi(numA);
//				int num2 = stoi(numB);
//				sections.push_back(num1);
//				sections.push_back(num2);
//			}
//			pairs.clear();
//		}
//		for (int i = 0; i < sections.size() - 4; i += 4)
//		{
//			int a = sections[i];
//			int b = sections[i + 1];
//			int c = sections[i + 2];
//			int d = sections[i + 3];
//
//			if ((a <= c && b >= d) || (c <= a && d >= b))
//				count++;
//		}
//		cout << count;
//	}
//
//	else {
//		cout << "Could not open file." << endl;
//	}
//}