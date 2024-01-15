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

		// Constructor / Destructor
		
		
		//Math();
		~Math();

		// Methods
		void calculatingPoints(std::string expression);
		
};

