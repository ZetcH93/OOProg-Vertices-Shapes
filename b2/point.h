#pragma once
#include "stdafx.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>

class Point : public Shape
{

	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;



public:

	double* getXCord() override;
	double* getYCord() override;
	int getPoints() override;
	void printCords() override;
	Point(double *xCord, double *yCord, int nrOfPoints);
	string getType() override;
	
	ShapePosition position() override;
	double distance(Shape &sObject) override;
	Point& operator=(const Point& point);

};