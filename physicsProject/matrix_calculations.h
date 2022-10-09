#pragma once
#include <iostream>
#include <array>
#include <vector>

using namespace std;

vector<vector<float>> matrixMult(vector<vector<float>> A, vector<vector<float>> B) {
	
	vector<vector<float>> returnMatrix;


	for (int i = 0; i < B[0].size(); i++)
	{
		returnMatrix.push_back({});
		for (int j = 0; j < B[0].size(); j++)
		{
			returnMatrix[i].push_back({});
		}
	}
	


	for (int i = 0; i < B[0].size(); i++)
	{
		for (int j = 0; j < B[0].size(); j++)
		{
			returnMatrix[i][j] = 0;
			for (int k = 0;  k < A[0].size();  k++)
			{
				returnMatrix[i][j] += A[i][k] * B[k][j];
			}
		}

	}

	// Prints matrix
	
	//for (int i = 0; i < returnMatrix.size(); i++)
	//{
	//	for (int j = 0; j < returnMatrix[0].size(); j++)
	//	{
	//		std::cout << "\t" << returnMatrix[i][j];
	//	}
	//	std::cout << "\n";
	//}


	return returnMatrix;
}