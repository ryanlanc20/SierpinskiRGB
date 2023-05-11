#include "SierpinskiGenerator.h"

SierpinskiGenerator::SierpinskiGenerator(float width, float height, std::vector<float> initialOrigin)
{
	this->width = width;
	this->height = height;
	this->initialOrigin = initialOrigin;

	// Push first origin
	std::vector<float> firstOrigin;
	firstOrigin.push_back(initialOrigin.at(0));
	firstOrigin.push_back(initialOrigin.at(1));

	this->origins.push(firstOrigin);
}

std::vector<std::vector<float>> getOrigins(float width, float height, std::vector<float> origin)
{
		std::vector<std::vector<float>> origins;

		// Top Midpoint
		std::vector<float> topMidpoint;
		topMidpoint.push_back(origin.at(0));
		topMidpoint.push_back(origin.at(1) - (height / 4));

		// Left Midpoint
		std::vector<float> leftMidpoint;
		leftMidpoint.push_back(origin.at(0) - (width / 4));
		leftMidpoint.push_back(origin.at(1) + (height / 4));

		// Right Midpoint
		std::vector<float> rightMidpoint;
		rightMidpoint.push_back(origin.at(0) + (width / 4));
		rightMidpoint.push_back(origin.at(1) + (height / 4));

		origins.push_back(topMidpoint);
		origins.push_back(leftMidpoint);
		origins.push_back(rightMidpoint);

		return origins;
}

void SierpinskiGenerator::generateTriangles(int maxDepth)
{
	int widthCpy = this->width;
	int heightCpy = this->height;

	// Stores removed triangle origins until children origins have been discovered
	std::vector<std::vector<float>> tmpOrigins;

	int currentDepth = 0;
	while (currentDepth < maxDepth)
	{
		// Important: Must be cleared at each level to prevent overlapping triangles
		tmpOrigins.clear();

		// Build triangles for current level
		while (origins.size() > 0)
		{
			// Get next origin
			std::vector<float> origin = origins.front();
			origins.pop();
			tmpOrigins.push_back(origin);
			Triangle triangle(widthCpy, heightCpy, origin);
			triangle.setColourToWhite();
			triangles.push_back(triangle);
		}

		// Get next origins
		widthCpy /= 2;
		heightCpy /= 2;

		for (std::vector<float> oldOrigin : tmpOrigins)
		{
			// Get next origins
			for (std::vector<float> newOrigin : getOrigins(widthCpy, heightCpy, oldOrigin))
			{
				origins.push(newOrigin);
				Triangle triangle(widthCpy, heightCpy, newOrigin);
				triangles.push_back(triangle);
			}
		}

		currentDepth++;
	}
}

std::vector<Triangle> SierpinskiGenerator::getTriangles()
{
	return this->triangles;
}
