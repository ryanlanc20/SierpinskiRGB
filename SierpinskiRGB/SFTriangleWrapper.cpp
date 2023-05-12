#include "Point2d.h"
#include "SFTriangleWrapper.h"

SFTriangleWrapper::SFTriangleWrapper(Triangle triangle)
{
	// Initialize vertex array for triangle
	this->vertices = sf::VertexArray(sf::Triangles, 3);

	// Add vertices to array
	std::vector<Point2d> points = triangle.getPoints();
	this->vertices[0].position = sf::Vector2f(points.at(0).getX(), points.at(0).getY());
	this->vertices[1].position = sf::Vector2f(points.at(1).getX(), points.at(1).getY());
	this->vertices[2].position = sf::Vector2f(points.at(2).getX(), points.at(2).getY());

	if (triangle.getColour() == "white")
	{
		// Foreground colouring
		sf::Color randomColour(rand() % 255, rand() % 255, rand() % 255);
		this->vertices[0].color = randomColour;
		this->vertices[1].color = randomColour;
		this->vertices[2].color = randomColour;
	}
	else
	{
		// Background colouring
		this->vertices[0].color = sf::Color::Black;
		this->vertices[1].color = sf::Color::Black;
		this->vertices[2].color = sf::Color::Black;
	}
}

sf::VertexArray SFTriangleWrapper::getVertexArray()
{
	return this->vertices;
}
