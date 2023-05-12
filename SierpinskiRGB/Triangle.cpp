#include "Triangle.h"
#include "Point2d.h"
#include <iostream>
#include <vector>

Triangle::Triangle(float height, float width, Point2d origin)
{
	Point2d bottomLeft(origin.getX() - (width / 4), origin.getY() + (height / 4));
	Point2d bottomRight(origin.getX() + (width / 4), origin.getY() + (height / 4));
	Point2d top(origin.getX(), origin.getY() - (height / 4));

	this->points.push_back(bottomLeft);
	this->points.push_back(bottomRight);
	this->points.push_back(top);
}

std::vector<Point2d> Triangle::getPoints()
{
	return this->points;
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