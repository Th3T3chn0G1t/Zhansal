#include <cstdlib>
#include <clocale>
#include <iostream>
#include <ncpp/NotCurses.hh>
#include <ncpp/Menu.hh>
#include <ncpp/Pile.hh>
#include <ncpp/Plane.hh>
#include <ncpp/Reel.hh>
#include <ncpp/MultiSelector.hh>
#include <ncpp/Selector.hh>
#include <ncpp/Visual.hh>
#include <ncpp/Direct.hh>
#include <ncpp/Plot.hh>
#include <ncpp/FDPlane.hh>
#include <ncpp/Subproc.hh>
#include <ncpp/Progbar.hh>

int run() {
	ncpp::NotCurses nc;

	const char* ncver = nc.version ();

	{
		ncpp::Plane p1 (1, 1, 0, 0);
		ncpp::Plot plot1 (p1);
		ncpp::Plane p2 (1, 1, 0, 0);
		ncpp::PlotU plot2 (p2);
		ncpp::Plane p3 (1, 1, 0, 0);
		ncpp::PlotD plot3 (p3);
	}

	nc.stop();

	ncpp::Direct direct{};
	direct.set_fg_rgb (0xb5, 0x0d, 0xff);
	std::cout << "notcurses version: ";
	direct.set_bg_rgb (0x05, 0x6e, 0xee);
	direct.set_fg_rgb (0xe2, 0xbf, 0x00);
	std::cout << ncver << std::endl;

	return EXIT_SUCCESS;
}

int main () {
	if(!setlocale (LC_ALL, "")) {
		std::cerr << "Couldn't set locale based on user preferences" << std::endl;
		return EXIT_FAILURE;
	}
	
	try {
		return run();
	} catch (ncpp::init_error &e) {
		std::cerr << "Initialization error: " << e.what () << std::endl;
	} catch (ncpp::invalid_state_error &e) {
		std::cerr << "Invalid state error: " << e.what () << std::endl;
	} catch (ncpp::invalid_argument &e) {
		std::cerr << "Invalid argument error: " << e.what () << std::endl;
	}

	return EXIT_FAILURE;
}
