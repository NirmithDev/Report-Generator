#ifndef REPORT1_H
#define REPORT1_H

#include<vector>
#include<list>
#include "ReportGenerator.h"


//#include "ReportData.h"

class Report1:public ReportGenerator{

	private:
		ReportData<float>* repo1;
		DescBehaviour<float>* l;
		vector<vector<float>> col;
		vector<float> perc;
		vector<string> anNam;
		//virtual void computeHelper(vector<Record*>,vector<Record*>,int,int);
		
		
	public:
		Report1();
		virtual ~Report1();
		//the function to populate the maps and census collection
		//static void populate();
		virtual void compute();
		//add in the parameter as seen fit
		virtual void formatData(ReportData<float>*);
		//printing the data
		virtual void printReport(ReportData<float>*);
		//cleanup function for later on to clean up the census collection
		//void cleanUp();
};

#endif
