#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "matrix_functions.h"
#include "matrix_calculations.h"
//#include "Camera.h"
#include "Object_3d.h"

using namespace std;

class softwareRenderer {
public:

	sf::Vector2f RES = { 1280, 720 };
	sf::Vector2f halfRES = { RES.x / 2, RES.y / 2 };
	int targetFPS = 60;
	sf::RenderWindow* window;
	sf::Clock clock;
	float deltaT;
	float fps = 60;
	softwareRenderer* render;

	softwareRenderer(sf::RenderWindow* _window) {
		window = _window;
		deltaT = clock.restart().asSeconds();
	}

	void create_objects(softwareRenderer _render) {
		std::cout << _render.RES.x << "\n";
		Object3d* obj = new Object3d(&_render);
	};

	void draw() {
		window->clear();
	}

	void run(softwareRenderer *_render) {
		render = _render;
		create_objects(*render);
		sf::Event event;
		window->setFramerateLimit(targetFPS);
		while (window->isOpen())
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();
				}
			}
			deltaT = clock.restart().asSeconds();
			fps = 1 / deltaT;
			draw();
			window->setTitle(std::to_string(fps));

		}
	}
};

