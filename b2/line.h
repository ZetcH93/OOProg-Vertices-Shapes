#pragma once
#include "stdafx.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <cmath>



class Line : public Shape
{

	double *xCord = nullptr;
	double *yCord = nullptr;
	int nrOfPoints = 0;


public:


	double* getXCord() override;
	double* getYCord() override;
	int getPoints() override;
	void printCords() override;


	Line(double *xCord, double *yCord, int nrOfPoints);
	string getType() override;

	ShapePosition position() override;
	double distance(Shape &sObject) override;
	Line& operator=(const Line& line);
	
};