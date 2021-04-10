#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include <algorithm>
#include<string>

#include "Report3.h"
#include "Record.h"

Report3::Report3(){
	cout<<"TEST 4 PASSED"<<endl;
	l=new DescBehaviour<int>();
	repo3=new ReportData<int>(l);
}
Report3::~Report3(){
	//delete l;
	delete repo3;
	ReportGenerator::cleanUp();
}

void Report3::computeHelper(vector<Record*> e){

	cout<<"HELPER FUNCITON"<<endl;
	
	cout<<e.size()<<endl;
	int j;
	for(int i=0;i<e.size();i++){
		//cout<<*e[i];
		if(e[i]->getRegion()!="CAN"){
			cout<<*e[i];
			for(j=i+1;j<e.size();j++){
				//if they have the same sub region
				if(e[i]->getRegion()==e[j]->getRegion()){
					cout<<"------------------NESTED FOR LOOP->";
					cout<<*e[j];
				}
				else{
					break;
				}
				//max.push_back(e[i]);
				//cout<<endl;
			}
			cout<<"\n-----------------------------\n";
			max.push_back(e[i]);
			i=j-1;
			cout<<i<<"  ";
		}
		
	}
	cout<<"\n\nMAX ARRAY TEST\n";
	for(int i=0;i<max.size();i++){
		cout<<*max[i];
	}
	cout<<max.size()<<endl;
	
}

/*if(a[i]->getRegion()!="CAN"){
			//iterate through the collection starting from position i+1 and check if the regions are same
			for(j=i+1;j<a.size();j++){
				
				cout<<a[j]->getsubRegion()<<endl;
				//if(a[j]->getsubRegion() != "All" && a[i]->getsubRegion()!= "All"){
					//max.push_back(a[j]);
				//	break;
				//} 
			}
			max.push_back(a[j]);
		}*/

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
	//maybe use an iterator?
	//typename vector<Record*>::iterator itr;
	for(int i=0;i<a.size();i++){
		if(a[i]->getYear()==2016){
			k.push_back(a[i]);	
		}
	}
	computeHelper(k);
	//get the size of k and all the region cuz we will be going through each and every value to find the maximum value
	/*cout<<k.size()<<endl;
	for(int i=0;i<k.size();i++){
		cout<<*k[i];
	}*/
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
