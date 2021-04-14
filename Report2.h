#ifndef REPORT2_H
#define REPORT2_H

#include<vector>
#include<list>
#include "ReportGenerator.h"
#include "AscBehaviour.h"

class Report2_PercentageChange:public ReportGenerator{

	private:
		ReportData<float>* repo2;
		AscBehaviour<float>* l;
		vector<Record*> perc;
		vector<vector<Record*>> collc;
		Record* ne;
		
		
	public:
		Report2_PercentageChange();
		virtual ~Report2_PercentageChange();
		virtual void compute();
		virtual void formatData(ReportData<float>*,vector<int>);
		virtual void printReport(ReportData<float>*);
};

#endif

/*
-> derived class for ReportGenerator "PERCENTAGE CHANGE OF ANIMALS (2011-2016)"
-> constuctor to init the preferred type of compare behaviour and init the report2 
-> destructor to deallocate the report 2 variable
-> we have a compute function for which I didn't necessarily need a helper function and the algo will be explained later on
-> format Data that calculates the percentage for each elem and pushes them back repesectively in my 2D vector and I calculate the difference and add it to the string to display it accrdg to the preferred way a
-> printData just prints out the Report variable data and writes into a file

compute algorithm
-> I have a collection that adds all the data for 2011 and 2016 a 2d collection 
-> a for loop I declare and use the maps for the year 2011 and year 2016
-> for loop for 2011 that checks for each type of animal and if the region is CANI would add it to the sum for 2011
-> similarly I would do the same for the sum 2016 although this can be done using a vector instead of just having the sums for 2011 and 2016 
-> then I have a if statement for incase I have missed out on any of the values or for the scenario where in 2016 the wildboar was non existent so I created a new record and appended it into my temp vector which got added into my 2D collection
-> then I called the formatData and printReport
*/
