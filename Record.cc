#include<iostream>
using namespace std;
#include<string>
#include<iomanip>

#include "Record.h"

Record::Record(int a, string b, int c){
	year=a;
	region=b;
	numAnimals=c;
}

int Record::getYear(){
	return year;
}

string Record::getRegion() const{
	return region;
}

ostream& operator<<(ostream& out, Record& r){
	out<<r.year<<" - "<<r.region<<" - "<<r.numAnimals<<"\n";
	return out;
}
