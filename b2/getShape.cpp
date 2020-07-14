#include "stdafx.h"
#include "getShape.h"
#include <sstream>


Shape& getShape(int nrOfCords, double *xCord, double *yCord)
{
	Shape* shape = nullptr;
	

	if (nrOfCords > 6)
	{
		shape = new Polygon(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 6)
	{
		shape = new Triangel(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 4)
	{
		shape = new Line(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 2)
	{
		shape = new Point(xCord, yCord, nrOfCords);
	}
	return *shape;
}



Shape &defineShapes(string line)
{
	int nrOfcords = 0;
	double value = 0;
	double *newShape = new double[nrOfcords];


	istringstream iss(line);

	while (iss >> value)
	{
		nrOfcords++;

			double *tempArray = new double[nrOfcords];
			for (int i = 0; i < nrOfcords; i++)
			{
				tempArray[i] = newShape[i];
			}
		
			delete[] newShape;
			newShape = tempArray;
			tempArray = nullptr;

			newShape[nrOfcords - 1] = value;
	}

	double *xCord1 = new double[nrOfcords / 2];
	double *yCord1 = new double[nrOfcords / 2];


	for (int i = 0; i < nrOfcords; i++)
	{
		int cordIndex = (i / 2);
		if (i % 2 == 0)
			xCord1[cordIndex] = newShape[i];
		else
			yCord1[cordIndex] = newShape[i];
	}

	if (nrOfcords == 0 || nrOfcords % 2 == 1)
	{
		cout << "That is not a shape.." << endl;
		exit(EXIT_FAILURE);
	}

	if (nrOfcords == 0 || nrOfcords % 2 == 1)
	{
		cout << "That is not a shape.." << endl;
		exit(EXIT_FAILURE);
	}


	Shape &shape = getShape(nrOfcords, xCord1, yCord1);

	return shape;
}