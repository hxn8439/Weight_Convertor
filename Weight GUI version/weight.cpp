//Hamilton Nguyen 1000538439 problem 3 07-19-2019 

#include "weight.h"	
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

//THIS FUNCTION HELPS CONVERT THE DOUBLE INPUT FROM KILOS TO POUNDS.
double KilosToPound(double num1)
{
    double input9;
	input9 = (num1)/0.45359237;
	
	return input9; 
}

//THIS FUNCTION HELPS CONVERT THE DOUBLE INPUT FROM POUNDS TO KILOS.
double PoundToKilos(double num1)
{
    double input9;
	input9 = (num1)*0.45359237;
	
	return input9; 
}	

weight_window::weight_window()	: box(Gtk::ORIENTATION_VERTICAL), button_close("Close"), button_send("Convert")
{			
	set_size_request(400, 200);			
	set_title("WEIGHT CONVERTER");	
	
	add(box);	
	
	label.set_text("ENTER YOUR NAME AND WEIGHT");	
	box.pack_start(label);	
	
	entry.set_max_length(4000);
	entry.set_text("For an example: Hamilton 83.5 kilos");	
	entry.select_region(0, entry.get_text_length());
	box.pack_start(entry);	

	box.pack_start(weight);	

	button_send.signal_clicked().connect(sigc::mem_fun(*this,		
	&weight_window::send_value));		
	box.pack_start(button_send);	


	button_close.signal_clicked().connect(	sigc::mem_fun(*this,
	&weight_window::close_button));
	box.pack_start(button_close);	

	button_close.set_can_default();	
	button_close.grab_default();	

	show_all_children();	
}	
	
weight_window::~weight_window()
{

}	
	
void weight_window::send_value()	
{			
	std::string	input=entry.get_text();
	char inputspecial[4000];
	
	int i;
	
	for(i = 0; i<sizeof(inputspecial); i++)
	{
		inputspecial[i] = input[i];
	}	
	
	inputPTR =strtok(inputspecial, " ");
	container.push_back(inputPTR);
	
	while(inputPTR != NULL)
	{
		inputPTR =strtok(NULL, " ");
		container.push_back(inputPTR);
	}
	
	name = container[0];
	
	//THE IF STATMENT IS RESPONSIBLE TO CHECK THE LENGTH OF THE STRING.
	if(container.size()<4)
	{
		//	(MESSAGE_WARNING)	https://developer.gnome.org/gtk3/stable/GtkMessageDialog.html
		Gtk::MessageDialog dialog (*this, "Not enough info to convert! Exiting...",false,Gtk::MESSAGE_ERROR);
		dialog.run();
		container.clear();
		exit(0);
	}
	
	number = container[1];
	num1 = stoi(number);
	SIunit = container[2];
	
	if (SIunit.compare("pounds") == 0 || SIunit.compare("kilos") == 0)
	{
		if (SIunit == "kilos")
		{
			input9 = KilosToPound(num1);
			std::stringstream ss;
			ss << "Hi "<<name<<"-you weigh "<<input9<<" pounds.";
			std:: string s = ss.str();
			// (MESSAGE_WARNING)	https://developer.gnome.org/gtk3/stable/GtkMessageDialog.html
			Gtk::MessageDialog dialog (*this, "Weight is Converted!",false,Gtk::MESSAGE_WARNING);
			dialog.set_secondary_text(s);
			dialog.run();
			container.clear();
			
		}
		
		if (SIunit == "pounds")
		{
			input9 = PoundToKilos(num1);
			std::stringstream ss;
			ss << "Hi "<<name<<"-you weigh "<<input9<<" kilos.";
			std:: string s = ss.str();
			//	(MESSAGE_WARNING)	https://developer.gnome.org/gtk3/stable/GtkMessageDialog.html
			Gtk::MessageDialog dialog (*this, "Weight is Converted!",false,Gtk::MESSAGE_WARNING);
			dialog.set_secondary_text(s);
			dialog.run();	
			container.clear();
		}		
	}
}	
	
void weight_window::close_button()
{			
	hide();
}	
	