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

ReportGenerator::ReportGenerator(){
	cout<<"I am here"<<endl;
}
void ReportGenerator::populate(){
	cout<<"WE ARE HERE"<<endl;
	
	int year,numFarms,numAnimals;
	string region,subRegion,animalType;
	ifstream infile("farms.dat", ios::in);
	if(!infile){
		cout<<"Error"<<endl;
		exit(1);
	}
	while(infile>>year>>region>>subRegion>>animalType>>numFarms>>numAnimals){
		cout<<year<<"  "<<region<<"  "<<subRegion<<"  "<<animalType<<"  "<<numFarms<<"  "<<numAnimals<<"  "<<endl;
	}
}
