/*
* babyNamePopularity.cpp
* Matthew Bersalona
* CSCI 123 C
* 10/08/2024
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void render(string name, string gender);
int findRanking(string filename, string name, string gender);

int main() {
	string name, gender;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your gender (boy or girl): ";
	cin >> gender;
	cin.ignore();
	render(name, gender);

	return 0; 
}

void render(string name, string gender) {
	int oldRank = findRanking("babyNames1973.txt", name, gender);
	int currentRank = findRanking("babyNames2023.txt", name, gender);
	int gap;

	if (currentRank != -1 && oldRank != -1) {
		if (oldRank < currentRank) {
			gap = currentRank - oldRank;
			cout << "The name " << name << " has decreased from " << gap << " positions in the popularity ranking from Rank " << oldRank << " in 1972 to Rank " << currentRank << " in 2023." << endl;
		}
		else if (currentRank < oldRank) {
			gap = oldRank - currentRank;
			cout << "The name " << name << " has increased from " << gap << " positions in the popularity ranking from Rank " << oldRank << " in 1972 to Rank " << currentRank << " in 2023." << endl;
		}
		else {
			cout << "The name " << name << " has not changed, ranking " << oldRank << " in both 1972 and 2023.";
		}
	}
	else if (currentRank != -1 && oldRank == -1) {
		cout << "The name " << name << " was ranked " << currentRank << ", while it was not present in 1972.";
	}
	else {
		cout << "The name " << name << " was ranked " << oldRank << ", but it is no longer present.";
	}
}

int findRanking(string filename, string name, string gender) {
	string maleName, maleNumber, femaleName, femaleNumber;
	int ranking = -1;
	ifstream babyNames;
	babyNames.open(filename);

	while (!babyNames.eof()) {
		babyNames >> ranking >> maleName >> maleNumber >> femaleName >> femaleNumber;
		if (gender == "girl") {
			if (name == femaleName) {
				break;
			}
		}
		else if (gender == "boy") {
			if (name == maleName) {
				break;
			}
		}
		if (name != maleName && name != femaleName) {
			ranking = -1;
		}
	}
	babyNames.close();
	return ranking;
}