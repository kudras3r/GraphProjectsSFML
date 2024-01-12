#pragma once

#include "Libs.h"

struct defaultCoords {
	int x;
	int y;
};

struct coords {
	float x;
	float y;
};

class Math {
	public:
		// Coords
		defaultCoords defCoords = { 0, 0 };

		// Data
		std::vector<coords> points;

		// Constructor / Destructor
		Math(const int* width, const int* heigh);
		~Math();


		std::vector<coords>* takeDataPointer();
		
	private:
		void calculatingPoints();
};

