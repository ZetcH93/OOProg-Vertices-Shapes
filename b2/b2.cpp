#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include "shape.h"
#include "line.h"
#include "point.h"
#include "polygon.h"
#include "triangel.h"
#include "getShape.h"
#include "figure.h"



using namespace std;


int main(int argc, const char * argv[])
{


	int nrOfShapes = 0;
	Shape** shapes = new Shape*[nrOfShapes];


	ifstream myReadFile;
	myReadFile.open("vertices.txt");

	if (myReadFile)
	{
		string line;
		getline(myReadFile, line);

		while (!(line.empty()))
		{


			Shape** tempArr = new Shape*[nrOfShapes + 1];
			for (int i = 0; i < nrOfShapes; i++)
			{
				tempArr[i] = shapes[i];
			}
			delete[] shapes;
			shapes = tempArr;
			tempArr = nullptr;


			shapes[nrOfShapes] = &defineShapes(line);
			line.clear();
			getline(myReadFile, line);
			nrOfShapes++;
		}

		myReadFile.close();
	}
	else
	{
		cout << "Could not open file. \n";
		exit(EXIT_FAILURE);
	}

	Figure figure(shapes, nrOfShapes);

	figure.getClosest(*shapes[2], 3);

	figure.getFigures();

	figure.addShape();

	figure.getFigures();








	return 0;
}


