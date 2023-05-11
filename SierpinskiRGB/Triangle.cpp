#include "Triangle.h"
#include <iostream>
#include <vector>
Triangle::Triangle(float height, float width, std::vector<float> origin)
{
	std::vector<float> bottomLeft;
	bottomLeft.push_back(origin.at(0) - (width / 4));
	bottomLeft.push_back(origin.at(1) + (height / 4));

	std::vector<float> bottomRight;
	bottomRight.push_back(origin.at(0) + (width / 4));
	bottomRight.push_back(origin.at(1) + (height / 4));

	std::vector<float> top;
	top.push_back(origin.at(0));
	top.push_back(origin.at(1) - (height / 4));

	points.push_back(bottomLeft);
	points.push_back(bottomRight);
	points.push_back(top);
}

std::vector<std::vector<float>> Triangle::getPoints()
{
	return points;
}

void Triangle::setColourToWhite()
{
	this->colour = "white";
}

void Triangle::setColourToBlack()
{
	this->colour = "black";
}

std::string Triangle::getColour()
{
	return this->colour;
}