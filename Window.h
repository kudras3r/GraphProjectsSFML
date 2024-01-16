#pragma once

#include "Libs.h"
#include "Math.h"
#include "Parser.h"

class Window {
	
	private:

		// Initialize
		void initWindow(Math*);

		// Private methods
		void drawPoints();
		void drawCoordsVectors();
		void drawAll();

		// Private vars
		Math* mathP;

		int x0, y0;
		int scale;

		sf::Event event;
		sf::Font font;
		sf::Text text;

		std::vector<coords>* coordsDataP;

		std::stringstream ss;

		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		const int width = 1240;
		const int heigh = 720;

    public:
		
		// Constructor / Destructor
		Window(Math* pointer);
		~Window();

		// Service
		bool open();

		void renderWindow();
		void updateWindow();

		void getDataPointer(std::vector<coords>*);

};

