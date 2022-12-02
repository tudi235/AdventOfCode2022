#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Welcome to Advent of Code 2022 - Day 1\n";

	ifstream input("input.txt");
	int sum = 0, lineCounter = 0, maxItem = 0, maxItemPosition = 0, i = 0;
	string line;
	vector<string> readData;

	//read data from txt file and manipulate it
	if (input.is_open())
	{
		cout << "\nReading file...\n";
		while (getline(input, line))
		{
			//cout << line << endl;
			if (line == "")
				readData.push_back("$");
			else
				readData.push_back(line);
			lineCounter++;
		}
		input.close();
		cout << "\nDone!\n";
		cout << "\nThere are " << lineCounter << " new lines in the file.\n";
	}
	else
		cout << "Reading the file failed!";

	//calculate sum
	vector<int> sumArr;
	//cout << "\nreadData: \n";
	for (int k = 0; k < lineCounter; k++)
	{
		//cout << readData[k] << endl;
		if (readData[k] != "$")
		{
			sum += stoi(readData[k]);
		}
		else
		{
			sumArr.push_back(sum);
			sum = 0;
			i++;
			continue;
		}
	}

	//calculate biggest sum of sums and their position in array
	//cout << "\nsumArr:\n";
	for (int k = 0; k < i; k++)
	{
		//cout << sumArr[k] << endl;
		if (sumArr[k] > maxItem)
		{
			maxItem = sumArr[k];
			maxItemPosition = k;
		}
	}
	cout << endl << "#" << maxItemPosition + 1 << " Elf is carrying the most calories: " << maxItem << endl;

	//sort array and take top 3 biggest sums
	sort(sumArr.begin(), sumArr.end());
	//cout << "\nsumArr sorted:\n";
	//for (auto x : sumArr)
	//{
	//	cout << x << endl;
	//}
	int topThree = sumArr[i - 1] + sumArr[i - 2] + sumArr[i - 3];
	cout << "\nTotal calories of top 3 Elves is: " << topThree << endl;

	return 0;
}

