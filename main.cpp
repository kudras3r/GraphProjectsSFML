
#include "Libs.h"
#include "Window.h"
#include "Math.h"

int main() {
	
	Window window;
	Math m(&window.width, &window.heigh);
	std::vector<coords>* p = m.takeDataPointer();
	window.getDataPointer(p);
	// Loop
	while (window.open()) {


		window.updateWindow();
		window.renderWindow();
		

	}
	return 0;
}