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
	//cout<<key.size()<<endl;
	//printing out all the animal keys
	int sum2011=0;
	int sum2016=0;
	vector<Record*> temp;
	for(int i=0;i<key.size();i++){
		temp.clear();
		//cout<<key[i]<<endl;
		//vector<Record*> temp;
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
		//if(temp.size()==0){
			//ne=new Record(2011,"CAN",0,0,"All",key[i]);
		//	temp.push_back(new Record(2011,"CAN",0,0,"All",key[i]));
		//}
		//2016
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
		//temp.clear();
		//for(int j=0;j<temp.size();j++){
			//delete temp[i];
		//}
	}
	cout<<"TOTAL IN 2011 ------->"<<sum2011<<endl;
	cout<<"TOTAL IN 2016 ------->"<<sum2016<<endl;
	formatData(repo2,sum2011,sum2016);
	printReport(repo2);	

}

void Report2::formatData(ReportData<float>* cb,int sum2011,int sum2016){
	//time for format data
	vector<vector<float>> lls;
	for(int i=0;i<collc.size();i++){
		//stringstream ss;
		//ss<<collc[i][0]->getanimalType()<<"\t\t\t";
		float tel;
		vector<float> ttl;
		for(int j=0;j<collc[i].size();j++){
			//vector<int> ttl;
			if(collc[i][j]->getYear()==2011){
				//vector<int> ttl;
				
				tel= 100*(collc[i][j]->getnumAnimals())/(float)sum2011;
				ttl.push_back(tel);
			}
			else{
				//vector<int> ttl;
				tel= 100*(collc[i][j]->getnumAnimals())/(float)sum2016;
				ttl.push_back(tel);
			}
			//lls.push_back(ttl);
			//int tel= 100*(collc[i][j]->getnumAnimals())/
		//	ss<<tel<<"\t\t";
			
		}
		lls.push_back(ttl);
		//ss<<endl;
		//cout<<ss.str();
	}
	
	for(int i=0;i<collc.size();i++){
		//cout<<lls[i].size()<<endl;
		stringstream ss;
		float percDiff=0;
		ss<<setw(20)<<right<<collc[i][0]->getanimalType()<<"";
		//cout<<ss.str()<<endl;
		for(int j=0;j<lls[i].size();j++){
			ss<<"   "<< setw(7)<<right<<setprecision (1)<<fixed<<lls[i][j];
			if(j>0){
				//cout<<"------yeah we here"<<endl;
				percDiff=lls[i][j]-lls[i][j-1];
			}
			//cout<<endl;
		}
		if(percDiff<0){
			ss<<"   "<< setw(7)<<right<<setprecision (1)<<fixed<<percDiff<<endl;
			cb->add(percDiff,ss.str());
		}else{
			ss<<"   "<< setw(4)<<right<<setprecision (1)<<fixed<<"+"<<percDiff<<endl;
			cb->add(percDiff,ss.str());
		}
		//cout<<ss.str();
	}
	//cout<<ss.str();
	
}

void Report2::printReport(ReportData<float>* c){
	
	cout<<"\n\t \tPERCENTAGE CHANGE OF ANIMALS (2011-2016)\t\t\n";
	cout<<"\t---------------------------------------------------------\n";
	cout<<"\t\t ANIMAL TYPE\t  2011\t    2016     Change"<<endl<<endl;
	cout<<*c;
	cout<<"\t---------------------------------------------------------\n";
	//write into file
	ofstream outfile("Report2.txt",ios::out);
	if (!outfile) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}
	outfile<<"\n\t \tPERCENTAGE CHANGE OF ANIMALS (2011-2016)\t\t\n";
	outfile<<"\t---------------------------------------------------------\n";
	outfile<<"\t\t ANIMAL TYPE\t  2011\t    2016     Change"<<endl<<endl;
	outfile<<*c;
	outfile<<"\t---------------------------------------------------------\n";
	repo2->CLEAN();
}

