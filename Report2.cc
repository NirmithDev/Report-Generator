#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include<algorithm>
#include<string>

#include <fstream>

#include "Report2.h"
#include "Record.h"

//RESTART

Report2::Report2(){
	cout<<"TEST 5 PASSED"<<endl;
	l=new AscBehaviour<float>();
	repo2=new ReportData<float>(l);
}
Report2::~Report2(){
	//delete l;
	delete repo2;
	//if(ne!=NULL){
	//	delete ne;
	//}
	//delete ne;
	//ReportGenerator::cleanUp();
}

void Report2::computeHelper(vector<Record*> lm,vector<Record*> ml, int sum2011, int sum2016){
	//2016 CAN All
	for(int i=0;i<lm.size();i++){
		cout<<*lm[i];
	}
	cout<<endl;
	//2011 CAN All
	for(int j=0;j<ml.size();j++){
		cout<<*ml[j];
	}
	cout<<sum2011<<"       ---         "<<sum2016<<endl;
	

}

void Report2::compute(){

	collc.clear();
	vector<string> key=animalTypeMap.getKeys();
	cout<<key.size()<<endl;
	//printing out all the animal keys
	int sum2011=0;
	int sum2016=0;
	//vector<Record*> temp;
	for(int i=0;i<key.size();i++){
		cout<<key[i]<<endl;
		vector<Record*> temp;
		vector<Record*>& a=yearMap[2011];
		vector<Record*>& b=yearMap[2016];
		//first condition is 2011 
		for(int j=0;j<a.size();j++){
			//check if it exists 
			if(a[j]->getanimalType()==key[i] && a[j]->getRegion()=="CAN"){
		//		cout<<*a[j];
				temp.push_back(a[j]);
				sum2011+=a[j]->getnumAnimals();
			}
		}//cout<<endl;
		if(temp.size()==0){
			//ne=new Record(2011,"CAN",0,0,"All",key[i]);
			temp.push_back(new Record(2011,"CAN",0,0,"All",key[i]));
		}
		for(int j=0;j<b.size();j++){
			if(b[j]->getanimalType()==key[i] && b[j]->getRegion()=="CAN"){
		//		cout<<*b[j]<<endl;
				temp.push_back(b[j]);				
				sum2016+=b[j]->getnumAnimals();
			}
		}
		if(temp.size()==1){
			if(temp[0]->getYear()==2011){
				//ne=new Record(2016,"CAN",0,0,"All",key[i]);
				temp.push_back(new Record(2016,"CAN",0,0,"All",key[i]));

			}else{
				//ne=new Record(2011,"CAN",0,0,"All",key[i]);
				temp.push_back(new Record(2011,"CAN",0,0,"All",key[i]));

			}
		}
		//for(int j=0;j<temp.size();j++){}
		collc.push_back(temp);
	}
	cout<<"TOTAL IN 2011 ------->"<<sum2011<<endl;
	cout<<"TOTAL IN 2016 ------->"<<sum2016<<endl;
	formatData(repo2);	

}

void Report2::formatData(ReportData<float>* c){
	for(int i=0;i<collc.size();i++){
		for(int j=0;j<collc[i].size();j++){
			cout<<*collc[i][j];
		}
		cout<<endl;
	}
	//time for format data
	for(int i=0;i<collc.size();i++){
		stringstream ss;
		for(int j=0;j<collc[i].size();j++){
			ss<<collc[i][j]->getanimalType()<<"\t\t";
			
		}
		ss<<endl;
		cout<<ss.str();
	}
	//cout<<ss.str();
}

void Report2::printReport(ReportData<float>* c){
	//cout<<
}



/*if(m.size()<k.size()){
		cout<<"2016 is smaller"<<endl;
		for(int i=0;i<k.size();i++){
			//cout<<*k[i];
			
		}
		
	}
	else if(m.size()>k.size()){
		cout<<"2011 is smaller"<<endl;
	}*/
	//calculation of percentage of shizzle for 2011
	//float per=0.00;
	/*for(int i=0;i<k.size();i++){
		//cout<<sum2011<<endl;
		//cout<<"  ->"<<k[i]->getnumAnimals()<<"   -";
		float per=100*k[i]->getnumAnimals()/(float)sum2011;
		cout<<k[i]->getanimalType()<<"    ->"<<per;
		cout<<endl;
//		cout<<k[i]->getanimalType()<<"  -  "<<per<<endl;
	}*/
