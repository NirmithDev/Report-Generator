#ifndef RECORD_H
#define RECORD_H


class Record
{
	friend ostream& operator<<(ostream&,Record&);
	public:
		Record(int,string,int);
		int getYear();
		string getRegion() const;
	private:
		int year;
		string region;
		int numAnimals;

};

#endif
