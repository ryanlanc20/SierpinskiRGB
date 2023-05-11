#pragma once
#include "Triangle.h"
#include <SFML\Graphics.hpp>

class SFTriangleWrapper
{
public:
	SFTriangleWrapper(Triangle triangle);
	sf::VertexArray getVertexArray();

private:
	sf::VertexArray vertices;
};

