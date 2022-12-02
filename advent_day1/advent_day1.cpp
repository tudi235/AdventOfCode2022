#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	cout << "Welcome to Advent of Code 2022 - Day 1\n";

	ifstream input("input.txt");
	int item = 0, sum = 0, lineCounter = 0, i = 0;
	string line;
	vector<string> readData;

	if (input.is_open())
	{
		cout << "\nReading file...\n\n";
		while (getline(input, line))
		{
			cout << line << endl;
			if (line == "")
				readData.push_back("$");
			else
				readData.push_back(line);
			lineCounter++;
		}
		input.close();
		cout << "\nDone!\n";
		cout << "There are " << lineCounter << " new lines in the file.\n";
	}
	else
		cout << "Reading the file failed!";

	vector<int> sumArr(lineCounter, 0);

	cout << "\nArray: \n";
	for (int k = 0; k < lineCounter; k++)
	{
		sumArr[k] = k;
		cout << sumArr[k] << endl;
	}
	cout << "\nOriginal vector Data: \n";
	for (int k = 0; k < lineCounter; k++)
	{
		cout << readData[k] << endl;
	}
	return 0;
}

