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
}

template <class T>
bool AscBehaviour<T>::compare(T a, T b){
	if(a>b){
		return true;
	}
	else{
		return false;
	}
}	

/*
-> Ascending class template which is a derived class template that checks if key 1 is greater than key 2
-> using the virtual compare function 
*/
