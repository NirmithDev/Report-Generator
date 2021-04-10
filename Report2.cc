#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include <algorithm>
#include<string>

#include <fstream>

#include "Report2.h"
#include "Record.h"

Report2::Report2(){
	cout<<"TEST 5 PASSED"<<endl;
	l=new AscBehaviour<float>();
	repo2=new ReportData<float>(l);
}
Report2::~Report2(){
	//delete l;
	delete repo2;
	ReportGenerator::cleanUp();
}

void Report2::compute(){

	//take data from the year maps and use the populate function first
	ReportGenerator::populate();
	

}

void Report2::formatData(ReportData<float>*){}

void Report2::printReport(ReportData<float>*){}

