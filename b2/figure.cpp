#include "stdafx.h"
#include "figure.h"
#include "getShape.h"
#include <iostream>



Figure::Figure(Shape** Sh, int nrShapes)
{
	this->nrOfShapes = nrShapes;
	this->shapePtr = Sh;
}

Figure::~Figure()
{
	delete[] shapePtr;
	shapePtr = nullptr;
}


void Figure::addShape()
{
	string line;
	cout << "Enter a shape value: ";
	getline(cin, line);


	Shape** tempArr = new Shape*[nrOfShapes+1];
	for (int i = 0; i < nrOfShapes; i++)
	{
		tempArr[i] = shapePtr[i];
	}

	delete[] shapePtr;
	shapePtr = tempArr;
	tempArr = nullptr;

	this->shapePtr[nrOfShapes] = &defineShapes(line);
	this->nrOfShapes++;
	
}

void Figure::getBoundingBox()
{
	double bigX = shapePtr[0]->getXCord()[0], bigY = shapePtr[0]->getYCord()[0], smallX = shapePtr[0]->getXCord()[0], smallY = shapePtr[0]->getXCord()[0];
	for (int j = 0; j < nrOfShapes; j++)
	{
		for (int i = 0; i < (shapePtr[j]->getPoints())/2; i++)
		{
			if (shapePtr[j]->getXCord()[i] > bigX)
			{
				bigX = shapePtr[j]->getXCord()[i];
			}
			if (shapePtr[j]->getYCord()[i] > bigY)
			{
				bigY = shapePtr[j]->getYCord()[i];
			}
			if (shapePtr[j]->getXCord()[i] < smallX)
			{
				smallX = shapePtr[j]->getXCord()[i];
			}
			if (shapePtr[j]->getYCord()[i] < smallY)
			{
				smallY = shapePtr[j]->getYCord()[i];
			}
		}
	}

	cout << "Top-Left coords: (" << smallX << "," << bigY << ") , Bottom-Right coords: (" << bigX << "," << smallY << ")" << endl;
}

void Figure::getClosest(Shape &shape, int n)
{
	int counter = 0;
	arrOfDistances = new double[nrOfShapes];

	for (int i = 0; i < nrOfShapes; i++)
	{
		double distanceToLocation = shape.distance(*shapePtr[i]);
		arrOfDistances[i] = distanceToLocation;

	}
	selectSortDistanceFigure(arrOfDistances, 0);


	cout << "The " << n << " closests shapes to (" << shape.position().x <<","<< shape.position().y << ") is : " << endl;
	for (int i = 0; i < nrOfShapes; i++)
	{
		for (int j = 0; j < nrOfShapes; j++)
		{
			if ((shape.distance(*shapePtr[j]) == arrOfDistances[i]) && (counter < n))
			{
				if ((shape.position().x == shapePtr[j]->position().x) && (shape.position().y == shapePtr[j]->position().y))
				{

				}
				else
				{
					counter++;
					cout <<counter<<": "<<shapePtr[j]->getType() << ": (" << shapePtr[j]->position().x << "," << shapePtr[j]->position().y << ") " << endl;
					
				}
			}
		}
	}
	
	delete[] arrOfDistances;
	arrOfDistances = nullptr;
}

void Figure::selectSortDistanceFigure(double arrDistances[], int min)
{
		int smallest = min;

		if (min == nrOfShapes - 1)		
			return;

		for (int i = min + 1; i < nrOfShapes; i++)
		{
			if (arrDistances[smallest] > arrDistances[i])
			{
				smallest = i;
			}
		}

		double temp = arrDistances[min];
		arrDistances[min] = arrDistances[smallest];			
		arrDistances[smallest] = temp;
		

		selectSortDistanceFigure(arrDistances, (min + 1));

}


void Figure::getFigures()
{
	
	cout << "\nAll the shapes in the figure: \n";
	for (int i = 0; i < nrOfShapes; i++)
	{
		cout << shapePtr[i]->getType();
		cout << ":  ";
		shapePtr[i]->printCords();
		cout << endl;
	}
}


