#pragma once
#include "stdafx.h"
#include "shape.h"



class Figure
{
	Shape **shapePtr = nullptr;
	int nrOfShapes;
	double *arrOfDistances = nullptr;

public:
	~Figure();
	Figure(Shape**, int nrShapes);
	void getFigures();
	void addShape();
	void getBoundingBox();
	void getClosest(Shape &shape, int n);
	void selectSortDistanceFigure(double arrDistance[], int min);

};