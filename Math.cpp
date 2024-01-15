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
	
	for (float x = -10; x < 10; x += 0.1f) {

		point.x = x;
		point.y = calc(expression, x);

		this->points.push_back(point);
	}
	// DEBUG
	for (auto p : this->points) {
		std::cout << p.x << " " << p.y << '\n';
	}
}