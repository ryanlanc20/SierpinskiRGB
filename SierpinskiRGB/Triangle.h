#pragma once
#include "Point2d.h"
#include <iostream>
#include <vector>

class Triangle
{
public:
	Triangle(float height, float width, Point2d position);
	std::vector<Point2d> getPoints();
	void setColourToBlack();
	void setColourToWhite();
	std::string getColour();

private:
	std::vector<Point2d> points;
	std::string colour;
};

