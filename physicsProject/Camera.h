#pragma once
#include <iostream>
#include "matrix_calculations.h"
#include "matrix_functions.h"
#include <array>
#include <SFML/Graphics.hpp>



class Camera {
	public:
		std::vector<float> pos = {0,0,0,1};
		std::vector<float> forward = { 0,0,1,1 };
		std::vector<float> up = { 0,1,0,1 };
		std::vector<float> right = {1,0,0,1};
		float h_fov = 3.1415f / 3;
		float v_fov;
		float near_plane = 0.1f;
		float far_plane = 100;
		Camera() {
			std::cout << "d";
			//v_fov = h_fov * (render->RES.y / render->RES.x);
		}

		vector<vector<float>> translate_matrix() {
			float x, y, z, w;
			x = pos[0];
			y = pos[1];
			z = pos[2];
			w = pos[3];
			vector<vector<float>> returnMatrix = { {
				{ 1,0,0,0 },
				{ 0,1,0,0 },
				{ 0,0,1,0 },
				{ -x,-y,-z,1 } } };
			return returnMatrix;
		}

		vector<vector<float>> rotate_matrix() {
			float rx, ry, rz, w;
			rx = right[0];
			ry = right[1];
			rz = right[2];
			w = right[3];
			float fx, fy, fz;
			fx = forward[0];
			fy = forward[1];
			fz = forward[2];
			float ux, uy, uz;
			ux = up[0];
			uy = up[1];
			uz = up[2];
			vector<vector<float>> returnMatrix = { {
				{ rx,ux,fx,0 },
				{ ry,uy,fy,0 },
				{ rz,uz,fz,0 },
				{ 0,0,0,1 } } };
			return returnMatrix;
		}


		vector<vector<float>> camera_matrix() {
			return matrixMult(translate_matrix(), rotate_matrix());
		}
};