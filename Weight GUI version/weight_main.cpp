//Hamilton Nguyen 1000538439 problem 3 07-19-2019 

#include "weight.h"	
#include <gtkmm/application.h>	
	
int	main(int argc, char *argv[])
{
	Gtk::Main app(argc,	argv);	
	
	weight_window window;	
	
	Gtk::Main::run(window);
	return	0;	
}