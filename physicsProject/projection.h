#pragma once

#include "matrix_calculations.h"
#include "physicsProject.cpp"


class Projection {
	public: 
		float NEAR;
		float FAR;
		float RIGHT;
		float LEFT;
		float TOP;
		float BOTTOM;

		float m00;
		float m11;
		float m22;
		float m32;

		vector<vector<float>> projection_matrix;

		Projection(softwareRenderer *render)
		{
			NEAR = render->camera.near_plane;
			FAR = render->camera.far_plane;
			RIGHT = tan(render->camera.h_fov / 2);
			LEFT = -RIGHT;
			TOP = tan(render->camera.v_fov / 2);
			BOTTOM = -TOP;

			m00 = 2 / (RIGHT - LEFT);
			m11 = 2 / (TOP - BOTTOM);
			m22 = (FAR + NEAR) / (FAR - NEAR);
			m32 = -2 * NEAR * FAR / (FAR - NEAR);

			projection_matrix = { {{m00,0,0,0},{0,m11,0,0},{0,0,m22,1},{0,0,m32,0},} };
		}
};