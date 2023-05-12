#include "SierpinskiGenerator.h"
#include "Point2d.h"

SierpinskiGenerator::SierpinskiGenerator(float width, float height, float originX, float originY)
{
	this->width = width;
	this->height = height;

	// Push first origin
	this->origins.push(Point2d(originX, originY));
}

std::vector<Point2d> getOrigins(float width, float height, Point2d origin)
{
	std::vector<Point2d> origins;

	// Top midpoint
	origins.push_back(Point2d(origin.getX(), origin.getY() - (height / 4)));

	// Left midpoint
	origins.push_back(Point2d(origin.getX() - (width / 4), origin.getY() + (height / 4)));

	// Right midpoint
	origins.push_back(Point2d(origin.getX() + (width / 4), origin.getY() + (height / 4)));

	return origins;
}

void SierpinskiGenerator::generateTriangles(int maxDepth)
{
	int widthCpy = this->width;
	int heightCpy = this->height;

	// Stores removed triangle origins until child origins have been discovered
	std::vector<Point2d> tmpOrigins;

	int currentDepth = 0;
	while (currentDepth < maxDepth)
	{
		// Important: Must be cleared at each level to prevent overlapping triangles
		tmpOrigins.clear();

		// Build triangles for current level
		while (this->origins.size() > 0)
		{
			// Get next origin
			Point2d origin = this->origins.front();
			this->origins.pop();
			tmpOrigins.push_back(origin);
			Triangle triangle(widthCpy, heightCpy, origin);
			triangle.setColourToWhite();
			this->triangles.push_back(triangle);
		}

		// Get next origins
		widthCpy /= 2;
		heightCpy /= 2;

		for (Point2d parentOrigin : tmpOrigins)
		{
			// Get next origins
			for (Point2d childOrigin : getOrigins(widthCpy, heightCpy, parentOrigin))
			{
				this->origins.push(childOrigin);
				Triangle triangle(widthCpy, heightCpy, childOrigin);
				this->triangles.push_back(triangle);
			}
		}

		currentDepth++;
	}
}

std::vector<Triangle> SierpinskiGenerator::getTriangles()
{
	return this->triangles;
}
