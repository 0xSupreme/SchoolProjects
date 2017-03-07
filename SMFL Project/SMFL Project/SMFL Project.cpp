// SMFL Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
	// Main Screen
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	// Settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

	// Ints
	int shapeSides;

	// Bools
	bool validShapeSides = true;
	bool runProgram = false;

	do{
		while (window.isOpen())
		{
			do{
				cout << "Please enter how many side for a shape: ";
				cin >> shapeSides;
				if (shapeSides <= 2 && shapeSides >=8)
				{
					cout << "Not Valid Try Again!" << endl;
					validShapeSides = false;
				}
				else
				{
					validShapeSides = true;
					runProgram = true;
				}
				sf::CircleShape shape(80, shapeSides);
				shape.setFillColor(sf::Color::Green);
			} while (validShapeSides == false);
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			sf::CircleShape shape(80, shapeSides);
			shape.setFillColor(sf::Color::Blue);

			window.clear();
			window.draw(shape);
			window.display();
		}
	} while (runProgram == true);
	return 0;
}
