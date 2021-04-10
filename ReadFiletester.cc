//to read the files for now then when we get successfull we can just add it to the populate cuz I want to test it
#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>


int main(){
	cout<<"TEST 1"<<endl;
	int year,numFarms,numAnimals;
	string region,subRegion,animalType;
	ifstream infile("farms.dat", ios::in);
	if(!infile){
		cout<<"Error"<<endl;
		exit(1);
	}
	while(infile>>year>>region>>subRegion>>animalType>>numFarms>>numAnimals){
		cout<<year<<"  "<<region<<"  "<<subRegion<<"  "<<animalType<<"  "<<numFarms<<"  "<<numAnimals<<"  "<<endl;
	}
	//ReportGenerator a;
	//a.populate();
	return 0;
}

