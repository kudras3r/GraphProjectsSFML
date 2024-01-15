
#include "Libs.h"
#include "Window.h"
#include "Math.h"

int main() {

	Math m;
	Window window(&m);

	std::vector<coords>* p = m.takeDataPointer();
	window.getDataPointer(p);
	// Loop
	while (window.open()) {

		
		window.updateWindow();
		window.renderWindow();
		

	}
	return 0;

}