#include "Window.h"


// Public Methods

// Constructor / Destructor

Window::Window(Math* pointer) {

	this->initWindow(pointer);

}

Window::~Window() {

	delete this->window;

}

// Service

bool Window::open() {

	return this->window->isOpen();

}

void Window::renderWindow() {

	this->window->clear();
	this->drawAll();
	this->window->display();

}



void Window::updateWindow() {

	while (this->window->pollEvent(this->event)) {

		switch (this->event.type) {

		case sf::Event::Closed:
			
			this->window->close();
			
			break;

		case sf::Event::TextEntered:

			if (event.text.unicode == 39) {  // scope ++ (')

				this->scale += 20; 

			}

			else if (event.text.unicode == 47) {  // scope -- (/)

				this->scale -= 20;  

			}

			else if (event.text.unicode == 8) {  // Backspace press (clear sstream and text)
				ss.str("");
				ss << "y=";
				this->text.setString("y=");
			}

			else if (event.text.unicode == 13) {  // Enter press (let calculate)
			
				std::string a;  // Creating string for calculating
				for (unsigned i = 2; i < this->ss.str().length(); i++) {
					a += this->ss.str()[i];
				}
				
				this->mathP->calculatingPoints(a);

			}

			else if (event.text.unicode < 128) {
				
				ss << static_cast<char>(event.text.unicode);	
				this->text.setString(ss.str());

			}

			break;
		}
	}
}

void Window::getDataPointer(std::vector<coords>* pointer) {

	this->coordsDataP = pointer;  // Pointer to vector with points data

}


// Private methods

// Initialize

void Window::initWindow(Math* pointer) {

	this->mathP = pointer;

	this->scale = 60;

	this->x0 = this->width / 2;
	this->y0 = this->heigh / 2;

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
	this->ss << "y=";
	this->text.setString("y=");

}

// Drawing

void Window::drawPoints() {

	for (coords point : *this->coordsDataP) {

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

	for (float i = 0.f; i < 100.f; i += 1.f) {

		sf::CircleShape pointX(1.2f);
		sf::CircleShape pointY(1.2f);

		pointX.setFillColor(sf::Color::White);
		pointY.setFillColor(sf::Color::White);

		pointX.setPosition(this->x0 + i * scale, this->y0);
		pointY.setPosition(this->x0, this->y0 + i * scale);

		sf::CircleShape pointX1(1.2f);
		sf::CircleShape pointY1(1.2f);

		pointX1.setFillColor(sf::Color::White);
		pointY1.setFillColor(sf::Color::White);

		pointX1.setPosition(this->x0 - i * scale, this->y0);
		pointY1.setPosition(this->x0, this->y0 - i * scale);

		this->window->draw(pointX1);
		this->window->draw(pointY1);
		this->window->draw(pointX);
		this->window->draw(pointY);
	}

}

void Window::drawAll() {

	this->window->draw(this->text);
	this->drawCoordsVectors();
	this->drawPoints();

}