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
	l=new DescBehaviour<float>();
	repo1=new ReportData<float>(l);

}
Report1::~Report1(){
	delete repo1;
}

void Report1::compute(){
	col.clear();
	perc.clear();
	anNam.clear();
	vector<string> keys=animalTypeMap.getKeys();
	vector<int> sumEach;
	int sumTot=0;
	
	//getting all animal types in the year 2016 for later formatting reasons
	vector<string> ke=regionMap.getKeys();
	vector<Record*>& an=regionMap[ke[1]];
	for(int i=0;i<an.size();i++){
		if(an[i]->getYear()==2016 && an[i]->getRegion()!="CAN" && an[i]->getsubRegion()=="All"){
			//cout<<*an[i];
			anNam.push_back(an[i]->getanimalType());
		}
	}
	//find sum of each and all animal in all the provinces for the year 2016 with the sub region ALL
	for(int i=0;i<keys.size();i++){
		int sum=0;
		vector<string> key=regionMap.getKeys();
		vector<Record*>& a=animalTypeMap[keys[i]];
		//set each animal type to every single region sorta like pair
		for(int k=0;k<a.size();k++){
			if(a[k]->getsubRegion()=="All" && a[k]->getYear()==2016 && a[k]->getRegion()!="CAN"){
				sum+=a[k]->getnumFarms();
			}
		}
		sumTot+=sum;
		if(sum>0){
			sumEach.push_back(sum);
		}
	}


	//after calculating each animals total and the total sum and adding them to the sumEach collection
	//we need to divide each animal with that type
	//so a iterator thru each city and in each city divide all the animals and append to my 2d collection for later on processing
	//if sum or number of that animal is a 0 then we just append a 0 otherwise we do the above mentioned
	//vector<vector<float>> col;
	vector<string> key=regionMap.getKeys();
	for(int i=0;i<key.size();i++){
		if(key[i]!="CAN"){
			vector<Record*>& b=regionMap[key[i]];
			//segregate the 2011 and 2016
			vector<Record*> te;
			vector<float> temp;
			for(int j=0;j<b.size();j++){
				if(b[j]->getYear()!=2011 && b[j]->getsubRegion()=="All"){
					te.push_back(b[j]);
				}
			}
			for(int j=0;j<te.size();j++){
				//calculate the percentage of the animal in the whole thingy and then append to it
				float temmmm=100*(te[j]->getnumFarms()/float(sumEach[j]));
				temp.push_back(temmmm);
				
			}
			col.push_back(temp);
		}
		//cout<<key[i]<<endl;
		//cout<<endl;
	}
	
	cout<<endl<<endl;
	//calculate the total number of farms for each region
	//and add them all and append to another collection that will be used later on for sorting
	//percentage breakdown of all animals in that region
	int sumByCount=0;
	vector<int> temporary;
	for(int i=0;i<key.size();i++){
		if(key[i]!="CAN"){
			//cout<<key[i]<<endl;
			vector<Record*>& b=regionMap[key[i]];
			int sum=0;
			//vector<int> t;
			for(int j=0;j<b.size();j++){
				if(b[j]->getYear()!=2011 && b[j]->getsubRegion()=="All"){
					sum+=b[j]->getnumFarms();
				}
				
			}
			temporary.push_back(sum);
			sumByCount+=sum;
		}
	}
	//calculate total percentage difference ish and then append to the vector of floats and hopefully they might have the samenumber as that of regions which they prolly do
	for(int i=0;i<temporary.size();i++){
		float per=100*temporary[i]/(float)sumByCount;
		perc.push_back(per);
	}
	//cout<<sumByCount<<endl;
	
	formatData(repo1);
	printReport(repo1);
}

void Report1::formatData(ReportData<float>* k){
	vector<string> key=regionMap.getKeys();
	for(int i=0;i<col.size();i++){
		stringstream ss;
		ss<<key[i+1]<<"   ";	

		for(int j=0;j<col[i].size();j++){
			ss<<setprecision(1)<<fixed<<col[i][j]<<setw(15)<<right;
		}
		ss<<setw(13)<<right<<perc[i]<<endl;
		k->add(perc[i],ss.str());
	}
}

void Report1::printReport(ReportData<float>* lm){
	
	cout<<"\n\n\t\t\t\t\t\t\t PERCENTAGE OF FARMS BY REGION\t\t\n";
	cout<<"\t\t\t\t\t\t------------------------------------------------\t\t\n";
	cout<<"     ";
	for(int i=0;i<anNam.size();i++){
		if(anNam[i].size()>6){
			cout<<setw(9);
			for(int j=0;j<6;j++){
				cout<<anNam[i][j];
			}
			cout<<"  ";
		}
		else{
			cout<<setw(9)<<anNam[i]<<"  ";
		}
	}
	cout<<setw(9)<<"      Totals";
	cout<<endl<<endl;
	cout<<*lm;
	cout<<"\t------------------------------------------------------------------------------------------------------------------------------\n";
	ofstream out("Report1.txt",ios::out);
	if (!out) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}
	out<<"\n\n\t\t\t\t\t\t\t PERCENTAGE OF FARMS BY REGION\t\t\n";
	out<<"\t\t\t\t\t\t------------------------------------------------\t\t\n";
	out<<"     ";
	for(int i=0;i<anNam.size();i++){
		if(anNam[i].size()>6){
			out<<setw(9);
			for(int j=0;j<6;j++){
				out<<anNam[i][j];
			}
			out<<"  ";
		}
		else{
			out<<setw(9)<<anNam[i]<<"  ";
		}
	}
	out<<setw(9)<<"      Totals";
	out<<endl<<endl;
	out<<*lm;
	out<<"\t------------------------------------------------------------------------------------------------------------------------------\n";
	repo1->CLEAN();
}
