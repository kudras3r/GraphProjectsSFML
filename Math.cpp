#include "Math.h"
#include "Libs.h"


Math::~Math() {

	delete[] &this->points;

}

std::vector<coords>* Math::takeDataPointer() {

	return &this->points;

}

void Math::calculatingPoints(std::string expression) {

	this->points.clear();

	coords point = { 0, 0 };
	
	for (float x = -100.f; x < 100.f; x += this->quality) {  // TODO

		point.x = x;
		point.y = calc(expression, x);

		this->points.push_back(point);

	}
	// DEBUG (cout coords)
	for (auto p : this->points) {

		std::cout << p.x << " " << p.y << '\n';

	}

}