#include "Math.h"
#include "Libs.h"

Math::Math(const int* width, const int* heigh) {
	this->defCoords.x = *width;
	this->defCoords.y = *heigh;
	this->calculatingPoints();
}

Math::~Math() {
	delete &this->points;
}

std::vector<coords>* Math::takeDataPointer() {
	return &this->points;
}

void Math::calculatingPoints() {
	coords point = { 0, 0 };
	float x = 0;
	float y = x;  // in the future here will be another functions
	for (float x = -10; x < 10; x += 0.1f) {
		point.x = x;
		point.y = x;
		this->points.push_back(point);
	}
}
