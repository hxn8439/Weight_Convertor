CXXFLAGS += -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

ex: weight_main.o weight.o
	$(CXX) $(CXXFLAGS) -o weight weight_main.o weight.o $(GTKFLAGS)
	
weight_main.o: weight_main.cpp weight.h
	$(CXX) $(CXXFLAGS) -c weight_main.cpp $(GTKFLAGS)
	
weight.o: weight.h weight.cpp
	$(CXX) $(CXXFLAGS) -c weight.cpp $(GTKFLAGS)
	
cleanup:
	echo "Cleaning up object files and executable!"
	rm *.o
	rm weight