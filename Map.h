#include <iostream>
using namespace std;
#include <cstdlib>

#include<vector>
#include"Record.h"

template <class T>
class Map{
	//is this needed? 
	//template <class V>
	private:
		vector<T> keys;
		vector<vector<Record*>> values;
	public:
		void add(T,Record*);
		int getKeySize();
		vector<T>& getKeys();
		vector<Record*>& operator[](T);
		//vector<Record*> operator=(const Record) 
};

template <class T>
void Map<T>::add(T key,Record* rec){
	if(keys.size()==0){
		keys.push_back(key);
		vector<Record*> newcollection;
		newcollection.push_back(rec);
		values.push_back(newcollection);
//		values.push_back(rec);
	}
	else{
		if(keys.size()==values.size()){
			bool a=true;
			
			//
			for(int i=0;i<keys.size();i++){
				if(keys[i]==key){
				//add to corresponding values key
					values[i].push_back(rec);
					a=false;
				}
			}
			//we have to create a new collection ? and then add that to the values collection
			if(a){
				keys.push_back(key);
				vector<Record*> newcollection;
				newcollection.push_back(rec);
				values.push_back(newcollection);
			}
		}
		else{
			cout<<"OVERLOAD "<<endl;
		}
		
	}
}

template <class T>
int Map<T>::getKeySize(){
	return keys.size();
}

template <class T>
vector<T>& Map<T>::getKeys(){
	return keys;
}

template <class T>
vector<Record*>& Map<T>::operator[](T a){
	try{
		for(int i=0;i<keys.size();i++){
			if(a==keys[i]){
				return values[i];
			}
		}
	}
	catch(const T s){
		cout<<"Error"<<s<<endl;
		
	}
}
//catch(const int* s){
	//	throw "it a integer";
	//}
	//catch(char s){
	//	cout<<"Handled STRING error "<<s<<endl;
		//return NULL;
	//}	
	//catch(int s){
	//	cout<<"Handled INT error"<<endl;
	//}
		//return NULL;










