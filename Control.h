#ifndef CONTROL_H
#define CONTROL_H

#include "ReportGenerator.h"
#include <vector>
#include "Report3.h"
#include "Report2.h"
#include "Report1.h"
class Control
{
	public:
		Control();
		~Control();
		void launch();
	private:
		Report1_PercentageOfFarmByReg* rep1;
		Report2_PercentageChange* rep2;
		Report3_maxHorseByReg* rep3;
		vector<ReportGenerator*> collections;
		
};

#endif

/*
this class is to use the view class and create a menu when the program is run
*/
