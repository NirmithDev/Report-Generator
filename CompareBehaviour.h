#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include<vector>
#include<iterator>
#include<string>

template <class T>
class CompareBehaviour{
	public:
		CompareBehaviour();
		virtual bool compare(T,T)=0;
};

template<class T>
CompareBehaviour<T>::CompareBehaviour(){
}

#endif

/*
-> the template base class CompareBehaviour that pretty much contains a constructor because force of habit
-> and it contains a pure virtual function called compare which will function according to our liking in the Ascending or descending behaviour
*/
