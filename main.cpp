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
//					initSprite now also takes a screen xy position
//
//					ver.0.5
//					Added a few input functions to mygba.h to check for specific key combos and 
//					others that check for only a single button being pushed.  
					//onlys
//					#define F_CTRLINPUT_A_ONLY_PRESSED			R_CTRLINPUT == 0x03FE	//1022
//					#define F_CTRLINPUT_B_ONLY_PRESSED			R_CTRLINPUT == 0x03FD	//1021
//					#define F_CTRLINPUT_SELECT_ONLY_PRESSED		R_CTRLINPUT == 0x03FB	//1019
//					#define F_CTRLINPUT_START_ONLY_PRESSED		R_CTRLINPUT == 0x03F7	//1015
//					#define F_CTRLINPUT_RIGHT_ONLY_PRESSED		R_CTRLINPUT == 0x03EF	//1007
//					#define F_CTRLINPUT_LEFT_ONLY_PRESSED		R_CTRLINPUT == 0x03DF	// 991
//					#define F_CTRLINPUT_UP_ONLY_PRESSED			R_CTRLINPUT == 0x03BF	// 959
//					#define F_CTRLINPUT_DOWN_ONLY_PRESSED		R_CTRLINPUT == 0x037F	// 895
//					#define F_CTRLINPUT_R_ONLY_PRESSED			R_CTRLINPUT == 0x02FF	// 767
//					#define F_CTRLINPUT_L_ONLY_PRESSED			R_CTRLINPUT == 0x01FF	// 511

					//combos
//					#define F_CTRLINPUT_UP_AND_B_PRESSED		R_CTRLINPUT == 0x03BD	//957
//					#define F_CTRLINPUT_DOWN_AND_B_PRESSED		R_CTRLINPUT == 0x037D	//893

					//diagonals
//					#define F_CTRLINPUT_UP_RIGHT_PRESSED		R_CTRLINPUT == 0x03AF	//943
//					#define F_CTRLINPUT_UP_LEFT_PRESSED			R_CTRLINPUT == 0x039F	//927
//					#define F_CTRLINPUT_DOWN_RIGHT_PRESSED		R_CTRLINPUT == 0x036F	//879
//					#define F_CTRLINPUT_DOWN_LEFT_PRESSED		R_CTRLINPUT == 0x035F	//863

//					Also mucked with the
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
//					this file.  Maybe a waste of time but I can't say for sure yet.  Also added a
//					map class to handle maps
//
//					changes 2-2-2003
//					
//					ver.1.0
//					I have decided to skip ver.0.9 and go directly to version 1.0 (don't really know why,
//					it just happened) I added a menu class and a mission class.  I restructured 
//					jworld.updateworldstate() to handle	three modes (in game, pause and main menu) 
//					For now missions and menus are not used but are integrated into the project.
//
//					changes 2-3-2003
//
//					ver.1.1
//					I converted to background mode 4 and hooked up the background rotation and scaling
//					in process added variables to the map class and accesser functions.  that is all.
//
//					changes 2-4-2003
//
//					ver.1.2
//					attempted to do a big background but it appears the maxsize allowable in mode 4 is
//					240x160... that won't work well for what I had intended to implement.  I have now
//					attempted to rotate sprites just to see how ham does this. it hasn't worked yet.
//
//					ver.1.3
//					hmm, just found that tile mode 1 and 2 are actually rotatable.  So I am in the
//					process of converting back to mode 1 (ha ha ha)...  Alright, it now rotates a background
//					in mode one.  I still don't have complete understanding of graphics but it looks
//					like my original implementation idea still is possible.
//
//					changes 2-6-2003
//					
//					ver.1.4
//					NOTHING WORKS AHAHAHHHHHAHHHAHH!!!!((!*#&*&#&@#(*?????.  Wow this is quite frustrating.
//					The graphics converter doesn't appear to be doing its job and now the complier is
//					taking like 6 or 8 minutes to do its job instead of the usual 1 or 2???!?!?  I tried to
//					reinstall ham and managed to scrap about ten lines of code for an h file.  I must 
//					walk away for a bit or I will explode...	
//
//					changes 2-9-2003
//
//					ver.1.5
//					I will start this versions comments with some general ramblings.  I don't know if I put
//					this down anywhere but I came up with the idea of making a quilt of sprites to represent
//					the map but this is problematic if it was to rotate the quilt.  So this sprite idea
//					led to another where instead of a tile map you have a solid background and then just create
//					random sprites to represent bushes and such that move by under your plane recycling them
//					as they go offscreen.  Because of my trials in the last version I think I will try
//					to do this new idea.  ...  I have added rotation to the sprite and supercub classes.  This
//					was just a way of hiding the library calls.  
//
//
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



