#include <iostream>
using namespace std;
#include <cstdlib>

#include<string>

#include "CompareBehaviour.h"

template <class T>
class AscBehaviour:public CompareBehaviour<T>{
	public:
		AscBehaviour();
		virtual bool compare(T,T);
};

template <class T>
AscBehaviour<T>::AscBehaviour(){
	cout<<"TEST 2 PASSED"<<endl;
}

template <class T>
bool AscBehaviour<T>::compare(T a, T b){
	if(a.compare(b)>0){
		return true;
	}
	else{
		return false;
	}
}	
