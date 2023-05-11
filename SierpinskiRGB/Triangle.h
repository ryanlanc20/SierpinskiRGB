#pragma once
#include <iostream>
#include <vector>

class Triangle
{
public:
	Triangle(float height, float width, std::vector<float> position);
	std::vector<std::vector<float>> getPoints();
	void setColourToBlack();
	void setColourToWhite();
	std::string getColour();

private:
	std::vector<std::vector<float>> points;
	std::string colour;
};

