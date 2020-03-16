//  Filename:		main.cpp
//	Author:			John Carlson
//	Description:	This file started as the cpptest example from the ham samples folder
//					it then was morphed through the aaronroger.com tutorials and other 
//					code from the ham samples folder.  When finished it will be the driver
//					for my gba version of "air taxi"...
//	
//	Changelog:		This is the history of the project. Daily and version changes
//
//					started 1-30-2003
//
//					At this point the sprite handling has been transfered to the Jsprite class
//					it is still however mostly hard coded :( so it currently won't do more than
//					one sprite.  Also made a pile of macros to define and implement basic attributes
//
//					changes 1-31-2003
//
//					ver.0.3
//					Jsprite.initSprite() now takes a ptr to the array representing the bmp
//
//					ver.0.4
//					Can now make different sprites based.  I ditched the idea of having one big
//					static array of 128 sprites in the sprite class because the compiler balked
//					at it.  So each instance has a u8 that corresponds with its sprite data.
//					initSprite now also takes a screen x&y position
//
//					ver.0.5
//					Added a few input functions to mygba.h to check for specific key combos and 
//					others that check for only a single button being pushed.  Also mucked with the
//					background mode to allow text display.  The background, previously bitmap, is
//					now white with dots...?
//
//					ver.0.6
//					Added macros for defining and implementing booleans in Jsprite class.
//					created JsuperCub class to deal with plane specific issues...  Got rid of 
//					silly macro warnings for trying to paste a . on the end of an value.  Cut key
//					query back to every five frames instead of every frame.
//
//					ver.0.7
//					hard coded supercub values into the JsuperCub class for simple set up of the cub
//					extended the Jsprite.initSprite to take all possible parameters for sprite creation
//					and other values I crammed into the Jsprite class
//
//					changes 2-1-2003
//
//					ver.0.8
//					hmmm... I made a class called Jworld.  This now houses everything that was in
//					this file.  Maybe a waste of time but I can't say for sure yet.
//


#include "Jworld.h"

void vblFunc();

//do you like my global variable?
Jworld myWorld;


//MULTIBOOT //I don't think this rom will need to be multibootable...

int main(void)
{
    // initialize world
	myWorld.initWorld();

	//start the Vertical BLank interrupt handler
	ham_StartIntHandler(INT_TYPE_VBL,(void*)&vblFunc);		//calls vblFunc ~60 times per sec

	//infinite loop so program doesn't end
    while(1)
    {}    

}//end main

void vblFunc()
{
	myWorld.updateWorldState();
}



