#include "Window.h"

Window::Window() {
	this->initWindow();
}

Window::~Window() {
	delete this->window;
}

bool Window::open() {
	return this->window->isOpen();
}

void Window::renderWindow() {
	this->window->clear();
	this->drawAll();
	this->window->display();
}

void Window::drawPoints() {
	for (coords point : *this->coordsDataP) {
		std::cout << point.x << " " << point.y << "\n";
		sf::CircleShape sfPoint(5.f);
		sfPoint.setPosition(point.x * 20, point.y * 20);
		sfPoint.setFillColor(sf::Color::White);
		this->window->draw(sfPoint);
	}
}

void Window::drawAll() {
	this->drawPoints();
}

void Window::updateWindow() {
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Window::getDataPointer(std::vector<coords>* pointer) {
	this->coordsDataP = pointer;
}

void Window::initWindow() {
	this->videoMode.width = this->width;
	this->videoMode.height = this->heigh;
	this->window = new sf::RenderWindow(this->videoMode, "Graph");
	this->window->setFramerateLimit(60);
}
