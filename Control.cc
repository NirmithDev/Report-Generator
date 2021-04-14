#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"

Control:: Control(){
	rep1=new Report1();
	rep2=new Report2();
	rep3=new Report3();
	collections.push_back(rep1);
	collections.push_back(rep2);
	collections.push_back(rep3);
}

Control::~Control(){
	delete rep1;
	delete rep2;
	delete rep3;
}

void Control::launch(){
	View v;
	int p=1;
	while(true){
		v.showMenu(p);
		if(p==1){
			collections[0]->compute();
		}
		else if(p==2){
			collections[1]->compute();
		}
		else if(p==3){
			collections[2]->compute();
		}
		else if(p==0){
			break;
		}
		else{
			cout<<"INVALID INPUT\n";
		}
	}
}