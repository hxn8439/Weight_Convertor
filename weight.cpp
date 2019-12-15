//Hamilton Nguyen 1000538439 Problem 2. 06/09/2019

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define Max 100

using namespace std; 

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

int main()
{

	char input[Max];
	char* inputPTR;
	vector<char*>stackpile;
	int run = 1;
	string name;
	string number;
	double num1;
	double input9;
	string SIunit;
	
	//THIS WHILE LOOP WILL CONTINUE TO PROMPT THE USER UNTIL THE USER INPUT EXIT.
	while(run)
	{
		//THESE ALGORITHMS IS RESPONSBLE FOR GETTING A SERIES OF STRINGS PER LINE, SPLIT THE FIRST INPUT STORE AS A TOKEN USING STRTOK, AND PUSH BACK ONTO THE VECTOR AS A STACK.
		cout<<"Please enter your name and weight. ";
		cin.getline(input,Max);
		inputPTR =strtok(input, " ");
		stackpile.push_back(inputPTR);
		
		//THIS WHILE LOOP WILL ACCEPT THE REMAINING STRINGS AND STORE AS TOKENS. THEN IT WILL PUSH BACK ONTO ONTO THE VECTOR.
		while(inputPTR != NULL)
		{
			inputPTR =strtok(NULL, " ");
			stackpile.push_back(inputPTR);
		}	

		//DECLARE AND INITIALIZED THE FIRST STRING INPUT AS NAME.
		name = stackpile[0];
		
		//THE IF STATEMENT IS RESPONSBLE FOR EXITING THE PROGRAM WHEN USER INPUT exit
		if (name.compare("exit") == 0)
		{
			cout<<"Exiting...\n\n";
			return run = 0;
		}
		
		//THE IF STATMENT IS RESPONSIBLE TO CHECK THE LENGTH OF THE STRING.
		if(stackpile.size()<4)
		{
			cout<<"Not enough info to convert\n\n";
		}

		else
		{
			//DECLARE AND INITIALIZED THE SECOND AND THIRD STRING INPUT AS NUMBER AND SI UNIT.
			number = stackpile[1];
			num1 = stoi(number);
			SIunit = stackpile[2];
			
			//THE IF STATEMENT WILL DETERMINE WHETHER THE THIRD STRING IS A KILOS OR POUNDS UNIT.
			if (SIunit.compare("pounds") == 0 || SIunit.compare("kilos") == 0)
			{
				if (SIunit == "pounds")
				{
					input9 = PoundToKilos(num1);
					cout.precision(1);
					cout<<fixed;
					cout<<"Hi "<<input<<"-you weigh "<<input9<<" kilos.";
					cout<<"\n\n";	
				}

				if (SIunit == "kilos")
				{
					input9 = KilosToPound(num1);
					cout.precision(1);
					cout<<fixed;
					cout<<"Hi "<<input<<"-you weigh "<<input9<<" pounds.";
					cout<<"\n\n";
				}	
			}
		}
		
		//CLEAR RAM BY DATA DUMPING THE VECTOR, STACKPILE, FROM THE STACK.
		stackpile.clear();
	}
	
	return 0;
}
