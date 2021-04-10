#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include <algorithm>
#include<string>

#include <fstream>

#include "Report2.h"
#include "Record.h"

Report2::Report2(){
	cout<<"TEST 5 PASSED"<<endl;
	l=new AscBehaviour<float>();
	repo2=new ReportData<float>(l);
}
Report2::~Report2(){
	//delete l;
	delete repo2;
	ReportGenerator::cleanUp();
}

void Report2::compute(){

	//take data from the year maps and use the populate function first
	ReportGenerator::populate();
	//year map
	vector<Record*>& a=yearMap[2011];
	cout<<a.size()<<endl;
	vector<Record*>& b=yearMap[2016];
	cout<<b.size()<<endl;
	
	vector<Record*> k;
	for(int i=0;i<a.size();i++){
		if(a[i]->getRegion()=="CAN"){
			k.push_back(a[i]);
		}
	}
	vector<Record*> m;
	for(int i=0;i<b.size();i++){
		if(b[i]->getRegion()=="CAN"){
			m.push_back(b[i]);
		}
	}
	
	cout<<k.size()<<endl;
	for(int i=0;i<k.size();i++){
		cout<<*k[i];
	}
	int sum2011=0;
	
	for(int i=0;i<k.size();i++){
		sum2011+=k[i]->getnumAnimals();
	}
	cout<<sum2011<<endl;
	
	//calculation of percentage of shizzle for 2011
	//float per=0.00;
	for(int i=0;i<k.size();i++){
		//cout<<sum2011<<endl;
		//cout<<"  ->"<<k[i]->getnumAnimals()<<"   -";
		float per=100*k[i]->getnumAnimals()/(float)sum2011;
		cout<<k[i]->getanimalType()<<"    ->"<<per;
		cout<<endl;
//		cout<<k[i]->getanimalType()<<"  -  "<<per<<endl;
	}
	
	

}

void Report2::formatData(ReportData<float>*){}

void Report2::printReport(ReportData<float>*){}

