#pragma once

#include "Libs.h"
#include "Parser.h"

struct coords {
	float x;
	float y;
};

class Math {

	public:

		// Data
		std::vector<coords> points;
		std::vector<coords>* takeDataPointer();

		// Destructor
		~Math();

		// Methods
		void calculatingPoints(std::string expression);

	public:

		const float quality = 0.01f;  // !!! < 0.0001 IS BAD !!!
		
};

