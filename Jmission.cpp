//  Filename:		Jmission.cpp
//	Author:			John Carlson
//	Description:	This is implementation of Jmission
//
//	Changelog:		started 2-2-2003
//

#include "Jmission.h"

Jmission::Jmission()
{
	fTimeLimit = 1000; //some frame count
	fGoalMet = false;
}

u32 Jmission::GetTimeLimit()
{
	return fTimeLimit;
}

