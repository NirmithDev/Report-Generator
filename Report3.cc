#include <iostream>
using namespace std;
#include <string>

#include "Report3.h"
#include "Record.h"

Report3::Report3(){
	cout<<"TEST 2 PASSED"<<endl;
}
Report3::~Report3(){
	ReportGenerator::cleanUp();
}

void Report3::compute(){
	cout<<"I WAS CALLED\n";
	ReportGenerator::populate();
	//how to access the map and stuff?
	vector<Record*>& a=animalTypeMap["Horses-Ponies"];
	cout<<a.size()<<endl;
	vector<Record*> k;
	//int k=0;
	for(int i=0;i<a.size();i++){
		if(a[i]->getYear()==2011){
			k.push_back(a[i]);	
			//k++;
			//a.erase(i);
		}
	}
	cout<<k.size();
}

void Report3::formatData(){}

void Report3::printReport(ReportData<int>* k){}
