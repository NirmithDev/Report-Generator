#include <iostream>
using namespace std;
#include <string>

#include "Report3.h"
#include "Report2.h"
#include "Report1.h"

int main(){
	cout<<"TEST 6"<<endl;
	Report1* a=new Report1();
	a->compute();
	delete a;
	//Report3* a=new Report3();
	//a->compute();
	//Report2* b=new Report2();
//	b->compute();
	//delete a;
	//delete b;
	return 0;
}

//	Control c;
//	c.launch();
