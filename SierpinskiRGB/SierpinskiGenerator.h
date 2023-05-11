#pragma once
#include "Triangle.h"
#include <vector>
#include <queue>

class SierpinskiGenerator
{
public:
	SierpinskiGenerator(float width, float height, std::vector<float> initialOrigin);
	void generateTriangles(int maxDepth);
	std::vector<Triangle> getTriangles();

private:
	float width;
	float height;
	std::vector<float> initialOrigin;
	std::queue<std::vector<float>> origins;
	std::vector<Triangle> triangles;
};

