
#include <string>	//String manipulation
#include <iostream>	//Input/Output stream (cin/cout)
#include <fstream>	//Input/Output file streams
#include <iomanip>  //for C++ manipulators
#include "Seismometer_v3.h"


using namespace std;

fstream fin;	 //Input/Output stream class for file handling
double time_inc; //Time increment
int data;		 //Amount of data in file


//READING FROM FILE
void Seismometer::ReadFile(){
	fin.open("SEISMIC.DAT"); //Open file for input/output operations.

	if(fin.fail()){
		cout<<"\n Cannot open file.";
	}
	else{
		fin>>data>>time_inc; //Data and time_inc read from file
		sensor=new double[data];
        cout<<"\n Time: "<<setw(11)<<"Reading:\n";

		for(int k=0;k<data;k++){
			fin>>sensor[k];     //Read in next data element in file
			cout<<" "<<setw(4)<<time_inc<<"s   "<<setw(1)<<sensor[k]<<"\n";
			time_inc=time_inc+0.01;
		}
		fin.close();
	}
}

//DETECTING QUAKES
void Seismometer::DetectQuake(){

	int start=0;
	//Calculating seismic events
    //Calculating short-time power, long-time power and the ratio of both windows
	fin.open("SEISMIC.DAT");
	cout<<"\n Seismic readings:\n";

	//User chooses threshold, number of samples for short and long time power
	cout<<"\n Set the short-window size value: ";
	cin>>Short_W_Samples;
	cout<<"\n Set the long-window size value:  ";
	cin>>Long_W_Samples;
	cout<<"\n Set the threshold:               ";
	cin>>Threshold;
	cout<<"\n Choose from where to start reading in data: ";
	cin>>start; //Choosing starting point for reading from file

    cout<<setw(10)<<" Short window:"<<setw(10)<<" Long window:"<<setw(8)<<" Ratio:"<<setw(12)<<"time:\n";
    fin>>data>>time_inc;

	Short_time_P=new double[data];
	Long_time_P=new double[data];
	Ratio=new double[data];

	//Short and long time calculation
	for(int n=0;n<data;n++){
		if(n>=start){
		fin>>sensor[n];

		*Short_time_P=(
					   pow(sensor[n],2)+
					   pow(sensor[n-1],2)
					  )
					  /Short_W_Samples;

		*Long_time_P=(
					  pow(sensor[n],2)+
					  pow(sensor[n-1],2)+
					  pow(sensor[n-3],2)+
					  pow(sensor[n-4],2)
					 )
					 /Long_W_Samples;
					 
		
		//Ration between windows calculated
		*Ratio=(*Short_time_P)/(*Long_time_P);
		cout<<"\n"<<setw(5)<<*Short_time_P<<setw(13)<<*Long_time_P<<setw(20)<<*Ratio<<setw(7)<<time_inc<<"sec";

		//Threshold set by user
		//Prints data if ratio of windows is above the threshold
		//Any seismic event detected is printed to screen
		//Any seismic event detected is written to new file
		if(*Ratio>Threshold){
            cout<<"  Seismic event detected! ";
			fin.open("Values.txt",fstream::trunc);
			fstream out("Values.txt",fstream::app);
		
			out.seekg(0,ios::end);
			out<<"\n Reading: "<<n+1;
			out<<"\n Short: ";
			out<<*Short_time_P;
			out<<"\n Long: ";
			out<<*Long_time_P;
			out<<"\n Ratio: ";
			out<<*Ratio;
			out<<"\n ";

		out.close();
		}

		}else{
			fin>>sensor[n]; //Sensor reads in data element from file but does not display
		}

		time_inc=time_inc+0.01;

		
	}
	fin.close();
}



