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

	//take data from the year maps and use the populate function first
	//ReportGenerator::populate();
	//year map
	//vector<Record*>& a=yearMap[2011];
	//cout<<a.size()<<endl;
	//	figure out how to get a for loop for the name of animals
	//vector<Record*>& b=yearMap[2016];
	//vector<vector<Record*>> collc;
	collc.clear();
	vector<string> key=animalTypeMap.getKeys();
	cout<<key.size()<<endl;
	//printing out all the animal keys
	int sum2011=0;
	int sum2016=0;
	for(int i=0;i<key.size();i++){
		cout<<key[i]<<endl;
		vector<Record*> temp;
		vector<Record*>& a=yearMap[2011];
		vector<Record*>& b=yearMap[2016];
		for(int j=0;j<a.size();j++){
			//check if it exists 
			if(a[j]->getanimalType()==key[i] && a[j]->getRegion()=="CAN"){
		//		cout<<*a[j];
				temp.push_back(a[j]);
				sum2011+=a[j]->getnumAnimals();
			}
		}//cout<<endl;
		for(int j=0;j<b.size();j++){
			if(b[j]->getanimalType()==key[i] && b[j]->getRegion()=="CAN"){
		//		cout<<*b[j]<<endl;
				temp.push_back(b[j]);				
				sum2016+=b[j]->getnumAnimals();
			}
		}
		
		//cout<<"\n---------------------TEMP-------------------\n";
		
		//for(int z=0;z<temp.size();z++){
		//	cout<<*temp[z];
		//}
		//cout<<endl;
		collc.push_back(temp);
	}
	cout<<"TOTAL IN 2011 ------->"<<sum2011<<endl;
	cout<<"TOTAL IN 2016 ------->"<<sum2016<<endl;
	formatData(repo2);
	//cout<<"SIZE OF TESTER ------>"<<collc.size()<<endl;
	//for(int i=0;i<collc.size();i++){
	//	for(int j=0;j<collc[i].size();j++){
	//		cout<<*collc[i][j];
	//	}
	//	cout<<endl;
		//cout<<collc[i];
	//}
	//vector<Record*> k;
	/*for(int i=0;i<a.size();i++){
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
	//for(int i=0;i<k.size();i++){
	//	cout<<*k[i];
//	}
	cout<<m.size()<<endl;
	cout<<endl;
//	for(int i=0;i<m.size();i++){
//		cout<<*m[i];
//	}
	int sum2011=0;
	
	for(int i=0;i<k.size();i++){
		sum2011+=k[i]->getnumAnimals();
	}
	cout<<sum2011<<endl;
	
	
	int sum2016=0;
	for(int i=0;i<m.size();i++){
		sum2016+=m[i]->getnumAnimals();	
	}
	cout<<sum2016<<endl;
	computeHelper(m,k,sum2011,sum2016);
	*/
	

}

void Report2::formatData(ReportData<float>*){
	//for(int i=0;i<collc.size();i++){
	//	for(int j=0;j<collc[i].size();j++){
	//		cout<<*collc[i][j];
	//	}
	//	cout<<endl;
		//cout<<collc[i];
	//}
	//time for format data
}

void Report2::printReport(ReportData<float>*){}



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
