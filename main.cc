#include <iostream>
using namespace std;
#include <string>

#include "Report3.h"
#include "Report2.h"

int main(){
	cout<<"TEST 6"<<endl;
	//Report3* a=new Report3();
	//a->compute();
	Report2* b=new Report2();
	b->compute();
	//delete a;
	delete b;
	return 0;
}

//ReportGenerator a;
	//a.populate();
	//a.cleanUp();
	//ReportGenerator* a=new ReportGenerator();
	//a.populate();

//	Control c;
//	c.launch();
