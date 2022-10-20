#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;
//using std::map;

mt19937 random_mt;

class States
{
	string State;
	int Capita;
	int Population;
	int HouseholdIncome;
	int NumHouses;
public:
	States(string State = "Null", int Capita = 0, int Population = 0, long HouseholdIncome = 0, int NumHouse = 0)
	{
		this->State = State;
		this->Capita = Capita;
		this->Population = Population;
		this->HouseholdIncome = HouseholdIncome;
		this->NumHouses = NumHouse;
	}
	string GetState()
	{
		return State;
	}
	int GetCapita()
	{
		return Capita;
	}
	int GetPopulation()
	{
		return Population;
	}
	long GetHouseholdIncome()
	{
		return HouseholdIncome;
	}
	int GetNumHouse()
	{
		return NumHouses;
	}
};

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}
void RollDice(int numberOfRolls, int numberOfSides);
int main()
{

	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";

		int firstRoll;
		cin >> firstRoll;
		//cout << firstRoll << endl;
		cout << "Number of sides on this die: ";

		int diceSides;
		cin >> diceSides;
		//cout << diceSides << endl;


		RollDice(firstRoll, diceSides);


	}
	else if (option == 2)
	{
		map<string, States> stateInfo;
		// Load the states
		//States newStates;

		ifstream inFile("states.csv");
		if (inFile.is_open())
		{
			string lineFromFile;
			getline(inFile, lineFromFile);
			//cout << lineFromFile << endl;
			//getline(inFile, lineFromFile, ',');
			//cout << lineFromFile << endl;
			//getline(inFile, lineFromFile, ',');
			//cout << lineFromFile << endl;

			while (getline(inFile, lineFromFile))
			{
				istringstream stream(lineFromFile);
				string buffer;

				string stateNames;
				int capital, pop, householdNumber;
				long householdIncome;

				getline(stream, stateNames, ',');
				//stateNames = buffer;
				//cout << stateNames << endl;

				getline(stream, buffer, ',');
				capital = stoi(buffer);
				//cout << capital << endl;

				getline(stream, buffer, ',');
				pop = stoi(buffer);
				//cout << pop << endl;

				getline(stream, buffer, ',');
				householdIncome = stol(buffer);
				//cout << householdIncome << endl;

				getline(stream, buffer, ',');
				householdNumber = stoi(buffer);
				//cout << householdNumber << endl;

				States c(stateNames, capital, pop, householdIncome, householdNumber);
				stateInfo.emplace(stateNames, c);
			}
		}
		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;

		int secondOption;
		cin >> secondOption;
		if (secondOption == 1)
		{
			auto iter = stateInfo.begin();
			for (; iter != stateInfo.end(); ++iter)
			{
				cout << iter->first << endl;
				cout << "Population: " << iter->second.GetPopulation() << endl;
				cout << "Per Capita Income: " << iter->second.GetCapita() << endl;
				cout << "Median Household Income: " << iter->second.GetHouseholdIncome() << endl;
				cout << "Number of Households: " << iter->second.GetNumHouse() << endl;
			}
		}
		if (secondOption == 2)
		{
			//map<string, States>::iterator copy;
			auto iter = stateInfo.begin();
			string searchState;
			cin >> searchState;
			iter = stateInfo.find(searchState);

			if (iter == stateInfo.end())
			{
				cout << "No match found for " + searchState << endl;
			}
			else
			{
				cout << iter->first << endl;
				cout << "Population: " << iter->second.GetPopulation() << endl;
				cout << "Per Capita Income: " << iter->second.GetCapita() << endl;
				cout << "Median Household Income: " << iter->second.GetHouseholdIncome() << endl;
				cout << "Number of Households: " << iter->second.GetNumHouse() << endl;
			}
			//auto iter = stateInfo.begin();
			//for (; iter != stateInfo.end(); ++iter)
			//{
			//	cout << iter->first << endl;
			//	cout << "Population: " << iter->second.GetPopulation() << endl;
			//	cout << "Per Capita Income: " << iter->second.GetCapita() << endl;
			//	cout << "Median Household Income: " << iter->second.GetHouseholdIncome() << endl;
			//	cout << "Number of Households: " << iter->second.GetNumHouse() << endl;
			//}
		
		}

	}

	return 0;
}
void RollDice(int numberOfRolls, int numberOfSides)
{
	map<int, int> dice;
	int k = 1;
	for (int i = 0; i < numberOfSides; i++)
	{
		dice[k];
		k++;
	}
	for (int i = 0; i < numberOfRolls; i++)
	{
		int randomNumber = Random(1, numberOfSides);
		//dice.emplace(k, randomNumber);
		dice[randomNumber] = dice[randomNumber] + 1;
		//RollDice(firstRoll, randomNumber);
		//k++;
	}
	auto iter = dice.begin();
	for (; iter != dice.end(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;

	}
}