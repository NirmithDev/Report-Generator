
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

	template <class V>
	class ReportRow{
		public:
			V key;
			string row;
			ReportRow(V a,string n){
				key=a;
				row=n;
			}
	};
	
	private:
		vector<ReportRow<T>> collec;
		CompareBehaviour<T>* comp;
		
	public:
		ReportData(CompareBehaviour<T>*);
		~ReportData();
		int getSize();
		void CLEAN();
		vector<ReportRow<T>>& getCollec();
		void add(T,string);
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c):comp(c){

}

template <class T>
int ReportData<T>::getSize(){
	return collec.size();
}

template <class T>
ReportData<T>::~ReportData(){
	delete comp;
}

template <class T>
void ReportData<T>::CLEAN(){
	collec.clear();
}


template <class T>
void ReportData<T>::add(T key, string row){
	
	typename vector<ReportRow<T>>::iterator itr;

	if(getSize()==0){
		itr=collec.insert(collec.begin(),ReportRow<T>(key,row));
	}
	else{
		for(itr=collec.begin();itr!=collec.end();itr++){

			if(comp->compare(itr->key,key)){
				break;
			}
			else{
				continue;
			}		
		}
		collec.insert(itr,ReportRow<T>(key,row));
	}
		
}

template <class T>
ostream& operator<<(ostream& out,const ReportData<T>& a){	
	for(int i=0;i<a.collec.size();i++){
		out<<"\t"<<a.collec[i].row;
	}
	return out;
}


/*
Report Data
-> class template
-> constructor assign the type of compareBehaviour -> ascending or descending
-> we have a getter function for size, a ofstream operator
-> we have a add function that iterates thru and adds the collection to the ReportData of Report Row
-> I have a CLEAN function because it helps with dealing the duplicating scenario when the output computes are run for more than one turn this function cleans the collection vector for ReportRow
-> ofstream operator that just displays all data of the ReportData 

Report Row (nested class template)
-> we have a key and a string row that we populate in the constructor from the variables that we pass on from the add function of the Report Data add function
*/








