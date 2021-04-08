#include <iostream>
using namespace std;
#include <string>

#include "ReportGenerator.h"

int main(){
	cout<<"TEST 1"<<endl;
	ReportGenerator a;
	a.populate();
	a.cleanUp();
	//ReportGenerator* a=new ReportGenerator();
	//a.populate();
	return 0;
}


//	Control c;
//	c.launch();
