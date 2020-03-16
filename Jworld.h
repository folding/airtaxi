#ifndef _JWORLD_DOT_H_
#define _JWORLD_DOT_H_

//  Filename:		Jworld.h
//	Author:			John Carlson
//	Description:	This is my world.  It contains the state of affairs and handles initialization.
//
//	Changelog:		started 2-1-2003
//

#include "JsuperCub.h"
#include "Jmap.h"
#include "Jmission.h"
#include "Jmenu.h"

class Jworld
{
public:
		Jworld();

		void initWorld();
        
		void updateWorldState();

		void processInput();

protected:

private:
		JsuperCub plane; //this is our plane sprite.
		JsuperCub otherplane;

		Jmap fMap;

		u32 fFrames;

		u8 fInRotation;

		Jmenu fMainMenu;
		Jmenu fPauseMenu;

		Jmission fMissionOne;

		u8 fWhereIWas;
		u8 fWhereIAm;

		u8 fMenuDecision;

		


};





#endif


