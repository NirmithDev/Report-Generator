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
		Record* ne;
		
		
	public:
		Report2();
		virtual ~Report2();
		//the function to populate the maps and census collection
		virtual void compute();
		//add in the parameter as seen fit
		virtual void formatData(ReportData<float>*,int,int);
		//printing the data
		virtual void printReport(ReportData<float>*);
};

#endif

