#ifndef _JMAP_DOT_H_
#define _JMAP_DOT_H_
//  Filename:		Jmap.h
//	Author:			John Carlson
//	Description:	This is a class to abstract map creation and maintenence
//
//	Changelog:		started 2-1-2003
//

#include "mygba.h"

class Jmap
{
public:

	void initMap();

	u8	getElevation(u16 x, u16 y);

protected:


private:

	//I need a variable to hold elevations
	// will probably be array from bmp

	u16 fMapX;
	u16 fMapY;

};








#endif //_JMAP_DOT_H_



