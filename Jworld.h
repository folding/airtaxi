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
		//these are the world bounds
		u16		xbound;
		u16		ybound;
	
		//this is our plane sprite.
		JsuperCub plane; 
				
		//this is other objects in the world
		JsuperCub otherplane;

        //this is the background
		Jmap fMap;

		//total number of frames thus far
		u32 fFrames;

		//is the plane been rotated
		u8 fInRotation;

		//the various menus
		Jmenu fMainMenu;
		Jmenu fPauseMenu;

		//the missions
		Jmission fMissionOne;

		//variables to track transition from menu to game
		u8 fWhereIWas;
		u8 fWhereIAm;

		u8 fMenuDecision;

		


};





#endif


