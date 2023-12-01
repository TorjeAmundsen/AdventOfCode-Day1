#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

static void readFileToVector(const char* filename, vector<string>& stringVector)
{
	stringVector.clear();
	ifstream file(filename);
	string line;
	while (getline(file, line))
	{
		stringVector.push_back(line);
	}
}

static int firstAndLastDigitsCombined(string input)
{
	int leftNumber;
	int rightNumber;
	for (int i = 0; i < input.size(); ++i)
	{
		int leftCharInt = input[i] - '0';
		if (leftCharInt >= 0 && leftCharInt <= 9)
		{
			leftNumber = leftCharInt * 10;
			break;
		}
	}
	for (int i = input.size() - 1; i >= 0; --i)
	{
		int rightCharInt = input[i] - '0';
		if (rightCharInt >= 0 && rightCharInt <= 9)
		{
			rightNumber = rightCharInt;
			break;
		}
	}
	return leftNumber + rightNumber;
}

static int calculatePart1(vector<string>& input)
{
	int total = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		total += firstAndLastDigitsCombined(input[i]);
	}
	return total;
}



int main()
{
	vector<string> input;
	readFileToVector("input.txt", input);
	cout << calculatePart1(input) << endl;
	return 0;
}