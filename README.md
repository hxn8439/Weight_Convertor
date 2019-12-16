# Weight_Convertor

README
**************
File included: weight.cpp
**************
This program converts a user's weight from kilograms to pounds or
pounds to kilograms. It takes in inputs in the form of:

Jon 600 pounds
or
Jon 600 kilos

**************
Compilation instructions:

->This is built in a Lubuntu virtual machine

->In terminal:

	g++ weight.cpp
	
	./a.out
	
	James 182 pounds
	
output:Hi James-you weigh 82.5 kilos.

	Connor 78
	
output:Not enough info to convert.

	Connor 78 kilos
	
output:Hi Connor-you weigh 171.9 pounds. 

	Exit
	
output:Exiting...

**GUI VERSION**
**************
File included: weight.cpp , weight.h , weight_main.cpp, makefile
**************
This program handles the GUI interface of user's input doing a weight conversion between kilos 
and pounds. The output data will return the converted weight values through a dialog box.

**************
Compilation instructions:

->This is built in a Lubuntu virtual machine

->In terminal:

	make
	
	./weight
	
	Hamilton 83.5 kilos
	
	**click Convert**
	
	**data outputted**
	
	**click OK**
	
	Hamilton 83.5 pounds
	
	**click Convert**
	
	**data outputted**
	
	**click OK**
	
	**click close**
	
