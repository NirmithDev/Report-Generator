#ifndef REPORT3_H
#define REPORT3_H

#include<vector>
#include<list>
#include "ReportGenerator.h"

class Report3:public ReportGenerator{

	private:
		ReportData<int>* repo3;
		DescBehaviour<int>* l;
		int cou=0;
		virtual void computeHelper(vector<Record*>&);

		//collection containing all the regions with subregions that got largest number of horse's and ponies in that region 
		vector<Record*> max;
		list<Record*> maxPonies;
		
	public:
		Report3();
		virtual ~Report3();
		virtual void compute();
		//add in the parameter as seen fit
		virtual void formatData(ReportData<int>*);
		//printing the data
		virtual void printReport(ReportData<int>*);
};

#endif

/*
Report 3 is the report for the "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016"
-> We have a constructor that inits the Type of comparing behaviour we want and then we do the same we the ReportData
-> in the destructor we destuct the report cariable we created and we call the cleanUp function created in the ReportGenerator
-> the compute function which will be explained in more detail later on since I used the computeHelper function for it
-> formatData() -> we will be formatting the output to look like similar ish to that of the desired output
-> printReport() -> in this function we pretty much just display the reportData variable using the ofstream operator that we created in the ReportData class template and we will write all the data gets printed out into the repoective Report3.txt file

Compute function algorithm explaination
-> so I used a map called animalTypeMap that pretty much searches for the key "Horse-Ponies"
-> I created a helper function just to make it less complicated
-> I have a for loop iterating over the animal map for Horse Ponies 
-> in this I checked if the region is !="CAN" and the year is !=2011 && the subRegion !="All" the year can be just used to check if it is 2016 as well
-> I created a tmeporary int value to stor the one that has the highest horse and also a temporary int value to store the position of the region with the highest horse
-> find maximum num of animals of all within this for loops save the position and once it is false set the max Hor back to 0 let maxPos be as it is
-> then I add it to my collection max which contains all the regions with the subRegions with the highest horses
-> the last for loop is for the places that do not have a subregion such as NT and YT although they do have animals 
-> push it into the max collection
->then we call the formatData and PrintData in the end

*/















