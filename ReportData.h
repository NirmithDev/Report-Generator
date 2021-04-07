
#include <iostream>
using namespace std;
#include <cstdlib>
#include<iomanip>

#include<vector>
#include<iterator>
#include <algorithm>
#include<string>

#include "CompareBehaviour.h"

template <class T>
class ReportData{
	template <class E>
	friend ostream& operator<<(ostream&,const ReportData<E>&);
	//s
	template <class V>
	class ReportRow{
		public:
			V key;
			string row;
			ReportRow(V a,string n){
				key=a;
				row=n;
			}
			//V& getKeys();	
	};
	
	private:
		vector<ReportRow<T>> collec;
		CompareBehaviour<T>* comp;
	public:
		ReportData(CompareBehaviour<T>*);
		~ReportData();
		int getSize();
		void print();
		vector<ReportRow<T>>& getCollec();
		void add(T,string);
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c):comp(c){
	//comp=c;
	cout<<"I AM HERE"<<endl;
	
}

template <class T>
int ReportData<T>::getSize(){
	return collec.size();
}
template <class T>
void ReportData<T>::print(){
	for(int i=0;i<collec.size();i++){
		cout<<collec[i].row;
	}
}
/*
template <class T, class V>
vector<ReportRow<T>>& ReportData<V>::getCollec(){
	return *collec;
}*/

template <class T>
ReportData<T>::~ReportData(){
//destroy something idk
	delete comp;
}

template <class T>
void ReportData<T>::add(T key, string row){
	
	typename vector<ReportRow<T>>::iterator itr;
	//itr=collec.begin();
		//itr=collec.insert(itr,ReportRow<T>(key,row));
		//cout<<itr->key<<" - "<<itr->row;
	if(getSize()==0){
		itr=collec.insert(collec.begin(),ReportRow<T>(key,row));
		//cout<<itr->key<<" - "<<itr->row;
	}
	else{
		//a simple for loop with itr shizzle that iterates thru the thingy and then compares and adds accrdg to that
		for(itr=collec.begin();itr!=collec.end();itr++){
			//cout<<itr->key;
			if(comp->compare(itr->key,key)){
			//	cout<<itr->key<<" - "<<key;
				//itr=collec.insert(itr,ReportRow<T>(key,row));
				//cout<<itr->row;
				break;
			}
			else{
				continue;
			}
			//break;		
		}
		collec.insert(itr,ReportRow<T>(key,row));
	}
		
}


//typename ReportRow<T> b;
	//vector<ReportRow<T>>
	//ostream_iterator<vector<ReportRow<T>>> outItr(out);
	//copy(a.begin(),a.end(), outItr);
//overloaded insertion operator for output
//template vector<ReportRow<T>>

template <class T>
ostream& operator<<(ostream& out,const ReportData<T>& a){	
	for(int i=0;i<a.collec.size();i++){
		out<<a.collec[i].row;
	}
	return out;
}


//ReportData<T>::template
	//template<vector<ReportRow<T>>>
	//typename vector<ReportRow<T>>::iterator itr;
	//typename  ReportData<T>::vector<ReportRow<V>>::iterator itr;
	//for(itr=a.begin();itr!=a.end();itr++){
	//	out<<itr;
	//}	
	//a.getCollec();
	//out<<a.collec;
	
	//cout<<a.getSize()<<endl;
	//out<<a.getSize();
	//for(int i=0;i<a.getSize();i++){
	
	//}
	//typename vector<ReportRow<T>>::iterator itr;
	//for(itr = rows.begin(); itr != rows.end(); ++itr) {
        //	out << itr->row << endl;
  	//}
//      return output;













