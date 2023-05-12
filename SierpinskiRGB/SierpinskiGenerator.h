#pragma once
#include "Triangle.h"
#include "Point2d.h"
#include <vector>
#include <queue>

class SierpinskiGenerator
{
public:
	SierpinskiGenerator(float width, float height, float originX, float originY);
	void generateTriangles(int maxDepth);
	std::vector<Triangle> getTriangles();

private:
	float width;
	float height;
	std::queue<Point2d> origins;
	std::vector<Triangle> triangles;
};

