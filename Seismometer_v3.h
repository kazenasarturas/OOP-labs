
#ifndef SEISMOMETER_V3
#define  SEISMOMETER_V3

#include <iostream>
#include <fstream>
#include <iomanip> //for C++ manipulators


class Seismometer{
private:
	int data;				//Number of data elements
	double time_incr;		//Time increment
	double *sensor;			//To read in data elements 
	double *Short_time_P;	//Short-time power
	double *Long_time_P;	//Long-time power
	double *Ratio;			//Ratio between powers
	int Short_W_Samples;	//Number of samples chossen for short-window
	int Long_W_Samples;		//Number of samples chossen for long-window
	double Threshold;		//Threshold value for siesmic data

public:
	Seismometer(){};
	void ReadFile();		//To read in data from file
	void DetectQuake();		//To perform calculations and detect possible quakes
};




#endif