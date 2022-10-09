#include <SFML/Graphics.hpp>
#include "softwareRenderer.h"
#include <iostream>
#include "matrix_functions.h"
#include "matrix_calculations.h"
#include "Object_3d.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "", sf::Style::Default);
	softwareRenderer engine(&window);
	engine.run(&engine);
	return 0;
}