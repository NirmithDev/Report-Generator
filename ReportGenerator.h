#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include<vector>
#include "Record.h"
#include "Map.h"

class ReportGenerator{

	private:
		static vector<Record*> census;
		static Map<int> yearMap;
		static Map<string> regionMap;
		static Map<string> animalTypeMap;
	public:
		//not specified but it is here anyway
		ReportGenerator();
		//the function to populate the maps and census collection
		static void populate();
		//virtual void compute()=0;
		//cleanup function for later on to clean up the census collection
		void cleanUp();
};

#endif
