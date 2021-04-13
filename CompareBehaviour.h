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
