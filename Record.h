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
		
		string getRegion();
		string getanimalType();
		string getsubRegion();
	private:
		int year;
		string region,subRegion,animalType;
		int numAnimals,numFarms;

};

#endif
