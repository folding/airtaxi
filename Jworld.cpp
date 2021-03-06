//  Filename:		Jworld.cpp
//	Author:			John Carlson
//	Description:	This is the implementation of my world
//
//	Changelog:		started 2-1-2003
//

//graphics includes
#include "gfx/object.pal.c"//supercubs color palette
//#include "gfx/spr.pal.c"//background palette
#include "gfx/mapgrid.pal.c"//mode 4 background
//#include "gfx/maptest.pal.c"


#include "Jworld.h"

//possible game modes
#define INGAME 0
#define INMAINMENU 1
#define INPAUSEMENU 2

//possible menu decisions
#define NODECISION 200
#define EXITMENU 201
#define EXITTOMAINMENU 202

#define MENUOPTIONONE 0
#define MENUOPTIONTWO 1
#define MENUOPTIONTHREE 2
#define MENUOPTIONFOUR 3
#define MENUOPTIONFIVE 4


#define TEXT_MODE_OK


Jworld::Jworld()
{
	fWhereIAm = INGAME;
	fWhereIWas = INGAME;



}

void Jworld::initWorld()
{
	ham_Init();

	ham_SetBgMode(1);	//set background mode to one

	//this is the backgrounds palette 
	ham_LoadBGPal256((void*)&mapgrid_Palette);	

	//do this one for tile modes
	//ham_LoadBGPal256((void*)&spr_Palette);	

	#ifdef TEXT_MODE_OK
		ham_InitText(0);
	#endif

	//now load the supercubs color palette
	ham_LoadObjPal((void*)&object_Palette,256);



	fMap.initMap();


	//Display the background
	ham_InitBg(2,		//background number
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

	ham_CopyObjToOAM();
	
}

void Jworld::updateWorldState()
{
	if (fWhereIAm != fWhereIWas) {
		
		//we have changed modes
		//do init based on where I am

		//do I need to do clean up??? first.

		switch(fWhereIAm) {
		case INGAME:
			
			//set up game mode
			

			break;
		case INMAINMENU:
			
			//set up main menu
			fMainMenu.ViewMenu();

			break;
		case INPAUSEMENU:

			//set up pause menu
			fPauseMenu.ViewMenu();

			break;
		//default:
		}//end switch whereIam


	}//end of update if mode changed
	

	//do whatever we can where we are.
	
	switch(fWhereIAm) {
	case INGAME:
		
		//check for a keypress
		//if(!(fFrames%3))
		processInput();

		// only update animation every 5th frame, 
		// and only if the plane is "in rotation"
		if(!(fFrames%5)&& fInRotation)
		{
			//change the planes texture if necessary
			plane.changeTexture();		
			otherplane.changeTexture();
			fInRotation = 0;
		}

		if(!(fFrames%5))
			plane.updateLocation();

		//check time limit
		if(fFrames == fMissionOne.GetTimeLimit())
		{
		#ifdef TEXT_MODE_OK
			ham_DrawText(1,18,"GAME OVER YOU LOSE ");
		#endif
			
		}

		//update plane position

		//update map business
		//maybe put this into map class...
		ham_RotBg(2,							//background number
				  fMap.GetRot(),				//angle
				  120,//plane.getXLoc(),				//x center of rotation		//xloc yloc are upper left corner of sprite.... should find center of plane instead....
				  80,//plane.getYLoc(),				//y center of rotation
				  0x100+(SIN_SFP32[fMap.GetZoom()])	//zoom factor
				  );

		//check collision
        



		//update sprite junk...
        ham_CopyObjToOAM();

		break;

	case INMAINMENU:

		fMenuDecision = fMainMenu.ProcessInput();

		if (fMenuDecision == NODECISION)
		{}	//do nothing, remain in menu
		else if(fMenuDecision == MENUOPTIONONE)//enter game
			fWhereIAm = INGAME;
		else if(fMenuDecision == MENUOPTIONTWO)//free fly
		{}
		else if(fMenuDecision == MENUOPTIONTHREE)//resupply
		{}
		else if(fMenuDecision == MENUOPTIONFOUR)//flight seeing
		{}
		else if(fMenuDecision == MENUOPTIONFIVE)
		{}

		break;

	case INPAUSEMENU:

		fMenuDecision = fPauseMenu.ProcessInput();

		if (fMenuDecision == NODECISION)
		{}	//do nothing, remain in menu
		else if(fMenuDecision == MENUOPTIONONE)//return to game
			fWhereIAm = INGAME;
		else if(fMenuDecision == MENUOPTIONTWO)//exit to mainmenu
			fWhereIAm = INMAINMENU;
		else if(fMenuDecision == MENUOPTIONTHREE)//restart mission...
		{}
		else if(fMenuDecision == MENUOPTIONFOUR)
		{}
		else if(fMenuDecision == MENUOPTIONFIVE)
		{}
	
		break;

	//default:
	}//end switch current mode update
		
	//increment frame count
	fFrames++;

}//end updateworldstate

void Jworld::processInput()
{
	//all references to axis assume positive z comes directly out of the screen,
	// positive x extends to the right and positive y extend up the screen

	if (F_CTRLINPUT_UP_ONLY_PRESSED){
		//rotate plane around x axis
		//rotate elevators down
		// make the plane dive
		plane.RotateElevatorDown();
		fMap.ZoomIn();
	}
	else if (F_CTRLINPUT_DOWN_ONLY_PRESSED) {
		//rotate plane around x axis
		//rotate elevators up
		// make the plane climb
		plane.RotateElevatorUp();
		fMap.ZoomOut();
	}
	else if (F_CTRLINPUT_LEFT_ONLY_PRESSED) {
		//rotate the plane around the z axis
		//rotate the rudder left
		// make the plane turn left
		plane.RotateRudderLeft();
		fMap.RotateLeft();

	}
	else if (F_CTRLINPUT_RIGHT_ONLY_PRESSED) {
		//rotate the plane around the z axis
		//rotate the rudder right
		// make the plane turn right
		plane.RotateRudderRight();		
		fMap.RotateRight();
	}
	else if (F_CTRLINPUT_A_ONLY_PRESSED) {
		// varies with mission
		// example: drop supplies
		#ifdef TEXT_MODE_OK
			ham_DrawText(1,18,"a only       ");		
		#endif

			otherplane.enableVisibility();

	}
	else if (F_CTRLINPUT_B_ONLY_PRESSED) {
		// nothing...
		#ifdef TEXT_MODE_OK
			ham_DrawText(1,18,"b only       ");
		#endif

			otherplane.disableVisibility();
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
	else if (F_CTRLINPUT_UP_AND_B_PRESSED) {
		//increase plane speed		
		plane.IncreaseSpeed();
	}
	else if (F_CTRLINPUT_DOWN_AND_B_PRESSED) {
		//decrease plane speed        
		plane.DecreaseSpeed();
	}
	else if (F_CTRLINPUT_START_ONLY_PRESSED) {

		fWhereIAm = INPAUSEMENU;

	}
}
