#pragma once
#include "matrix_functions.h"
#include "matrix_calculations.h"
#include <iostream>


using namespace std;
class softwareRenderer;

class Object3d {
public:
	vector<vector<float>> vertices;
	vector<vector<float>> faces;

	Object3d(softwareRenderer *_render) {
		std::cout << &_render;
		vertices = { {{0,0,0,1},{0,1,0,1},{1,1,0,1},{1,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1},{1,0,1,1}} };
		faces = { {{0,1,2,3},{4,5,6,7},{0,4,5,1},{2,3,7,6},{1,2,6,5},{0,3,7,4}} };
	}

	void screen_projection() {
		//vertices = matrixMult(vertices, render->camera.camera_matrix());
	}

	void translate(sf::Vector3f t) {
		vertices = matrixMult(vertices, translateMatrix(t));
	}

	void scale(float scale_to) {
		vertices = matrixMult(vertices, scaleMatrix(scale_to));
	}

	void rotate_x(float deg) {
		vertices = matrixMult(vertices, rotate_xMatrix(deg));
	}

	void rotate_y(float deg) {
		vertices = matrixMult(vertices, rotate_yMatrix(deg));
	}

	void rotate_z(float deg) {
		vertices = matrixMult(vertices, rotate_zMatrix(deg));
	}

};

