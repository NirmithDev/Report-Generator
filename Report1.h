#ifndef REPORT1_H
#define REPORT1_H

#include<vector>
#include<list>
#include "ReportGenerator.h"

class Report1_PercentageOfFarmByReg:public ReportGenerator{

	private:
		ReportData<float>* repo1;
		DescBehaviour<float>* l;
		vector<vector<float>> col;
		vector<float> perc;
		vector<string> anNam;		
		
	public:
		Report1_PercentageOfFarmByReg();
		virtual ~Report1_PercentageOfFarmByReg();
		virtual void compute();
		virtual void formatData(ReportData<float>*);
		virtual void printReport(ReportData<float>*);

};

#endif

/*
-> derived class for ReportGenerator "PERCENTAGE OF FARMS BY REGION (2016)"
-> Constructor to init the descending behaviour and we init the report data 
-> Destructor to deallocate the reportdata
-> compute afunction algorithm will be explained a bit later on
-> formatData -> formats the data to look somewhat similar to prof's output although it really isn't
-> PrintReport -> that prints out the report using ofstream and thenwe write into the file called Report1.txt

Compute function algorithm
-> I have a few collections some for animal names in the year the otheris a 2D vector of all collections 
-> first is a simple for loop can be done in a separate helper function but didn't due to other obligations in this for loop I am setting an d adding all the animals names that will used to be diplayed and formatted
-> second for loop is to find sum of each and every animal and then append into my temporary collection called sum EAch that I created for the matter
->third for loop is to find by region the percentage calculation for the farms by the year 2016 per region per animal
-> the fourth for loop is just to caluclate the total number of farms for each region for the calculation of totals that will be seen in the 5th for loop
-> the 5th for loop is just the calculation of percentages by region
*/
