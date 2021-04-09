#include<iostream>
using namespace std;
#include<string>
#include<iomanip>

#include "Record.h"

Record::Record(int a, string b, int c,int d,string e,string f){
	year=a;
	region=b;
	numAnimals=c;
	numFarms=d;
	subRegion=e;
	animalType=f;
}

int Record::getYear(){
	return year;
}

int Record::getnumAnimals(){
	return numAnimals;
}

int Record::getnumFarms(){
	return numFarms;
}

string Record::getRegion(){
	return region;
}

string Record::getsubRegion(){
	return subRegion;
}

string Record::getanimalType(){
	return animalType;
}

ostream& operator<<(ostream& out, Record& r){
	out<<r.year<<" - "<<r.region<<" - "<<r.animalType<<" - "<<r.subRegion<<" - "<<r.numFarms<<" - "<<r.numAnimals<<"\n";
	return out;
}
