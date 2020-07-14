#include "stdafx.h"
#include "triangel.h"
#include <iostream>
#include <string>
#include <cmath>


Triangel::Triangel(double *xCord, double *yCord, int nrOfPoints)
{

	this->xCord = new double[nrOfPoints];
	this->yCord = new double[nrOfPoints];
	this->nrOfPoints = nrOfPoints;

	for (int i = 0; i <nrOfPoints; i++)
	{
		this->xCord[i] = xCord[i];
		this->yCord[i] = yCord[i];
	}
		
	
}

string Triangel::getType()
{
	string returnType = "Triangle";
	return returnType;
}

double Triangel::area()
{
	double area = std::abs((xCord[0] * (yCord[1] - yCord[2]) + xCord[1] * (yCord[2] - yCord[0]) + xCord[2] * (yCord[0] - yCord[1])) / 2.0);
	
	return area;
}
double Triangel::circumference()
{
	double x1tox2 = pow(xCord[0] - xCord[1], 2);
	double y1toy2 = pow(yCord[0] - yCord[1], 2);
	double length1 = sqrt(x1tox2 + y1toy2);

	double x2to3 = pow(xCord[1] - xCord[2], 2);
	double y2toy3 = pow(yCord[1] - yCord[2], 2);
	double length2 = sqrt(x2to3 + y2toy3);

	double x3tox1 = pow(xCord[2] - xCord[0], 2);
	double y3toy1 = pow(yCord[2] - yCord[0], 2);
	double length3 = sqrt(x3tox1 + y3toy1);

	double circumference = length1 + length2 + length3;

	return circumference;

}

bool Triangel::isConvex()
{
	return true;
}

ShapePosition Triangel::position()
{
	double centerX = (xCord[0] + xCord[1] + xCord[2]) / 3;
	double centerY = (yCord[0] + yCord[1] + yCord[2]) / 3;

	ShapePosition triangelPos(centerX, centerY);
	return triangelPos;
	
}

double Triangel::distance(Shape &sObject)
{
	double xDistance = position().x - sObject.position().x;
	double yDistance = position().y - sObject.position().y;
	
	double distance = sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
	return distance;

}

Triangel& Triangel::operator=(const Triangel &triangle)
{
	if (this == &triangle)
	{
		return *this;
	}
	if (nrOfPoints > 0)
	{
		delete[] xCord;
		delete[] yCord;
	}
	nrOfPoints = triangle.nrOfPoints;
	xCord = new double[nrOfPoints];
	yCord = new double[nrOfPoints];

	for (int index = 0; index < nrOfPoints; index++)
	{
		xCord[index] = triangle.xCord[index];
		yCord[index] = triangle.yCord[index];
	}
	return *this;

}


double* Triangel::getXCord()
{
	return xCord;
}
double* Triangel::getYCord()
{
	return yCord;
}

int Triangel::getPoints()
{
	return nrOfPoints;
}


void Triangel::printCords()
{
	for (int i = 0; i < nrOfPoints/2; i++)
	{
		cout << "(" << xCord[i] << "," << yCord[i] << ")  ";
	}
}