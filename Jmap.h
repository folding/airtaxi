#ifndef _JMAP_DOT_H_
#define _JMAP_DOT_H_
//  Filename:		Jmap.h
//	Author:			John Carlson
//	Description:	This is a class to abstract map creation and maintenence
//
//	Changelog:		started 2-1-2003
//



//here is a map idea that I am not sure the hardware can handle...  There will 
//be a huge map in memory somewhere.  A 512x512 chunk will be sent to the
//viewable part of memory.  When the plane crosses some boundary another chunk
//will be copied into viewable memory that overlaps the screen area.  This
//could take advantage of the double buffering available in mode 4.  If there 
//is a delay during copying it could get annoying quickly.


//another possibility would be to make a collection of sprites that make up the
//background and then move them together (rotation would take some thought...


#include "mygba.h"

class Jmap
{
public:

	Jmap();

	void initMap();

	u8	getElevation(u16 x, u16 y);

	void RotateLeft();
	void RotateRight();
	void ZoomIn();
	void ZoomOut();

	u16 GetZoom();
	u16 GetRot();

protected:


private:

	//I need a variable to hold elevations
	// will probably be array from bmp

	u16 fMapX;
	u16 fMapY;

	u16 fMapRotation;	
	u16 fMapZoom;

};








#endif //_JMAP_DOT_H_



