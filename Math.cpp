#include "Math.h"
#include "Libs.h"

Math::Math() {
	this->calculatingPoints();
}

Math::~Math() {
	delete[] & this->points;
}

std::vector<coords>* Math::takeDataPointer() {
	return &this->points;
}

void Math::calculatingPoints() {
	coords point = { 0, 0 };
	//coords point1 = { 0,0 };
	float x = 0;
	float y = x*x;  // in the future here will be another functions

	for (float x = -10; x < 10; x += 0.1f) {
		point.x = x;
		point.y = cos(x) + 2*sin(x) - x*x;

		//point1.x = x;
		//point1.y = pow(1 - (abs(x) - 1) * (abs(x) - 1), (1.f / 2));
		//this->points.push_back(point1);

		this->points.push_back(point);
	}
}
