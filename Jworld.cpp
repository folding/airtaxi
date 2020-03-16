//  Filename:		Jworld.cpp
//	Author:			John Carlson
//	Description:	This is the implementation of my world
//
//	Changelog:		started 2-1-2003
//

//graphics includes
#include "gfx/object.pal.c"//supercubs color palette
#include "gfx/spr.pal.c"
#include "gfx/sprite.raw.c"
#include "gfx/sprite.map.c"

#include "Jworld.h"


void Jworld::initWorld()
{
	ham_Init();

	map_fragment_info_ptr  bg_pic; //map pointer

	ham_SetBgMode(0);	//set background mode to one

	//this is the backgrounds palette 
	ham_LoadBGPal256((void*)&spr_Palette);	

	ham_InitText(0);

	//now load the supercubs color palette
	ham_LoadObjPal((void*)&object_Palette,256);

	ham_bg[1].ti = ham_InitTileSet((void*)&sprite_Tiles,		//ptr to source
									SIZEOF_16BIT(sprite_Tiles),	//number of 16bit chunks
									1,							//color/palette mode
									1);							//offset or not...

	ham_bg[1].mi = ham_InitMapEmptySet(3,				//map size				
										0);				//rotatable (0 = no)

	bg_pic = ham_InitMapFragment((void*)&sprite_Map,	//ptr to source
									30,					//map x size
									20,					//map y size
									0,					//x offset
									0,					//y offset
									1,					//num tiles in x direct
									1,					//num tiles in y direct
									0);					//rotatable (0 = no)

	ham_InsertMapFragment(bg_pic,		//map fragment ptr
							0,			//background number
							0,			//x tilenumber to place frag
							0);			//y tilenumber..


	//Display the background
	ham_InitBg(1,		//background number
				1,		//turn bg on/off (1 = on)
				0,		//set priority (0-high,3-low)
				0);		//turn mosaic on/off

	//initialize our supercub sprites
	plane.initPlane();

	otherplane.initPlane();
	otherplane.setXLoc(10);
	otherplane.setYLoc(10);
	otherplane.updateLocation();
	plane.changeTexture();
	otherplane.changeTexture();

	
}

void Jworld::updateWorldState()
{
	// only update animation every 5th frame, 
	// and only if the plane is "in rotation"
	if(!(fFrames%5)&& fInRotation)
	{
		//change the planes texture if necessary
		plane.changeTexture();		
		otherplane.changeTexture();
		fInRotation = 0;
	}	

	//check for a keypress
	//if(!(fFrames%3))
		captureInput();


	//increment frame count
	fFrames++;

}

void Jworld::captureInput()
{
	//all references to axis assume positive z comes directly out of the screen,
	// positive x extends to the right and positive y extend up the screen

	if (F_CTRLINPUT_UP_ONLY_PRESSED){
		//rotate plane around x axis
		//rotate elevators down
		// make the plane dive
		plane.RotateElevatorDown();
	}
	else if (F_CTRLINPUT_DOWN_ONLY_PRESSED) {
		//rotate plane around x axis
		//rotate elevators up
		// make the plane climb
		plane.RotateElevatorUp();
	}
	else if (F_CTRLINPUT_LEFT_ONLY_PRESSED) {
		//rotate the plane around the z axis
		//rotate the rudder left
		// make the plane turn left
		plane.RotateRudderLeft();		

	}
	else if (F_CTRLINPUT_RIGHT_ONLY_PRESSED) {
		//rotate the plane around the z axis
		//rotate the rudder right
		// make the plane turn right
		plane.RotateRudderRight();		
	}
	else if (F_CTRLINPUT_A_ONLY_PRESSED) {
		// varies with mission
		// example: drop supplies
		ham_DrawText(1,18,"a only       ");		

	}
	else if (F_CTRLINPUT_B_ONLY_PRESSED) {
		// nothing...
		ham_DrawText(1,18,"b only       ");
	}
	else if (F_CTRLINPUT_R_ONLY_PRESSED) {
		//rotate the plane around the y axis
		//rotate the ailerons
		// make the plane roll right
		plane.RotateAileronsRight();
		otherplane.RotateAileronsRight();
		fInRotation = 1;

	}
	else if (F_CTRLINPUT_L_ONLY_PRESSED) {
		//rotate the plane around the y axis
		//rotate the ailerons
		// make the plane roll left
		plane.RotateAileronsLeft();
		otherplane.RotateAileronsLeft();
		fInRotation = 1;
	}
	else if (F_CTRLINPUT_B_AND_UP_PRESSED) {
		//increase plane speed		
		plane.IncreaseSpeed();
	}
	else if (F_CTRLINPUT_B_AND_DOWN_PRESSED) {
		//decrease plane speed        
		plane.DecreaseSpeed();
	}
}
