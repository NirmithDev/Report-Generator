#ifndef REPORT3_H
#define REPORT3_H

#include<vector>
#include<list>
#include "ReportData.h"
#include "ReportGenerator.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

class Report3:public ReportGenerator{

	private:
		ReportData<int>* repo3;
		DescBehaviour<int>* l;
		virtual void computeHelper(vector<Record*>);
		//vector<Record*> a;
		//collection containing all the regions with subregions that got largest number of horse's and ponies in that region 
		vector<Record*> max;
		//list<Record*> maxPonies;
		
	public:
		//not specified but it is here anyway
		Report3();
		virtual ~Report3();
		//the function to populate the maps and census collection
		//static void populate();
		virtual void compute();
		//add in the parameter as seen fit
		virtual void formatData(ReportData<int>*);
		//printing the data
		virtual void printReport(ReportData<int>*);
		//cleanup function for later on to clean up the census collection
		//void cleanUp();
};

#endif
