#pragma once
#include "Triangle.h"
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
	std::queue<std::vector<float>> origins;
	std::vector<Triangle> triangles;
};

