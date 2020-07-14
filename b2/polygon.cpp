#include "stdafx.h"
#include "polygon.h"
#include <iostream>
#include <string>
#include <cmath>


Polygon::Polygon(double *xCord, double *yCord, int nrOfPoints)
{
	this->xCord = new double[nrOfPoints/2];
	this->yCord = new double[nrOfPoints/2];
	this->nrOfPoints = nrOfPoints;

	for (int i = 0; i < nrOfPoints/2; i++)
	{
		this->xCord[i] = xCord[i];
		this->yCord[i] = yCord[i];
	}

}

bool Polygon::isConvex()
{
	int size = (nrOfPoints - 2);
	double *crossPrd = new double[size];
	double difInx1, difIny1, difInx2, difIny2;


	for (int i = 0; i < size; i++)
	{
		difInx1 = xCord[i + 1] - xCord[i];
		difIny1 = yCord[i + 1] - yCord[i];
		difInx2 = xCord[i + 2] - xCord[i + 1];
		difIny2 = yCord[i + 2] - yCord[i + 1];
		crossPrd[i] = (difInx1 * difIny2 - difIny1 * difInx2);
	}

	bool postiveFound = false;
	bool negativeFound = false;


	for (int i = 0; i < size; i++)
	{
		if (crossPrd[i] > 0)
			postiveFound = true;
		else
			negativeFound = true;
	}

	delete[] crossPrd;
	crossPrd = nullptr;

	if (postiveFound && negativeFound)
		return false;
	else
		return true;
}


string Polygon::getType()
{
	string returnType = "Polygon";
	return returnType;
}
double Polygon::area()
{
	double area = 0.0; 

	if (isConvex() == true)
	{
		int j = nrOfPoints - 1;  

		for (int i = 0; i < nrOfPoints; i++)
		{
			area += (xCord[j] + xCord[i]) * (yCord[j] - yCord[i]);
			j = i;
		}
		area = abs(area / 2.0);
	}
	else
		area = -1.0;

	return area;
}
double Polygon::circumference()
{
	double circumference = 0.0; 
	double distanceInX;
	double distanceInY;
	double distance;

	for (int i = 0; i < (nrOfPoints - 1); i++)
	{
		distanceInX = pow(xCord[i] - xCord[i + 1], 2);
		distanceInY = pow(yCord[i] - yCord[i + 1], 2);
		distance = sqrt(distanceInX + distanceInY);
		circumference += distance;
	}
	return circumference;
}

ShapePosition Polygon::position()
{
	{
		double totalCenterX = 0.0;
		double totalCenterY = 0.0;

		for (int i = 0; i < (nrOfPoints /2); i++)
		{
			totalCenterX += xCord[i];
			totalCenterY += yCord[i];
		}

		double x = (totalCenterX / (nrOfPoints /2));
		double y = (totalCenterY / (nrOfPoints /2));
		ShapePosition position(x,y);
		
		return position;
	}

}


double Polygon::distance(Shape &sObject)
{
	double xDistance = position().x - sObject.position().x;
	double yDistance = position().y - sObject.position().y;

	double distance = sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
	return distance;
}



Polygon& Polygon::operator=(const Polygon &polygon)
{
	if (this == &polygon)
	{
		return *this;
	}
	if (nrOfPoints > 0)
	{
		delete[] xCord;
		delete[] yCord;
	}
	nrOfPoints = polygon.nrOfPoints;
	xCord = new double[nrOfPoints];
	yCord = new double[nrOfPoints];

	for (int index = 0; index < nrOfPoints; index++)
	{
		xCord[index] = polygon.xCord[index];
		yCord[index] = polygon.yCord[index];
	}
	return *this;
}

double* Polygon::getXCord()
{
	return xCord;
}
double* Polygon::getYCord()
{
	return yCord;
}

int Polygon::getPoints()
{
	return nrOfPoints;
}


void Polygon::printCords()
{
	for (int i = 0; i < nrOfPoints / 2; i++)
	{
		cout << "(" << xCord[i] << "," << yCord[i] << ")  ";
	}
}