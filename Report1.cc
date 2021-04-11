#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include<algorithm>
#include<string>

#include <fstream>

#include "Report1.h"
#include "Record.h"

Report1::Report1(){
	cout<<"TEST 5 PASSED"<<endl;
	l=new DescBehaviour<float>();
	repo1=new ReportData<float>(l);
}
Report1::~Report1(){
	//delete l;
	delete repo1;
	//ReportGenerator::cleanUp();
}

void Report1::compute(){
	ReportGenerator::populate();
	//region map each region gets its own map?
	//AB gets 
	//vector<Record*>& AB= regionMap["AB"];
	vector<string> keys=regionMap.getKeys();
	cout<<endl;
	vector<string> key;
	for(int i=0;i<keys.size();i++){
		if(keys[i]!="CAN"){
			//cout<<keys[i]<<endl;
			//regionMap[keys[i]];
			key.push_back(keys[i]);	
		}
	}
	//vector<Record*> te;
	//calculate total animals that satisfy the conditions
	int totalAnimal=0;
	cout<<key.size()<<endl;
	for(int i=0;i<key.size();i++){
		//cout<<key[i]<<endl;
		//
		cout<<endl;
		vector<Record*>& te=regionMap[key[i]];
		for(int j=0;j<te.size();j++){
			if(te[j]->getYear()==2016){
				//cout<<*te[j];
				if(te[j]->getsubRegion()=="All"){
					cout<<"ADDED\t";
					cout<<*te[j];
					//for loop iterating through each region and set sum for each animal we will find total 
					totalAnimal+=te[j]->getnumAnimals();	
				}
			}
		}
	}
	cout<<endl;
	cout<<totalAnimal<<endl;
	
	//string stream all the calculations together and add it to a vector of collections 
}

/*

for(int i=0;i<perc.size();i++){
		cout<<endl;
		for(int j=i;j<=perc.size();j++){
			if(perc[i]->getRegion()==perc[j]->getRegion()){
				cout<<"------------------";
				cout<<*perc[j];
			}
			else{
				i=j-1;
				break;
			}
		}
	}
*/

void Report1::formatData(ReportData<float>* k){}

void Report1::printReport(ReportData<float>* lm){}
