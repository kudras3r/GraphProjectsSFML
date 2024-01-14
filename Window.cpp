#include "Window.h"

Window::Window() {

	this->initWindow();

	this->x0 = this->width / 2;
	this->y0 = this->heigh / 2;

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

		//std::cout << point.x << " " << point.y << "\n";
		sf::CircleShape sfPoint(2.f);
		sfPoint.setPosition(this->x0 + point.x * scale, this->y0 - point.y * scale);
		sfPoint.setFillColor(sf::Color::White);
		this->window->draw(sfPoint);

	}

}

void Window::drawCoordsVectors() {

	sf::RectangleShape Ox(sf::Vector2f((float)this->width, 1.f));
	sf::RectangleShape Oy(sf::Vector2f(1.f, (float)this->heigh));

	Ox.setFillColor(sf::Color::White);
	Oy.setFillColor(sf::Color::White);

	Ox.setPosition(0, this->y0);
	Oy.setPosition(this->x0, 0);

	this->window->draw(Ox);
	this->window->draw(Oy);
	
}

void Window::drawAll() {

	this->window->draw(this->text);
	this->drawCoordsVectors();
	this->drawPoints();

}

void Window::updateWindow() {

	while (this->window->pollEvent(this->event)) {

		switch (this->event.type) {

		case sf::Event::Closed:
			
			this->window->close();
			
			break;

		case sf::Event::TextEntered:

			if (event.text.unicode < 128) {
				ss << static_cast<char>(event.text.unicode);
				std::cout << static_cast<char>(event.text.unicode);
				this->text.setString(ss.str());
			}

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

	if (!this->font.loadFromFile("Fonts/Lordcorps[RUSbyPenka220]-Stencil.ttf")) {
		std::cout << "ERROR::FONTLOAD::font cant be loaded!" << '\n';
	}
	this->text.setFont(this->font);
	this->text.setCharacterSize(32);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("NONE");

}