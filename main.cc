#include <iostream>
using namespace std;
#include <string>

#include "Report3.h"
#include "Report2.h"
#include "Report1.h"

int main(){
	cout<<"TEST 6"<<endl;
	//Report1* a=new Report1();
	//a->compute();
	//delete a;
	//Report3* b=new Report3();
	//b->compute();
	Report2* c=new Report2();
	c->compute();
	//Report3* b=new Report3();
	//b->compute();
	delete c;
	//delete b;
	return 0;
}

//	Control c;
//	c.launch();
