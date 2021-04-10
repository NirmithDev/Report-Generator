#include <iostream>
using namespace std;
#include <string>

#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

#include "ReportGenerator.h"


vector<Record*> ReportGenerator::census;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalTypeMap;

/*
ReportGenerator::ReportGenerator(){
	cout<<"I am here"<<endl;
}
*/
void ReportGenerator::cleanUp(){
	for(int i=0;i<census.size();i++){
		delete census[i];
	}
	cout<<"\ndestroyed\n";
}

void ReportGenerator::populate(){
	cout<<"WE ARE HERE"<<endl;
	ostream_iterator<Record> outItr(cout);
	int year,numFarms,numAnimals;
	string region,subRegion,animalType;
	ifstream infile("farms.dat", ios::in);
	if(!infile){
		cout<<"Error"<<endl;
		exit(1);
	}
	while(infile>>year>>region>>subRegion>>animalType>>numFarms>>numAnimals){
		//populate the record collection
		census.push_back(new Record(year,region,numAnimals,numFarms,subRegion,animalType));
	}
	
	//cout<<endl<<"List of DETAILS:"<<endl;
	//cout<<census.size()<<endl;
	
	for(int i=0;i<census.size();i++){
		//populate each map with each respective key ish
		yearMap.add(census[i]->getYear(),census[i]);
		regionMap.add(census[i]->getRegion(),census[i]);
		animalTypeMap.add(census[i]->getanimalType(),census[i]);
	}
	//cout<<yearMap.getKeySize()<<endl;
	//cout<<regionMap.getKeySize()<<endl;
	//cout<<animalTypeMap.getKeySize()<<endl;
	//copy(census.begin(), census.end(), outItr);
}
