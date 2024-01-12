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
		void drawAll();
		void updateWindow();
		void getDataPointer(std::vector<coords>*);

		// Variables
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		int width = 1240;
		int heigh = 720;

	private:
		// Initialize
		void initWindow();

		// Private var
		sf::Event event;
		std::vector<coords>* coordsDataP;
};

