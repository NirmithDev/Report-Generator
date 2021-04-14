#ifndef RECORD_H
#define RECORD_H


class Record
{
	friend ostream& operator<<(ostream&,Record&);
	public:
		Record(int,string,int,int,string,string);
		int getYear();
		int getnumAnimals();
		int getnumFarms();
		~Record();
		string getRegion();
		string getanimalType();
		string getsubRegion();
	private:
		int year;
		string region,subRegion,animalType;
		int numAnimals,numFarms;

};

#endif

/*
In the record class we will need to store the year, region, subRegion, animalType, numAnimals and numFarms
that we can access by creating a bunch of getters that may or may not be necessary but are there for safety reasons
We have a constuctor that inits these values and a destructor that deallocates them as well
*/
