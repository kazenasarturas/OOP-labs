# OOP-labs
This is a C/C++ laboratory project for a software development module at Dublin Institute of Technology.

The aim of this assignment was to write a C++ Object Oriented program that reads seismometer data from a data (text) file named seismic.dat, determines whether seismic events have occurred and reports the data and findings to the screen in text format and stores the findings to a data file.

The first line of the seismic data file contains two values: the number of data elements or readings and the time interval in seconds that occurred between consecutive measurements. All the measurements were taken with the same time interval between them. After reading the data measurements the program identifies possible earthquakes or seismic events using a power ratio. 

At a specific point in time this ratio is the quotient of a short-time power measurement divided by a long -time power measurement. If the ratio is greater than a given threshold then an event may have occurred at that point in time.  

Given a specific point in the data measurements the short-time power is the average power, or average squared value, of the measurements using the specified point plus a small number of points that occurred just previous to the specified point. 

The long-time power is the average power of the measurements using the specified point plus a larger number of points that occurred just previous to the specified point. The set of points used in a calculation is referred to as a data window. 

The threshold is generally greater than 1 to avoid detecting events in constant data because the short-time power is equal to the long-time power if the data values are all the same value. 

The data window length (number of measurements) for short-time power and long-time power are to be read from the keyboard as is the threshold value. 


