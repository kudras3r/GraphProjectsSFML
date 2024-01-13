#pragma once

#include "Libs.h"

struct coords {
	float x;
	float y;
};

class Math {
	public:

		// Data
		std::vector<coords> points;
		std::vector<coords>* takeDataPointer();

		// Constructor / Destructor
		Math();
		~Math();
		
	private:
		void calculatingPoints();
};

