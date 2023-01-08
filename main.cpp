#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include <vector>
using namespace std;

int main()
{
	vector<Rectangle*> rectangles;

	ifstream inputFile;
	ofstream outputFile;

	inputFile.open("rectangle.txt");
	outputFile.open("output.txt");

	if (!inputFile)
	{
		cout << "Error opening file. Bailing out..." << endl;
		return 1;
	}

	int width;
	int height;

	while (!inputFile.eof())
	{
		inputFile >> width;
		inputFile >> height;
		rectangles.push_back(new Rectangle(width, height));
	}

	for (Rectangle* rectPtr : rectangles)
	{
		outputFile << (*rectPtr).area() << "\t" << (*rectPtr).perimeter() << endl;
	}

	for (Rectangle* rectPtr : rectangles)
	{
		delete rectPtr;
	}

	rectangles.clear();

	inputFile.close();
	outputFile.close();

	return 0;
}