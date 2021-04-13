#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

int main(){
	//cout<<"TEST 6"<<endl;
	/*
	
	Report1* d=new Report1();
	Report2* c=new Report2();
	int a;
	cin>>a;
	Report3* b=new Report3();
	while(a!=0){
		if(a==2){
		c->compute();
		}
		else if (a==3){
		b->compute();
		//delete b;
		}
		else if(a==1){
		d->compute();
		}
		cin>>a;
	}
	//Report3* b=new Report3();
	//b->compute();
	//Report1* a=new Report1();
	//a->compute();
	delete b;
	delete c;
	delete d;*/
	Control c;
	c.launch();
	return 0;
}

//	Control c;
//	c.launch();
