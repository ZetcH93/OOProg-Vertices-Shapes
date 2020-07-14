#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "polygon.h"
#include "triangel.h"
#include "line.h"
#include "point.h"


Shape &getShape(int nrOfCords, double *xCord, double *yCord);
Shape &defineShapes(string line);