#include "stdafx.h"
#include "shape.h"
#include "polygon.h"
#include "line.h"
#include "triangel.h"
#include <iostream>
#include <string>
#include <cmath>

Shape:: ~Shape()
{
	delete[] yCord;
	yCord = nullptr;
	delete[] xCord;
	xCord = nullptr;
	
}

double Shape::area()
{
	return -1;
}	

double Shape::circumference()
{
	return -1;
}


bool Shape::isConvex()
{
	return false;
}



ShapePosition::ShapePosition(double x,double y)
{
	this->x = x;
	this->y = y;
}


Shape& Shape::operator+(const Shape &shape)
{
	if (this == &shape)
		return *this;

	int combVertices = this->nrOfPoints + shape.nrOfPoints;

	double *totalXCords = new double[combVertices];
	double *totalYCords = new double[combVertices];


	for (int i = 0; i < this->nrOfPoints; i++)
	{
		totalXCords[i] = this->xCord[i];
		totalYCords[i] = this->yCord[i];
	}


	for (int j = 0; j < shape.nrOfPoints; j++)
	{
		int index = this->nrOfPoints + j;
		totalXCords[index] = shape.xCord[j];
		totalYCords[index] = shape.yCord[j];
	}

	Shape* ShapePtr = nullptr;

	if (combVertices > 3)
		ShapePtr = new Polygon(totalXCords, totalYCords, combVertices);
	else if (combVertices == 3)
		ShapePtr = new Triangel(totalXCords, totalYCords, combVertices);
	else
		ShapePtr = new Line(totalXCords, totalYCords, combVertices);

	return *ShapePtr;
}

ostream &operator<<(std::ostream &streamobj, const Shape &shape)
{
	streamobj << "Shape vertices:" << endl;

	for (int index = 0; index < (shape.nrOfPoints); index++)
	{
		streamobj << shape.xCord[index] << "," << shape.yCord[index] << endl;
	}
	return streamobj;
}


double* Shape::getXCord()
{
	return xCord;
}
double* Shape::getYCord()
{
	return yCord;
}

int Shape::getPoints()
{
	return nrOfPoints;
}


void Shape::printCords()
{
	for (int i = 0; i < nrOfPoints / 2; i++)
	{
		cout << "(" << xCord[i] << "," << yCord[i] << ")  ";
	}
}