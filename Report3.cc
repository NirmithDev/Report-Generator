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
	//populate the data
	ReportGenerator::populate();
	//get all horse-ponies from the animal type map
	vector<Record*>& a=animalTypeMap["Horses-Ponies"];
	cout<<a.size()<<endl;
	vector<Record*> k;
	//int k=0;
	//get all horse-ponies in the year 2016 and add to a separate vector
	for(int i=0;i<a.size();i++){
		if(a[i]->getYear()==2016){
			k.push_back(a[i]);	
			//k++;
			//a.erase(i);
		}
	}
	//get the size of k and all the region cuz we will be going through each and every value to find the maximum value
	cout<<k.size()<<endl;
	for(int i=0;i<k.size();i++){
		cout<<*k[i];
	}
	cout<<endl;
	//region  ||  sub region  || number of horse and ponies in that sub region
	
	
}

void Report3::formatData(){}

void Report3::printReport(ReportData<int>* k){}








/*
//through all the regions
	int kill=0;
	//find the one with the maximum value
	

vector<Record*> Max;
	int maxPos=0;
	//cout<<*k[0];
	for(int i=0;i<k.size();i++){
		if(k[i]->getsubRegion()!="All"){
			int temp=0;
			if(k[kill]->getRegion()==k[i]->getRegion()){
				//cout<<k[kill]->getRegion()<<" ---->"<<k[kill]->getsubRegion()<<endl;
				//cout<<"--->>"<<kill<<endl;
				if(temp<k[kill]->getnumAnimals()){
					maxPos=kill;
					temp=k[kill]->getnumAnimals();
				}
				else if(temp<k[i]->getnumAnimals()){
					maxPos=i;
					temp=k[i]->getnumAnimals();
				}
				else if(temp>k[kill]->getnumAnimals()){
				}
				else if(temp>k[i]->getnumAnimals()){
				}
				//find the one with the highest number and assign max val to that and if it is not then break and append to the Max collection
				//maxPos=i;
				//if(k[kill]->getnumAnimals()<k[i]->getnumAnimals()){
				//	maxPos=i;
				//}
				//cout<<*k[i];
			}
			else{
				kill=i;
				cout<<maxPos<<endl;
				//maxPos=i;
				//append these values into the vector collection for maxVals of number of animals
				//Max.push_back(k[maxPos]);
				//cout<<maxPos<<endl;
				//cout<<"updated kill - - ->"<<kill<<endl;
			}
		}
		//kill++;
	}
	
	cout<<"size of max "<<Max.size()<<endl;
	//for(int i=0;i<Max.size();i++){
		//k[i]->getRegion()
	//	cout<<*Max[i];
	//}
	cout<<"blah"<<endl;*/
