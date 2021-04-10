#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include <algorithm>
#include<string>

#include <fstream>

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

	//cout<<"HELPER FUNCITON"<<endl;
	
	//cout<<e.size()<<endl;
	int j;
	//int maxHor=0;
	int maxPos=0;
	for(int i=0;i<e.size();i++){
		//cout<<*e[i];
		if(e[i]->getRegion()!="CAN" && e[i]->getsubRegion()!="All"){
			//cout<<*e[i];
			int maxHor=0;
			for(int j=i;j<=e.size();j++){
				if(e[j]->getRegion()==e[i]->getRegion()){
			//		cout<<"----------------";
			//		cout<<*e[j];
					//find maximum num of animals of all within this for loops save the position and once it is false set the max Hor back to 0 let maxPos be as it is
					if(maxHor<e[j]->getnumAnimals()){
						maxHor=e[j]->getnumAnimals();
						maxPos=j;
					}			
				}
				else{	
					i=j-1;
					break;
				}
				//cout<<"----------------";
				//cout<<*e[j];
			}		
			//i=j;
			//cout<<endl<<maxPos<<" - Count of horsie -"<<maxHor<<endl;
			//cout<<"-----------------------------\n";
			max.push_back(e[maxPos]);
			
		}
		
	}
	//now for the all shizzle I am thinking a count so like say the ones without a subregion will have a count of 0 and it just got a all
	for(int i=0;i<e.size();i++){
	int count=0;
		if(e[i]->getRegion()!="CAN"){
			//cout<<*e[i];
			for(int j=i;j<e.size();j++){
				if(e[j]->getRegion()==e[i]->getRegion()){
					//cout<<"----------------";
					//cout<<*e[j];
					count++;
				}
				else{
					i=j-1;
					break;
				}
				//cout<<"\n----------------\n";
			}
			if(count==1){
				//cout<<"--------------------";
				//cout<<*e[i];
				max.push_back(e[i]);
			}
			//cout<<"count ->"<<count<<"\n----------------\n";
		}
	}

	formatData(repo3);
	printReport(repo3);
}


void Report3::compute(){
	cout<<"I WAS CALLED\n";
	//populate the data
	ReportGenerator::populate();
	//get all horse-ponies from the animal type map
	vector<Record*>& a=animalTypeMap["Horses-Ponies"];
	//cout<<a.size()<<endl;
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
	//formatData(repo3);
	
}

void Report3::formatData(ReportData<int>* ab){
	for(int i=0;i<max.size();i++){
		//cout<<*max[i];
		stringstream ss;
		if(max[i]->getsubRegion()=="All"){
			ss<<max[i]->getRegion()<<"   "<<setw(40)<<left<<"  "<<"  "<<setw(7)<<right<<0<<endl;
		//cout<<max[i]->getnumAnimals()<<endl;
			ab->add(0,ss.str());
		}
		else{
			ss<<max[i]->getRegion()<<"   "<<setw(40)<<left<<max[i]->getsubRegion()<<"   "<<setw(6)<<right<<max[i]->getnumAnimals()<<endl;
		//cout<<max[i]->getnumAnimals()<<endl;
			ab->add(max[i]->getnumAnimals(),ss.str());
		}
	}
}

void Report3::printReport(ReportData<int>* k){
	cout<<"\n\t SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016\t\t\n";
	cout<<"\t------------------------------------------------------\n";
	cout<<*k;
	cout<<"\t------------------------------------------------------\n";
	//now write all this shizzle into the file
	ofstream outfile("Report3.txt",ios::out);
	if (!outfile) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}
  	
  	outfile<<"\n\t SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016\t\t\n";
  	outfile<<"\t------------------------------------------------------\n";
  	outfile<<*k;
  	outfile<<"\t------------------------------------------------------\n";
  	outfile<<endl;
}

















