

#include <iostream> //Input/Output stream (cin/cout)
#include <fstream>  //Input/Output file streams
#include <string>   //String manipulation
#include <iomanip>  //for C++ manipulators

#include "Seismometer_v3.h"
using namespace std;

int main () {

	Seismometer Fdata;
	
	Fdata.ReadFile();		//To read from file
	Fdata.DetectQuake();	//To perform calculations
	
	

    return 0;
}


