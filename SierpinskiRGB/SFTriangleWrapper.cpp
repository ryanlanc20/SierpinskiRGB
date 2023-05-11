#include "SFTriangleWrapper.h"

SFTriangleWrapper::SFTriangleWrapper(Triangle triangle)
{
	// Initialize vertex array for triangle
	vertices = sf::VertexArray(sf::Triangles, 3);

	// Add vertices to array
	std::vector<std::vector<float>> points = triangle.getPoints();
	vertices[0].position = sf::Vector2f(points.at(0).at(0), points.at(0).at(1));
	vertices[1].position = sf::Vector2f(points.at(1).at(0), points.at(1).at(1));
	vertices[2].position = sf::Vector2f(points.at(2).at(0), points.at(2).at(1));

	if (triangle.getColour() == "white")
	{
		// Foreground colouring
		sf::Color randomColour(rand() % 255, rand() % 255, rand() % 255);
		vertices[0].color = randomColour;
		vertices[1].color = randomColour;
		vertices[2].color = randomColour;
	}
	else
	{
		// Background colouring
		vertices[0].color = sf::Color::Black;
		vertices[1].color = sf::Color::Black;
		vertices[2].color = sf::Color::Black;
	}
}

sf::VertexArray SFTriangleWrapper::getVertexArray()
{
	return vertices;
}
