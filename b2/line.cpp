#include "stdafx.h"
#include "line.h"
#include <iostream>
#include <string>
#include <cmath>

Line::Line(double *xCord, double *yCord, int nrOfPoints)
{
	this->xCord = new double[nrOfPoints];
	this->yCord = new double[nrOfPoints];
	this->nrOfPoints = nrOfPoints;

	for (int i = 0; i < nrOfPoints; i++)
	{
		this->xCord[i] = xCord[i];
		this->yCord[i] = yCord[i];
	}
}

string Line::getType()
{
	string returnType = "Line";
	return returnType;
}

ShapePosition Line::position()
{
	double centerX = (xCord[0] + xCord[1]) / 2;
	double centerY = (yCord[0] + yCord[1]) / 2;

	ShapePosition linePos(centerX, centerY);
	return linePos;
}

double Line::distance(Shape &sObject)
{
	double xDistance = position().x - sObject.position().x;
	double yDistance = position().y - sObject.position().y;

	double distance = sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
	return distance;
}


Line& Line::operator=(const Line &line)
{
	if (this == &line)
	{
		return *this;
	}

	if (nrOfPoints > 0)
	{
		delete[] xCord;
		delete[] yCord;
	}
	xCord = new double[nrOfPoints];
	yCord = new double[nrOfPoints];

	for (int index = 0; index < nrOfPoints; index++)
	{
		xCord[index] = line.xCord[index];
		yCord[index] = line.yCord[index];
	}
	return *this;
}

double* Line::getXCord()
{
	return xCord;
}
double* Line::getYCord()
{
	return yCord;
}

int Line::getPoints()
{
	return nrOfPoints;
}

void Line::printCords()
{
	for (int i = 0; i < nrOfPoints / 2; i++)
	{
		cout << "(" << xCord[i] << "," << yCord[i] << ")  ";
	}

}