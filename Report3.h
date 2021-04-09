#ifndef REPORT3_H
#define REPORT3_H

#include<vector>
#include "ReportData.h"
#include "ReportGenerator.h"

class Report3:public ReportGenerator{

	private:
		ReportData<int>* repo3;
		
	public:
		//not specified but it is here anyway
		Report3();
		virtual ~Report3();
		//the function to populate the maps and census collection
		//static void populate();
		virtual void compute();
		//add in the parameter as seen fit
		virtual void formatData();
		//printing the data
		virtual void printReport(ReportData<int>*);
		//cleanup function for later on to clean up the census collection
		//void cleanUp();
};

#endif
