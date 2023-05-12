// SierpinskiRGB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML\Graphics.hpp>
#include "SierpinskiGenerator.h"
#include "Triangle.h"
#include "SFTriangleWrapper.h"

int main()
{
	// Generate triangles
	SierpinskiGenerator generator(1024, 1024, 500, 300);
	generator.generateTriangles(10);
	std::vector<Triangle> triangles = generator.getTriangles();

	// Convert triangles to SFML triangles (returns Vertex Arrays)
	std::vector<sf::VertexArray> drawableTriangles;

	for (Triangle triangle : triangles)
	{
		drawableTriangles.push_back(SFTriangleWrapper(triangle).getVertexArray());
	}

	// Window setup
	sf::VideoMode vm(1024, 600);
	sf::RenderWindow window(vm, "Sierpinski generator");
	window.setFramerateLimit(30);

	// Draw SierpinskiRGB on screen
	while (window.isOpen())
	{
		// Handle events
		sf::Event currentEvent;
		while (window.pollEvent(currentEvent))
		{
			if (currentEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		
		// Let's draw the triangles
		window.clear(sf::Color::White);
		for (sf::VertexArray triangle : drawableTriangles)
		{
			window.draw(triangle);
		}

		window.display();
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
