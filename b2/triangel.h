#pragma once
#include "stdafx.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>



class Triangel : public Shape
{
	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;


public:

	double* getXCord() override;
	double* getYCord() override;
	int getPoints() override;
	
	void printCords() override;
	Triangel(double *xCord, double *yCord, int nrOfPoints);
	string getType() override;
	double area() override;
	double circumference() override;
	ShapePosition position() override;
	bool isConvex() override;
	double distance(Shape &sObject) override;
	Triangel& operator=(const Triangel& triangle);

};