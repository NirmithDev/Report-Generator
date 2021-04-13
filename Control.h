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
		Report1* rep1;
		Report2* rep2;
		Report3* rep3;
		vector<ReportGenerator*> collections;
		
};

#endif

