#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include<vector>
#include "Record.h"
#include "Map.h"
#include "ReportData.h"
#include "DescBehaviour.h"

class ReportGenerator{

	private:
		static vector<Record*> census;
	
	protected:
		static Map<int> yearMap;
		static Map<string> regionMap;
		static Map<string> animalTypeMap;

	public:
		//the function to populate the maps and census collection
		static void populate();
		virtual void compute()=0;
		//cleanup function for later on to clean up the census collection
		void cleanUp();
};

#endif

/*
-> base class
-> we have a vector of record* called census this will contain all the data read in from the file
-> we will have 3 respective maps called yearMap, regionMap and animalTypeMap with the corresponding data types
-> we have a function called populate which reads the data from the farms.dat file and accordingly populates all the map and the census collection  
*/
