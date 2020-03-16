#ifndef _JSUPERCUB_DOT_H_
#define _JSUPERCUB_DOT_H_

//  Filename:		JsuperCub.h
//	Author:			John Carlson
//	Description:	This is my class to abstract supercubs it inherits from Jsprite...
//					It may end up as a place to hard code sprite attributes	
//
//	Changelog:		started 1-31-2003
//

#include "Jsprite.h"

class JsuperCub : public Jsprite
{
public:

	JsuperCub();

	void initPlane();

	void RotateElevatorUp();
	void RotateElevatorDown();
	void RotateAileronsLeft();
	void RotateAileronsRight();
	void IncreaseSpeed();
	void DecreaseSpeed();
	void RotateRudderLeft();
	void RotateRudderRight();

	void RotateFlapsDown();
	void RotateFlapsUp();


protected:
private:
	//Jsprite plane;
};

#endif



