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
}

template <class T>
bool DescBehaviour<T>::compare(T a, T b){
	if(a<b){
		return true;
	}
	else{
		return false;
	}
}	

/*
-> the Descending class template which is a derived class template checks if key 2 is greater than key 1
-> using the virtual compare function
*/
