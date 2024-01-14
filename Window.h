#pragma once

#include "Libs.h"
#include "Math.h"

class Window {
    public:
		// Constructor / Destructor
		Window();
		~Window();

		// Public Methods
		bool open();
		void renderWindow();

		void drawPoints();
		void drawCoordsVectors();
		void drawAll();

		void updateWindow();

		void getDataPointer(std::vector<coords>*);

		// Variables
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		const int width = 1240;
		const int heigh = 720;

	private:
		// Initialize
		void initWindow();

		// Private var
		std::stringstream ss;
		int x0, y0;
		const int scale = 100;
		sf::Event event;
		sf::Font font;
		sf::Text text;
		std::vector<coords>* coordsDataP;

};

