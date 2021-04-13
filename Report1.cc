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
	
//	vector<string> keys=regionMap.getKeys();
	vector<string> keys=animalTypeMap.getKeys();
	vector<int> sumEach;
	int sumTot=0;
	//find sum of each and all animal in all the provinces for the year 2016 with the sub region ALL
	for(int i=0;i<keys.size();i++){
		int sum=0;
		cout<<keys[i]<<endl;
		vector<string> key=regionMap.getKeys();
		vector<Record*>& a=animalTypeMap[keys[i]];
		//set each animal type to every single region sorta like pair
		//for(int j=0;j<key.size();j++){
		//	if(key[j]!="CAN"){
		//		cout<<"--------------"<<key[j]<<endl;
				//vector<Record*>& a=animalTypeMap[keys[i]];
				cout<<endl;
		for(int k=0;k<a.size();k++){
			if(a[k]->getsubRegion()=="All" && a[k]->getYear()==2016 && a[k]->getRegion()!="CAN"){
				cout<<*a[k];
				sum+=a[k]->getnumAnimals();
			}
		}
		cout<<"SUM FOR ALL IN THE COUNTRY "<<keys[i]<<" -> "<<sum<<endl;
		sumTot+=sum;
		cout<<endl;
		sumEach.push_back(sum);
		//	}
//			cout<<"--------------"<<key[j]<<endl;
		//}
	}
	cout<<"TOTAL SUM OF ALL ANIMALS -> "<<sumTot<<endl;
	cout<<"THE SUM VECTOR COLLEC:::"<<endl;
	//for(int i=0;i<sumEach.size();i++){
	//	cout<<sumEach[i]<<endl;
	//}
	//after calculating each animals total and the total sum and adding them to the sumEach collection
	//we need to divide each animal with that type
	//so a iterator thru each city and in each city divide all the animals and append to my 2d collection for later on processing
	//if sum or number of that animal is a 0 then we just append a 0 otherwise we do the above mentioned
	
		
//	for(int i=0;i<sumEach.size();i++){
//		cout<<sumEach[i]<<endl;
//	}
	
}

/*
//ReportGenerator::populate();
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
		//cout<<endl;
		vector<Record*>& te=regionMap[key[i]];
		for(int j=0;j<te.size();j++){
			if(te[j]->getYear()==2016){
				//cout<<*te[j];
				if(te[j]->getsubRegion()=="All"){
					//cout<<"ADDED\t";
					//cout<<*te[j];
					//for loop iterating through each region and set sum for each animal we will find total 
					totalAnimal+=te[j]->getnumAnimals();	
				}
			}
		}
	}
	cout<<endl;
	cout<<"Total Animals-> "<<totalAnimal<<endl;
	
	cout<<perc.size()<<endl;
	int sHor=0,sGot=0,sLla=0,sRabb=0,sBi=0,sElk=0,sDome=0,sMin=0,sWild=0;
	//find sum of each and every animal and assign it to the unique types
	for(int i=0;i<key.size();i++){
		cout<<key[i]<<endl;
		vector<Record*>& t=regionMap[key[i]];
		cout<<t.size()<<endl;
		for(int j=0;j<key.size();j++){
			cout<<"-----------"<<key[j]<<endl;
			vector<Record*>& lm=regionMap[key[j]];
			cout<<lm.size()<<endl;
			for(int k=0;k<lm.size();k++){
				cout<<"Test"<<endl;
			}
		}
		//for(int j=0;j<t.size();j++){
		//	if(t[j]->getYear()==2016 && t[j]->getsubRegion()=="All"){
		//		cout<<*t[j];
				
		//	}
		//}		
	}
	

*/

/*for(int j=0;j<t.size();j++){
			if(t[j]->getYear()==2016  && t[j]->getsubRegion()=="All"){
				//cout<<*t[j];
				if(t[j]->getanimalType()=="Horses-Ponies"){
					sHor+=t[j]->getnumAnimals();
					cout<<"------------";
					cout<<*t[j];
				}else if(t[j]->getanimalType()=="Goats"){
					sGot+=t[j]->getnumAnimals();
					cout<<"------------";
					cout<<*t[j];
				}
				//for(int k=0;k<t.size();k++){
				//	if(t[k]->getYear()==2016 && t[k]->getsubRegion()=="All"){
				//		cout<<"-------------------------";
				//		cout<<t[k]->getRegion()<<endl;
				//	}
				//}
			}
	//		cout<<*t[j];
		}
		cout<<sHor<<"\t\t"<<sGot<<endl;*/
	//declare an array
	//vector<int> tEach;
	//int sHorse=0,sGoats=0,sLlama=0,sRab=0,sBison,;

	
	//use a collection that adds all the sums and totals and percentage to it 
	/*for(int i=0;i<key.size();i++){
		vector<Record*>& te=regionMap[key[i]];
		cout<<endl<<key[i]<<endl;
		for(int j=0;j<te.size();j++){
			if(te[j]->getYear()==2016  && te[j]->getsubRegion()=="All"){
				//cout<<*te[j];			
			
//				iterate through the animal type......
				//calculate each animal % in num Animals
				//cout<<*te[j]
				
				cout<<te[j]->getanimalType()<<"\t\t"<<te[j]->getnumAnimals()<<"\t\tCalculated percentage of each animal --->";
				//find percentage of each thingy;
				//float p=100*(te[j]->getnumAnimals()/(float)totalAnimal);
				//cout<<p<<endl;
			}
			
//			cout<<*te[j];
		}
		cout<<endl;
	}*/
	//string stream all the calculations together and add it to a vector of collections 






/*
	for(int i=0;i<key.size();i++){
		vector<Record*>& t=regionMap[key[i]];
		//cout<<*te[i];
		int s=0;
		for(int j=0;j<t.size();j++){
			if(t[j]->getsubRegion()=="All"  && t[j]->getYear()==2016){
				cout<<"\n===================\n";
				cout<<*t[j];
				//iterate through all it again
				for(int k=0;k<t.size();k++){
					//another for loop cuz I want one type of animal over the entire thing
					for(int l=0;l<t.size();l++){
						if(t[l]->getsubRegion()=="All"  && t[l]->getYear()==2016){
							//cout<<"-----------------------";
							if(t[l]->getanimalType()==t[k]->getanimalType()){
								cout<<"-----------------------";
								cout<<*t[l];
							}
						}
					}
					//if(t[k]->getsubRegion()=="All"  && t[k]->getYear()==2016){
						//cout<<"-----------------------";
					//	if(t[k]->getanimalType()==t[j]->getanimalType()){
					//		cout<<"-----------------------";
					//		cout<<*t[k];
					//	}
					//}
					//cout<<"-----------------------";
					//cout<<*t[k];
				}
			}
			//cout<<*t[j];
		}
		cout<<endl;
		//if(te[i]->getsubRegion()=="All" && te[i]->getYear()==2016){
		//	cout<<*te[i];
		//	for(int j=i;j<key.size();j++){
		//		if(te[j]->getRegion()==te[i]->getRegion()){
		//			cout<<
		//		}
		//		else{
		//			i=j-1;
		//			break;
		//		}
		//	}
			
	//	}
		//cout<<*te[i];
		//for(int j=i;j<key.size();j++){
		//	cout<<*te[j];
		//}
	}

*/


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
