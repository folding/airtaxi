#ifndef _JWORLD_DOT_H_
#define _JWORLD_DOT_H_

//  Filename:		Jworld.h
//	Author:			John Carlson
//	Description:	This is my world.  It contains the state of affairs and handles initialization.
//
//	Changelog:		started 2-1-2003
//

#include "JsuperCub.h"

class Jworld
{
public:
		void initWorld();
        
		void updateWorldState();

		void captureInput();

protected:

private:
		JsuperCub plane; //this is our plane sprite.
		JsuperCub otherplane;

		u32 fFrames;

		u8 fInRotation;

};





#endif


