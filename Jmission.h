#ifndef _JMISSION_DOT_H_
#define _JMISSION_DOT_H_
//  Filename:		Jmission.h
//	Author:			John Carlson
//	Description:	This is a class to abstract different game missions
//
//	Changelog:		started 2-2-2003
//

#include "mygba.h"

class Jmission
{
public:
		Jmission();
		u32 GetTimeLimit();

protected:

private:

		u32 fTimeLimit;
		bool fGoalMet;
        
};

#endif //_JMISSION_DOT_H_


