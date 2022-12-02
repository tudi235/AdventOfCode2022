#include <iostream>
#include <fstream>

using namespace std;

#define A 1; //rock
#define B 2; //paper
#define C 3; //scissors
#define X 1; //rock
#define Y 2; //paper
#define Z 3; //scissors
#define LOST 0;
#define DRAW 3;
#define WIN 6;

//function to determine who won the current round
int partOne(char opponent, char me)
{
	int result = 0;
	if (((opponent == 'A') && (me == 'X')) || ((opponent == 'B') && (me == 'Y')) || ((opponent == 'C') && (me == 'Z')))
	{
		result = DRAW;
	}
	if (((opponent == 'A') && (me == 'Y')) || ((opponent == 'B') && (me == 'Z')) || ((opponent == 'C') && (me == 'X')))
	{
		result = WIN;
	}
	if (((opponent == 'A') && (me == 'Z')) || ((opponent == 'B') && (me == 'X')) || ((opponent == 'C') && (me == 'Y')))
	{
		result = LOST;
	}

	switch (me) {
	case 'X':
		result += X;
		break;
	case 'Y':
		result += Y;
		break;
	case 'Z':
		result += Z;
		break;
	}
	//cout << "\nResult: " << result << endl;
	return result;
}

//function to determine what shape to use
int partTwo(char opponent, char outcome)
{
	int result = 0, shape = 0;
	if (((opponent == 'A') && (outcome == 'Y')) || ((opponent == 'B') && (outcome == 'X')) || ((opponent == 'C') && (outcome == 'Z')))
	{
		shape = X;
	}
	if (((opponent == 'A') && (outcome == 'Z')) || ((opponent == 'B') && (outcome == 'Y')) || ((opponent == 'C') && (outcome == 'X')))
	{
		shape = Y;
	}
	if (((opponent == 'A') && (outcome == 'X')) || ((opponent == 'B') && (outcome == 'Z')) || ((opponent == 'C') && (outcome == 'Y')))
	{
		shape = Z;
	}
	result += shape;
	switch (outcome) {
	case 'X':
		result += LOST;
		break;
	case 'Y':
		result += DRAW;
		break;
	case 'Z':
		result += WIN;
		break;
	}
	//cout << "\nResult: " << result << endl;
	return result;
}

int main()
{
	cout << "Welcome to Advent of Code 2022 - Day 2\n\n";
	ifstream input("input.txt");
	int score = 0;
	char opponentMove, myMove;
	if (input.is_open())
	{
		while (input >> opponentMove >> myMove)
		{
			cout << endl << opponentMove << myMove << endl;
			//score += partOne(opponentMove, myMove);
			score += partTwo(opponentMove, myMove);
		}
		cout << "\nScore is: " << score << endl;
	}
}