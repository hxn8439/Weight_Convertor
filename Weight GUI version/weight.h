//Hamilton Nguyen 1000538439 problem 3 07-19-2019 

#ifndef	WEIGHT_H	
#define	WEIGHT_H	
	
#include <gtkmm.h>
#include <vector>
	
class weight_window	: public Gtk::Window	
{	
	char* inputPTR;
	std::vector<char*>container;
	std::string name;
	std::string number;
	double num1;
	double input9;
	std::string SIunit;
	
	public:

	weight_window();		
	virtual	~weight_window();	
		
	protected:			

	//signal	handlers	
	void send_value();
	void close_button();	
		
	//widgets
	Gtk::Box weight;
	Gtk::Label	label;
	Gtk::Box	box;
	Gtk::Entry	entry;
	Gtk::Button	button_close, button_send;
};	
	
#endif	
	