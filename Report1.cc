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
	perc.clear();
	anNam.clear();
//	vector<string> keys=regionMap.getKeys();
	vector<string> keys=animalTypeMap.getKeys();
	vector<int> sumEach;
	int sumTot=0;
	
	//getting all animal types in the year 2016 for later formatting reasons
	vector<string> ke=regionMap.getKeys();
	vector<Record*>& an=regionMap[ke[1]];
	for(int i=0;i<an.size();i++){
		if(an[i]->getYear()==2016 && an[i]->getRegion()!="CAN" && an[i]->getsubRegion()=="All"){
			cout<<*an[i];
			anNam.push_back(an[i]->getanimalType());
		}
	}
	cout<<"-------------------------\n";
	
	//for(int i=0;i<anNam.size();i++){
	//	cout<<anNam[i]<<endl;
	//}
	
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
				//	cout<<*b[j];
					sum+=b[j]->getnumFarms();
					//t.push_back(sum);
				}
				//cout<<*b[j];
				
			}
			temporary.push_back(sum);
			sumByCount+=sum;
			//perc.push_back();
			//cout<<"Sum---------->"<<sum<<endl;
		}
		//cout<<key[i]<<endl;
	}
	//calculate total percentage difference ish and then append to the vector of floats and hopefully they might have the samenumber as that of regions which they prolly do
	for(int i=0;i<temporary.size();i++){
		//cout<<temporary[i]<<endl;
		float per=100*temporary[i]/(float)sumByCount;
		//cout<<"Percentage--------->"<<per<<endl;
		perc.push_back(per);
	}
	cout<<sumByCount<<endl;
	
	formatData(repo1);
	printReport(repo1);
}

void Report1::formatData(ReportData<float>* k){
//	stringstream ss;
	vector<string> key=regionMap.getKeys();
	for(int i=0;i<col.size();i++){
		//if(key[i]!="CAN"){
		stringstream ss;
		ss<<key[i+1]<<"   ";	
	//	cout<<col[i].size()<<endl;
		//for(int j=0;j<anNam.size();j++){
		//	ss<<"   "<<setw(40)<<left<<anNam[j];
		//}
		for(int j=0;j<col[i].size();j++){
			ss<<setprecision(1)<<fixed<<col[i][j]<<setw(15)<<right;
		}
		ss<<setw(13)<<right<<perc[i]<<endl;
		k->add(perc[i],ss.str());
		//}
	//	cout<<ss.str();
		//cout<<endl;
	}
	//cout<<ss.str();
}

void Report1::printReport(ReportData<float>* lm){
	
	cout<<"\n\n\t\t\t\t\t\t\t PERCENTAGE OF FARMS BY REGION\t\t\n";
	cout<<"\t\t\t\t\t\t------------------------------------------------\t\t\n";
	cout<<"     ";
	for(int i=0;i<anNam.size();i++){
		//cout<<anNam[i].size()<<endl;
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
		//cout<<setw(13.5)<<anNam[i]<<" ";
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
		//cout<<anNam[i].size()<<endl;
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
		//cout<<setw(13.5)<<anNam[i]<<" ";
	}
	out<<setw(9)<<"      Totals";
	out<<endl<<endl;
	out<<*lm;
	out<<"\t------------------------------------------------------------------------------------------------------------------------------\n";
	repo1->CLEAN();
}
