#ifndef REPORT2_H
#define REPORT2_H

#include<vector>
#include<list>
#include "ReportGenerator.h"
#include "AscBehaviour.h"
//#include "ReportData.h"

class Report2:public ReportGenerator{

	private:
		ReportData<float>* repo2;
		AscBehaviour<float>* l;
		vector<Record*> perc;
		vector<vector<Record*>> collc;
		virtual void computeHelper(vector<Record*>,vector<Record*>,int,int);
		
		
	public:
		Report2();
		virtual ~Report2();
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

//virtual void computeHelper(vector<Record*>);
		//vector<Record*> a;
		//collection containing all the regions with subregions that got largest number of horse's and ponies in that region 
		//vector<Record*> max;
		//list<Record*> maxPonies;
