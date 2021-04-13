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
	cout<<"TEST 8 PASSED"<<endl;
	l=new DescBehaviour<float>();
	repo1=new ReportData<float>(l);
	//ReportGenerator::populate();
}
Report1::~Report1(){
	//delete l;
	delete repo1;
	//ReportGenerator::cleanUp();
}

void Report1::compute(){
	col.clear();
//	vector<string> keys=regionMap.getKeys();
	vector<string> keys=animalTypeMap.getKeys();
	vector<int> sumEach;
	int sumTot=0;
	//find sum of each and all animal in all the provinces for the year 2016 with the sub region ALL
	for(int i=0;i<keys.size();i++){
		int sum=0;
		//cout<<keys[i]<<endl;
		vector<string> key=regionMap.getKeys();
		vector<Record*>& a=animalTypeMap[keys[i]];
		//set each animal type to every single region sorta like pair
		for(int k=0;k<a.size();k++){
			if(a[k]->getsubRegion()=="All" && a[k]->getYear()==2016 && a[k]->getRegion()!="CAN"){
				//cout<<*a[k];
				sum+=a[k]->getnumFarms();
			}
		}
//		cout<<"SUM FOR ALL IN THE COUNTRY "<<keys[i]<<" -> "<<sum<<endl;
		sumTot+=sum;
		//cout<<endl;
		if(sum>0){
			sumEach.push_back(sum);
		}
//		sumEach.push_back(sum);
		//	}
//			cout<<"--------------"<<key[j]<<endl;
		//}
	}
//	cout<<"TOTAL SUM OF ALL ANIMALS -> "<<sumTot<<endl;
//	cout<<"THE SUM VECTOR COLLEC:::"<<endl;
//	for(int i=0;i<sumEach.size();i++){
		//cout<<sumEach[i]<<endl;
//	}
	//cout<<endl;
	//after calculating each animals total and the total sum and adding them to the sumEach collection
	//we need to divide each animal with that type
	//so a iterator thru each city and in each city divide all the animals and append to my 2d collection for later on processing
	//if sum or number of that animal is a 0 then we just append a 0 otherwise we do the above mentioned
	//vector<vector<float>> col;
	vector<string> key=regionMap.getKeys();
	for(int i=0;i<key.size();i++){
		if(key[i]!="CAN"){
			//cout<<key[i]<<endl;
			vector<Record*>& b=regionMap[key[i]];
			//cout<<b.size()<<endl;
			//segregate the 2011 and 2016
			vector<Record*> te;
			vector<float> temp;
			for(int j=0;j<b.size();j++){
				if(b[j]->getYear()!=2011 && b[j]->getsubRegion()=="All"){
					te.push_back(b[j]);
				}
			}
			for(int j=0;j<te.size();j++){
				//cout<<*te[j];
				//calculate the percentage of the animal in the whole thingy and then append to it
				float temmmm=100*(te[j]->getnumFarms()/float(sumEach[j]));
				temp.push_back(temmmm);
				//cout<<"Total Sum of animal ------>"<<sumEach[j]<<" \tPERCENTAGE --->"<<temmmm<<endl;
			}
			col.push_back(temp);
		}
		//cout<<key[i]<<endl;
		//cout<<endl;
	}
	//cout<<col.size();
	//for(int i=0;i<col.size();i++){
	//	cout<<col[i].size()<<endl;
	//	for(int j=0;j<col[i].size();j++){
	//		cout<<col[i][j]<<"\t";
	//	}
	//	cout<<endl;
	//}
	cout<<endl<<endl;
	//calculate the total number of farms for each region
	//and add them all and append to another collection that will be used later on for sorting
	//regions map -> vector<string> key=regionMap.getKeys();
	//percentage breakdown of all animals in that region
	for(int i=0;i<key.size();i++){
		if(key[i]!="CAN"){
			cout<<key[i]<<endl;
			vector<Record*>& b=regionMap[key[i]];
			
			for(int j=0;j<b.size();j++){
				if(b[j]->getYear()!=2011 && b[j]->getsubRegion()=="All"){
					cout<<*b[j];
				}
				//cout<<*b[j];
				
			}
		}
		//cout<<key[i]<<endl;
	}
	
	//formatData(repo1);
}

void Report1::formatData(ReportData<float>* k){
//	stringstream ss;
	vector<string> key=regionMap.getKeys();
	for(int i=0;i<col.size();i++){
		//if(key[i]!="CAN"){
			stringstream ss;
			ss<<key[i+1]<<"   ";	
		//	cout<<col[i].size()<<endl;
			for(int j=0;j<col[i].size();j++){
				ss<<setw(7)<<right<<setprecision(1)<<fixed<<col[i][j];
				//cout<<col[i][j]<<"\t";
			}
			//append the total in here
			ss<<endl;
			cout<<ss.str();
		//}
		
		//cout<<endl;
	}
	//cout<<ss.str();
}

void Report1::printReport(ReportData<float>* lm){}
