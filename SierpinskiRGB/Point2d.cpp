#include "Point2d.h"

Point2d::Point2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point2d::getX()
{
	return this->x;
}

float Point2d::getY()
{
	return this->y;
}
