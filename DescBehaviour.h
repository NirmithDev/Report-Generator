#include <iostream>
using namespace std;
#include <cstdlib>

#include<string>

#include "CompareBehaviour.h"

template <class T>
class DescBehaviour:public CompareBehaviour<T>{
	public:
		DescBehaviour();
		virtual bool compare(T,T);
};

template <class T>
DescBehaviour<T>::DescBehaviour(){
	cout<<"TEST 3 PASSED"<<endl;
}

template <class T>
bool DescBehaviour<T>::compare(T a, T b){
	if(a.compare(b)<0){
		return true;
	}
	else{
		return false;
	}
}	
