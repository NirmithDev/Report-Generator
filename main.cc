#include <iostream>
using namespace std;
#include <string>

//#include "ReportGenerator.h"
#include "Report3.h"
#include "Report2.h"
//#include "Report1.h"

int main(){
	cout<<"TEST 6"<<endl;
	
	//Report2 c;
	//c->compute();
	int a;
	cin>>a;
	Report3 b;
	while(a!=0){
		//Report3* b=new Report3();
		//if(a<5){
		//c.compute();
		//}
		//else{
		b.compute();
		//delete b;
		//}
		cin>>a;
	}
	//Report3* b=new Report3();
	//b->compute();
	//Report1* a=new Report1();
	//a->compute();
	//delete b;
	//delete c;
	
	
	return 0;
}

//	Control c;
//	c.launch();
